#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
const ll N=1e6+5,inf=1e18;
int n,m,a[N],b[N];
ll f[1005][1005];
il void solve1()
{
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)f[i][j]=inf;
	f[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)continue;
			f[i][j]=min(f[i][j-1]+a[i],f[i-1][j]+b[j]);
		}
	}
	cout<<f[n][m];
}
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	if(n<=1000)solve1();
	return 0;
}
