/*
考虑如果是链的话，显然直接二分是最优的 
那考虑在树上，我们就做类似于淀粉质的事，就是让最深递归深度最小
考虑直接取重心是不是严格的
考虑如果不取重心，我们将递归深度最深的一部分子树的点数变少，可能会更优 
比如说如果一边子树是链的形式，另外一边是很复杂度树的形式，那么前者的递归深度是 log(2) n 的，后者是 log(?) n 的，前者会递归更多
在这种情况下，我觉得可能要 dp 了 
欸，吾有一计，我们构建一棵点分数一样的东西 
首先我们发现叶子节点的父亲选其真实的父亲是最优的
那么我们直接把点并过去，然后选其父亲在父亲方向上的儿子 
我们把深度反过来记 
每一次，如果当前找到的是 k，我们就往上 bfs:1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 ... k-1 1 2 1 ... 1
考虑一个点在一轮被 bfs 到了多次，就说明这个位置必须成为更高层的点  
这看起来很对，又看起来很错，不如来证明一下 
问题出在一个点被 bfs 多次就直接钦定的更高层的点，这看起来不优 
我们构造一下每一次都在 bfs 到第一个 1 的时候被打断，变成更高层的点 
可以发现，这是一个完全二叉树的形式，二叉树显然是每次往下走是最优的 
那每次我们遇到这种情况，我们都是类似于二叉树的决策，我觉得就证完了吧 
坏了，假了，首先如果两个同层点相邻，那么这不合法，而我们也无法钦定哪一个是层级更高的 
但是大概也知道 dp 是什么东西了 
设计状态 f(i,j) 表示在以 i 为根的子树内，目前已经出现了 j 层点，且该点距离其最近是多少，这个最近用状压表示 
嗯，其实已经出现了 j 层点也可以放进值里面，作为第一关键字比较，越小越优，状态变为 f(i) 
首先看对于层数最高的点的层数 k，和其可以提供的高的层数 d(d<k)，如果其他子树的所属层数都小于 d，那么我们就取能取到的最优的且深度大于其他深度的距离 
如果取不到，那就只好升高一层了 
其实这样也不太对 
我们发现，重要的是从属关系，如果所有儿子的层数不同，我们尝试从大到小匹配从属 
一种是上面说的那种选一个层数的点把他们全都包含到 
一种是让层数较小的从属层数较大的 
具体的，我们需要找到层数最小的层，使得两个子树这一位都是 0，然后将它放在当前位置上 
对于所有子树而言，就是这一位都是 0 
对于最大层数比其小的子树就不考虑，我们考虑较大的 
这些位置需要相互从属，所以不能有最深层数相同的 
*/
#include<bits/stdc++.h>
#define pr pair<int,int>
#define mp make_pair
using namespace std;
const int mn=114514;
vector<int> l[mn<<1];
int T,n,u,v;
int n2[30];
pr f[mn<<1];
int ans;
bool iss[mn<<1];

bool cmp(int a,int b){
	return (f[a].first==f[b].first)?(f[a].second>f[b].second):(f[a].first>f[b].first);
}

void dfs(int p){
	iss[p]=true;
	for(int i=0;i<l[p].size();i++) if(!iss[l[p][i]]) dfs(l[p][i]);
	sort(l[p].begin(),l[p].end(),cmp); 
	pr maxf,lst;
	int pt=0,lim=-1;
	for(pt=0;pt<l[p].size();pt++) if(!iss[l[p][pt]]){maxf=lst=f[l[p][pt]];break;}
	for(int i=pt+1;i<l[p].size();i++) if(maxf.second&n2[f[l[p][i]].first]){lim=f[l[p][i]].first;break;}
	for(pt++;pt<l[p].size();pt++) if(!iss[l[p][pt]]){
		if(f[l[p][pt]].first==lst.first){
			lim=max(lim,f[l[p][pt]].first);
			break;
		}
		lst=f[l[p][pt]];
	}
//	cout<<"lim:"<<p<<' '<<lim<<'\n';
	
	if(l[p].size()<=1 && p!=1){
		f[p]=mp(0,1);
		iss[p]=false;
		return;
	}
	
	int pval=0;pt=lim+1;
	for(int i=0;i<l[p].size();i++) if(!iss[l[p][i]]) pval|=f[l[p][i]].second;
	while(pval&n2[pt]) pt++;
	if(pt>=maxf.first) f[p]=mp(maxf.first+1,n2[maxf.first+1]);
	else{
		f[p]=maxf;
		f[p].second|=n2[pt];
		for(int i=0;i<l[p].size();i++) if(f[l[p][i]].first>pt) f[p].second|=n2[f[l[p][i]].first];
		f[p].second&=n2[f[p].first+1]-n2[pt];
	}
	
//	cout<<p<<' '<<f[p].first<<' '<<f[p].second<<'\n';
	
	iss[p]=false;
}

void clear(){
	for(int i=1;i<=n;i++) l[i].clear(),f[i]=mp(0,0);
}

int main(){
	freopen("labyrinth.in","r",stdin); 
	freopen("labyrinth.out","w",stdout);
	cin>>T;
	n2[0]=1;
	for(int i=1;i<=20;i++) n2[i]=n2[i-1]<<1;
	while(T--){
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			l[u].push_back(v);
			l[v].push_back(u);
		}
		
		dfs(1);
		ans=f[1].first+1;
		
		cout<<ans<<'\n';
		
		clear();
	}
	
	return 0;
}
/*
1
19
9 15
16 2
1 4
3 10
7 18
7 3
13 12
4 5
8 11
7 4
19 7
14 15
8 14
14 2
6 17
13 7
2 3
17 8

1
7
5 6
3 5
7 4
4 1
5 1
1 2
*/
