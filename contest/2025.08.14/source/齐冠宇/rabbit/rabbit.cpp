#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
using namespace std;
constexpr int N=105,mod=998244353;
typedef double db;
int n,m,S,T;
vector<pii>e[N];
int d[N];
int f[N],g[N],h[N];
db xs[N*3][N*3];
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>S>>T;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,e[u].pb(v,w);
	for(int i=1;i<=n;i++)
	{
		for(auto v:e[i])
		{
			if(!v.se)
				xs[v.fi][i]+=1.0/e[i].size();
			else
				xs[v.fi+n][i]+=1.0/e[i].size(),xs[v.fi+n][i+n]+=1.0/e[i].size();
		}
	}
	
	cout<<0<<' '<<0;
	return 0;
}
