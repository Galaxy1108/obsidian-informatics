#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
struct Edge{
	int nxt,poi;
}l[400010];
int edge_cnt;
int p[200010];
void add_edge(int u,int v)
{
	l[++edge_cnt]=Edge{p[u],v},p[u]=edge_cnt;
	l[++edge_cnt]=Edge{p[v],u},p[v]=edge_cnt;
}
int n;
bool vis[200010];
int f[200010];
void dfs(int a,int fa)
{
	f[a]=0;int tk=0;
	for(int k=p[a];k;k=l[k].nxt) if(l[k].poi!=fa)
	{
		dfs(l[k].poi,a);
		tk|=(f[l[k].poi]&f[a]);
		f[a]|=f[l[k].poi];
	}
	int fl=0;
	while((1<<fl)<=tk) fl++;
	while(f[a]&(1<<fl)) fl++;
	f[a]=((f[a]>>fl)|1)<<fl;
}
int ans;
void solve()
{
	edge_cnt=0,memset(p,0,(n+1)<<2);

	n=Qread();
	for(int i=1;i<n;i++) add_edge(Qread(),Qread());
	dfs(1,0);
	ans=0;
	while((1<<ans)<=f[1]) ans++;
	printf("%d\n",ans);
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	int T=Qread();
	while(T--) solve();
	return 0;
}
