#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
ll f[1005][1005],a[N],b[N];
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	if(n<=1000&&m<=1000)
	{
		memset(f,0x3f,sizeof(f));
		f[1][1]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1&&j==1)continue;
				f[i][j]=min(f[i-1][j]+b[j],f[i][j-1]+a[i]);
			}
		}
		cout<<f[n][m]<<'\n';
	}
	else
	{
		ll ans=1e18;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,a[i]*(m-1)+b[1]*(i-1)+b[m]*(n-i));
		}
		for(int i=1;i<=m;i++)
		{
			ans=min(ans,b[i]*(n-1)+a[1]*(i-1)+a[n]*(m-i));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
