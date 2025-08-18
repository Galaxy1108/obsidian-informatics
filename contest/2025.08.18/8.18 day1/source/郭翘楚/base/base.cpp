#include <bits/stdc++.h>
using namespace std;
const long long INF=2147483647;
long long m[3][2005];
long long qz[2005];
long long hz[2005];
long long h[2005];
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=2;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			cin>>m[i][j];
			if(i==2)
			{
				h[j]=h[j-1]+m[2][j];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		long long ans=-INF,sum=0;
		for(long long j=i;j>=1;j--)
		{
			sum+=m[1][j]+m[2][j];
			ans=max(ans,sum);
		}
		qz[i]=ans;
	}
	for(long long i=n;i>=1;i--)
	{
		long long ans=-INF,sum=0;
		for(long long j=i;j<=n;j++)
		{
			sum+=m[1][j]+m[2][j];
			ans=max(ans,sum);
		}
		hz[i]=ans;
	}
	long long temp=0;
	for(long long l=1;l<=n;l++)
	{
		for(long long r=n;r>l+1;r--)
		{
			long long mid=h[r-1]-h[l];
			temp=max(temp,qz[l]+hz[r]+mid);
		}
	}
	cout<<temp;
}
