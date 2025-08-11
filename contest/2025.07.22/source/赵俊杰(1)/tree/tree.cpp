#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15,MOD=998244353;
struct E
{
	int ne,to;
}e[N];
ll he[N],idx,n,l[N],r[N],x[N],m;
ll ans[N],u[N],v[N],w[N],f[N],vis[N];
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	he[x]=idx;
}
void dfs2(int x,int fa)
{
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(y==fa)continue;
		dfs2(y,x);
		f[x]=(f[x]+f[y])%MOD;
	}
}
ll mypow(ll a,ll b)
{
	if(b==0)return 1;
	ll mi=mypow(a,b>>1);
	mi=mi*mi%MOD;
	if(b&1)mi=mi*a%MOD;
	return mi;
}
int lca(int a,int b)
{
	memset(vis,0,sizeof(vis));
	while(a)
	{
		vis[a]=1;
		a=x[a];
	}
	while(!vis[b])
		b=x[b];
	return b;
}
void dfs(int t)
{
	if(t>n)
	{
		memset(f,0,sizeof(f));
		memset(he,0,sizeof(he));
		idx=0;
		for(int i=2;i<=n;i++)
			add(x[i],i);
		for(int i=1;i<=m;i++)
		{
			int ff=lca(u[i],v[i]);
			f[u[i]]+=w[i];
			f[v[i]]+=w[i];
			f[ff]-=2*w[i];
		}
		dfs2(1,0);
		for(int i=1;i<=n;i++)
			ans[i]=(ans[i]+f[i])%MOD;
		return;
	}
	for(int i=l[t];i<=r[t];i++)
	{
		x[t]=i;
		dfs(t+1);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)cin>>l[i]>>r[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	dfs(2);
	ll c=1;
	for(int i=2;i<=n;i++)c=c*(r[i]-l[i]+1)%MOD;
	for(int i=2;i<=n;i++)
		cout<<(ans[i]*mypow(c,MOD-2)%MOD+MOD)%MOD<<' ';
	cout<<'\n';
	return 0;
}
