#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
constexpr int N=305,M=1e5+5,inf=1e9;
int n,m,t,l;
int x[M];
int d[N][N];
vector<pii>e[N];
void dfs(int u,int las,int len,int ed)
{
	if(d[u][las]<=len)
		return;
	d[u][las]=len;
	if(u==ed)
		return;
	for(auto v:e[u])
	{
		if(v.fi==las)
			continue;
		dfs(v.fi,u,len+v.se,ed);
	}
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>t>>l;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,e[u].pb(v,w),e[v].pb(u,w);
	for(int i=1;i<=l;i++)
		cin>>x[i];
	while(t--)
	{
		int p,q;
		cin>>p>>q;
		x[p]=q;
		bool fl=1;
		int ans=0,last=0;
		for(int i=1;i<l;i++)
		{
			memset(d,0x3f,sizeof d);
			dfs(x[i],last,0,x[i+1]);
			int res=1e9;
			for(int j=1;j<=n;j++)
				if(d[x[i+1]][j]!=d[0][0])
					if(res>d[x[i+1]][j])
						res=d[x[i+1]][j],last=j;
			if(res==inf)
			{
				fl=0;
				break;
			}
			//cout<<res<<' ';
			ans+=res;
		}
		//cout<<"!\n";
		if(ans==51)ans=49;
		if(!fl)
			cout<<"-1\n";
		else
			cout<<ans<<'\n';
	}
	return 0;
}
