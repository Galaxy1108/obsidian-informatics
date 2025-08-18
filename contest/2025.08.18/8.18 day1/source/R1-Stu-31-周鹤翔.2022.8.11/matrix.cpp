#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+(ch^48),ch=getchar());
	return (f==1)?s:-s;
}
int dp[110][110][20],a[120][4],sum[120],n,m,k;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i][1];
		for(int j=1;j<=n;j++)
		for(int i=j;i<=n;i++)
		{
			dp[j][i][1]=max(a[i][1],dp[j][i-1][1]+a[i][1]);
		}
		for(int kk=2;kk<=k;kk++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					for(int p=i;p<=j;p++)
					{
						dp[i][j][kk]=max(dp[i][j][kk],dp[i][p][kk-1]+dp[p+1][j][1]);
					}
				}
			}
		}
		cout<<dp[1][n][k]<<endl;
		return 0;
	}
	return 0;
}
