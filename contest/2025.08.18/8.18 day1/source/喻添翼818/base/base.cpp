#include<bits/stdc++.h>
using namespace std;
const int mx=2050;
long long f1[mx][mx];
long long a[4][mx],sum[4][mx];
long long ans=-1e11;
int n;
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	memset(sum,0,sizeof(sum));
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++) a[3][i]=a[1][i]+a[2][i],sum[3][i]=sum[1][i]+sum[2][i];
	for(int i=1;i<=mx-1;i++)
		for(int j=1;j<=mx-1;j++)
			f1[i][j]=1e11;
	for(int i=n-1;i>=2;i--)
	{
		for(int j=i;j<=n-1;j++)
		{
		    f1[i][j]=sum[1][j]-sum[1][i-1];
		    f1[i][j]=min(f1[i][j],min(f1[i+1][j],f1[i][j-1]));
		}
	}
	for(int i=1;i<=n-2;i++)
		for(int j=i+2;j<=n;j++)
			ans=max(ans,sum[3][j]-sum[3][i-1]-f1[i+1][j-1]);
	cout<<ans;
	return 0;
}
