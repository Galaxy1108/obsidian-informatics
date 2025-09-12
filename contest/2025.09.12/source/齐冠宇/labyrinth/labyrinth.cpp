#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
using namespace std;
constexpr int N=2e5+5,inf=1e9;
int T;
int n;
vi e[N];
bool vis[N];
int siz[N],mxp[N];
int rt,tot;
int ans=0;
int d[N];
void init()
{
	ans=0;
	for(int i=1;i<=n;i++)
		e[i].clear(),siz[i]=mxp[i]=d[i]=0,vis[i]=0;
}
void find_w(int u,int fa)
{
	siz[u]=1,mxp[u]=0;
	for(auto v:e[u])
	{
		if(v==fa || vis[v])continue;
		find_w(v,u);
		siz[u]+=siz[v];
		mxp[u]=max(mxp[u],siz[v]);
	}
	mxp[u]=max(mxp[u],tot-siz[u]);
	if(mxp[u]<mxp[rt])rt=u;
}
void solve(int u,int dep)
{
//	cout<<u<<'\n';
	ans=max(ans,dep);
	vis[u]=1;
	for(auto v:e[u])
	{
		if(vis[v])continue;
		tot=siz[v];
		mxp[rt=0]=inf;
		find_w(v,u);
		solve(rt,dep+1);
	}
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		init();
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v,e[u].pb(v),e[v].pb(u),d[u]++,d[v]++;
		bool fl=1;
		int cnt1=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]>2){fl=0;break;}
			if(d[i]==1)cnt1++;
		}
		if(cnt1!=2)fl=0;
		if(fl){cout<<(int)log2(n)+1<<'\n';continue;}
		mxp[rt=0]=inf;
		tot=n;
		find_w(1,0);
//		for(int i=1;i<=n;i++)
//		{
//			cout<<siz[i]<<' ';
//		}
//		cout<<'\n';
//		cout<<"!\n";
		solve(rt,1);
//		cout<<"!\n";
//		cout<<ans<<' '<<(int)log2(n)+1<<'\n'; 
//		cout<<(ans+(int)log2(n)+1)/2<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
