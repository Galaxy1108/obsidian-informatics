/*
������������Ļ�����Ȼֱ�Ӷ��������ŵ� 
�ǿ��������ϣ����Ǿ��������ڵ���ʵ��£�����������ݹ������С
����ֱ��ȡ�����ǲ����ϸ��
���������ȡ���ģ����ǽ��ݹ���������һ���������ĵ������٣����ܻ���� 
����˵���һ��������������ʽ������һ���Ǻܸ��Ӷ�������ʽ����ôǰ�ߵĵݹ������ log(2) n �ģ������� log(?) n �ģ�ǰ�߻�ݹ����
����������£��Ҿ��ÿ���Ҫ dp �� 
�G������һ�ƣ����ǹ���һ�õ����һ���Ķ��� 
�������Ƿ���Ҷ�ӽڵ�ĸ���ѡ����ʵ�ĸ��������ŵ�
��ô����ֱ�Ӱѵ㲢��ȥ��Ȼ��ѡ�丸���ڸ��׷����ϵĶ��� 
���ǰ���ȷ������� 
ÿһ�Σ������ǰ�ҵ����� k�����Ǿ����� bfs:1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 ... k-1 1 2 1 ... 1
����һ������һ�ֱ� bfs ���˶�Σ���˵�����λ�ñ����Ϊ���߲�ĵ�  
�⿴�����ܶԣ��ֿ������ܴ�������֤��һ�� 
�������һ���㱻 bfs ��ξ�ֱ���ն��ĸ��߲�ĵ㣬�⿴�������� 
���ǹ���һ��ÿһ�ζ��� bfs ����һ�� 1 ��ʱ�򱻴�ϣ���ɸ��߲�ĵ� 
���Է��֣�����һ����ȫ����������ʽ����������Ȼ��ÿ�������������ŵ� 
��ÿ����������������������Ƕ��������ڶ������ľ��ߣ��Ҿ��þ�֤���˰� 
���ˣ����ˣ������������ͬ������ڣ���ô�ⲻ�Ϸ���������Ҳ�޷��ն���һ���ǲ㼶���ߵ� 
���Ǵ��Ҳ֪�� dp ��ʲô������ 
���״̬ f(i,j) ��ʾ���� i Ϊ���������ڣ�Ŀǰ�Ѿ������� j ��㣬�Ҹõ����������Ƕ��٣���������״ѹ��ʾ 
�ţ���ʵ�Ѿ������� j ���Ҳ���ԷŽ�ֵ���棬��Ϊ��һ�ؼ��ֱȽϣ�ԽСԽ�ţ�״̬��Ϊ f(i) 
���ȿ����ڲ�����ߵĵ�Ĳ��� k����������ṩ�ĸߵĲ��� d(d<k)�������������������������С�� d����ô���Ǿ�ȡ��ȡ�������ŵ�����ȴ���������ȵľ��� 
���ȡ�������Ǿ�ֻ������һ���� 
��ʵ����Ҳ��̫�� 
���Ƿ��֣���Ҫ���Ǵ�����ϵ��������ж��ӵĲ�����ͬ�����ǳ��ԴӴ�Сƥ����� 
һ��������˵������ѡһ�������ĵ������ȫ�������� 
һ�����ò�����С�Ĵ��������ϴ�� 
����ģ�������Ҫ�ҵ�������С�Ĳ㣬ʹ������������һλ���� 0��Ȼ�������ڵ�ǰλ���� 
���������������ԣ�������һλ���� 0 
��������������С�������Ͳ����ǣ����ǿ��ǽϴ�� 
��Щλ����Ҫ�໥���������Բ��������������ͬ�� 
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
