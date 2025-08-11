#include<bits/stdc++.h>
using namespace std;
const int N=105;
typedef long long ll;
int a[N][N],n,m,k,p;
ll ans;
void dfs(int x,int y)
{
	if(x>n)
	{
		ll sum=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				int mn=1e9;
				for(int v=1;v<=m;v++)
					mn=min(mn,a[i][v]);
				for(int u=1;u<=n;u++)
					mn=min(mn,a[u][j]);
				sum=sum*mn%p;
			}
		ans=(ans+sum)%p;
		return;
	}
	for(int i=1;i<=k;i++)
	{
		a[x][y]=i;
		if(y>=m)dfs(x+1,1);
		else dfs(x,y+1);
	}
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k>>p;
	dfs(1,1);
	cout<<ans<<'\n';
	return 0;
}
