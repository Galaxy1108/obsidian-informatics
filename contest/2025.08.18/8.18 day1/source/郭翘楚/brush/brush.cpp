#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[10005];
int a[10005];
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int sum=INF;
		for(int k=i-m;k<=i-2;k++)
		{
			int d1=2147483647,d2=2147483647;
			for(int l=k+1;l<=i;l++)
			{
				d1=min(d1,a[l]);
			}
			for(int l=k+1;l<=i;l++)
			{
				if(a[l]<d2 and a[l]!=d1)
				{
					d2=a[l];
				}
			}
			sum=min(sum,dp[k]+d1+d2);
		}
		dp[i]=sum;
	}
	cout<<dp[n];
	return 0;
}
