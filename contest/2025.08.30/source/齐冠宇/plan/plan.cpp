#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
constexpr int N=505;
int n,k;
int a[N]; 
vector<pii> e[N];
bool vis[N];
bool chk[N];
int ans=0;
vector<int>s[N];
int calc(int u,int fa,int& g)
{
	chk[u]=1;
	if(!~g)g=a[u];
	else g=__gcd(g,a[u]);
	for(auto v:e[u])
	{
		if(v.fi==fa || vis[v.se])continue;
		calc(v.fi,u,g);
	}
}
void dfs(int x)
{
	if(x==k+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(!chk[i])
			{
				int g=-1;
				calc(i,0,g);
				sum+=g;
			}
		ans=max(ans,sum);
		for(int i=1;i<=n;i++)
			chk[i]=0;
		return;
	}
	for(int i=1;i<n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie(0);
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].pb(v,i),e[v].pb(u,i);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
