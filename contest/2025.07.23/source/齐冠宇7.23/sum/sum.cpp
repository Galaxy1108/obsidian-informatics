#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=105;
int n,m,k,mod;
int a[N][N],mn1[N],mn2[N];
int ans,sum;
void dfs(int x,int y)
{
	if(x==n && y==m+1)
	{
		for(int i=1;i<=n;i++)
		{
			mn1[i]=1e9;
			for(int j=1;j<=m;j++)
				mn1[i]=min(mn1[i],a[i][j]);
		}
		for(int j=1;j<=m;j++)
		{
			mn2[j]=1e9;
			for(int i=1;i<=n;i++)
				mn2[j]=min(mn2[j],a[i][j]);
		}
		sum=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum=sum*min(mn1[i],mn2[j])%mod;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%2d",a[i][j]);
//			}
//			putchar('\n');
//		}
//		cout<<"SUM:"<<sum<<'\n'<<'\n';
		ans=(ans+sum)%mod;
		return;
	}
	if(y==m+1)
	{
		dfs(x+1,1);
		return;
	}
	for(int i=1;i<=k;i++)
	{
		a[x][y]=i;
		dfs(x,y+1);
	}
}
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>mod;
	dfs(1,1);
	cout<<ans;
	return 0;
}
