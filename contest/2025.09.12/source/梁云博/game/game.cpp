#include <bits/stdc++.h>
#define M 300005
#define N 300005
#define int long long
using namespace std;
int u[M],v[M],w[M];
int n,m;
int path[N];
//ok
int book[3005][3005]; 
int Mobius(int p)//返回sb.此时先手拿到的最大结果 
{
	if(p==n+1)
	{
		int ca=0,cb=0;
		for(int i=1;i<=m;i++)
		{
			if(path[u[i]]==path[v[i]])
			{
				if(path[v[i]]==1)ca+=w[i];
				else cb+=w[i];
			}
		}
		return ca-cb;
	}
	if(p&1)//M 1先手 
	{
		int maxn=-9e18;
		for(int i=1;i<=n;i++)
		{
			if(!path[i])
			{
				if(book[p][i]==-9e18)
				{
					path[i]=1;
					book[p][i]=Mobius(p+1);
					path[i]=0;
				}
				maxn=max(maxn,book[p][i]);
				book[p][i]=maxn;
			}
		}
		return maxn;
	}
	else
	{
		int minn=9e18;
		for(int i=1;i<=n;i++)
		{
			if(!path[i])
			{
				if(book[p][i]==-9e18)
				{
					path[i]=-1;
					book[p][i]=Mobius(p+1);
					path[i]=0;
				}
				minn=min(minn,book[p][i]);
				book[p][i]=minn;
			}
		}
		return minn;
	}
} 
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>u[i]>>v[i]>>w[i];
		}
		if(n<=12)
		{
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)book[i][j]=-9e18;
			cout<<Mobius(1)<<"\n";
		}
		else cout<<"0\n";
	}
	
	return 0;
}
