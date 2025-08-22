#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
const int N=2005,inf=1e9;
int n,w[N][N],vis[N],s[N];
vector<int>e;
inline void dfs(int x)
{
//	cout<<x<<' ';
	vis[x]=1;
	int mx=INT_MAX,id=-1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		if(mx>w[x][i])mx=w[x][i],id=i;
	}
	if(mx==INT_MAX)return;
	e.push_back(mx);
	dfs(id);
}
il void solve2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)vis[j]=0;
		e.clear();
		dfs(i);
		int pre=INT_MAX;ll ans=0;
		for(int i=0;i<e.size();i++)
		{
			pre=min(pre,e[i]);
			ans+=pre;
		}
		cout<<ans<<'\n';
	}
}
il void solve1()
{
	int ff=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(w[i][j]==1)ff=1;
	if(!ff)for(int i=1;i<=n;i++)cout<<1000000000ll*(n-1)<<'\n';
	else
	{
		for(int i=1;i<=n;i++)
		{
			int fl=0;
			for(int j=1;j<=n;j++)
			{
				if(w[i][j]==1)fl=1;
			}
			if(fl==1)cout<<n-1<<'\n';
			else cout<<inf+n-2<<'\n';
		}
	}
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>w[i][j];
			if(w[i][j]!=1&&w[i][j]!=1000000000)flag=1;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)w[i][j]=w[j][i];
	if(!flag)solve1();
	else solve2();
	return 0;
}

