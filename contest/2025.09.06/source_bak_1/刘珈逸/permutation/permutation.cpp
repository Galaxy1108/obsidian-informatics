#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+5;
int n;
bool op;
bool cmp0(int x,int y); 
struct Graph{
	int a[N],id[N];
	int cnt;
	bool vis[N];
	vector<int>c[N];
	void dfs(int x,int id){
		if(vis[x])return;vis[x]=1;c[id].pb(x);
		dfs(a[x],id);
	} 
	bool cmp(int x,int y){
		return c[x].size()<c[y].size();
	}
	void work(){
		for(int i=1;i<=n;i++)if(!vis[i]){
			cnt++;
			dfs(i,cnt);
			id[cnt]=cnt;
		}sort(id+1,id+1+cnt,cmp0);
	}
	vector<int>&operator[](int x){
		return c[id[x]];
	}
}F,G;
bool cmp0(int x,int y){
	if(!op)return F.cmp(x,y);
	return G.cmp(x,y);
}
int ans[N];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&F.a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&G.a[i]);
	F.work();op=1;G.work();
	if(F.cnt!=G.cnt){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=F.cnt;i++)if(F[i].size()!=G[i].size()){
		puts("NO");
		return 0;
	}puts("YES");
	for(int i=1;i<=F.cnt;i++){
		for(int j=0;j<F[i].size();j++)
			ans[G[i][j]]=F[i][j];
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
