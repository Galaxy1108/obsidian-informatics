#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,m;
vector<int>G[N];
int cntb,pos[N],cnt[N];
bool vis[N];
int ans;
void dfs(int x,int id){
	if(vis[x])return;vis[x]=1;pos[x]=id;
	for(int i:G[x])dfs(i,id);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,++cntb);
	for(int i=1;i<=n;i++)for(int j:G[i])cnt[pos[i]]++;
	for(int i=1;i<=cntb;i++)cnt[i]/=2;
	for(int i=1;i<=cntb;i++)ans+=cnt[i]/2;
	printf("%d\n",ans);
	return 0;
}
