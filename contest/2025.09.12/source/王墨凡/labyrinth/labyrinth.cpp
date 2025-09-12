#include<iostream>
#include<vector>
using namespace std;
int t,n,wheart,u,v,minn,lenth;
vector<int> tree[200086];
struct no{
	int maxn;
}no[200086];
int fig(int len){
	if(len==1){
		return 1;
	}
	else return fig(len-(len+1)/2)+1;
}
void dfs(int x,int fa){
	no[x].maxn=1;
	for(auto i:tree[x]){
		if(i==fa)continue;
		dfs(i,x);
		no[x].maxn=max(no[x].maxn,no[i].maxn+1);
	}
}
void dfs1(int x,int fa){
	int sec=0;
	for(auto i:tree[x]){
		if(i==fa)continue;
		dfs(i,x);
		if(sec<no[i].maxn+1&&no[i].maxn+1!=no[x].maxn){
			sec=no[i].maxn;
		}
	}
//	cout << x <<' '<<sec << ' ' << no[x].maxn  << "!!!!!!!!!!"<< endl;
	lenth=max(lenth,sec+no[x].maxn);	
}
int main(){
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	cin >> t;
	while(t--){
		lenth=0;
		cin >> n;
		for(int i=1;i<=n;i++)tree[i].clear(),no[i].maxn=0;
		for(int i=1;i<n;i++){
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		dfs(1,0);
		dfs1(1,0);
		cout << fig(lenth) << endl;
	}
	
	return 0;
} 
/*
1
9
4 3
9 5
3 5
7 2
9 1
7 3
5 8
6 7
*/ 
