#include <bits/stdc++.h>
using namespace std;
int mat[75][75],dp[75][75];
int r[75];
int sub[1<<6][2];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			dp[i][j]=-1;
		}
	}
	dp[0][0]=0;
	int h=m/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			r[i]=mat[i-1][j];
		}
		int cnt=0;
		for(int ma=0;ma < (1<<n);ma++)
		{
			int b=__builtin_popcount(ma);
			if(b>h) continue;
			int sum=0;
			for(int j=0;j<n;j++)
			{
				if(ma & (1<<j))
				{
					sum+=r[j];
				}
			}
			sub[cnt][0]=sum;
			sub[cnt][1]=sum%k;
			cnt++;
		}
		for(int p=0;p<k;p++)
		{
			if(dp[i-1][p]==-1)continue;
			for(int s=0;s<cnt;s++)
			{
				int sum=sub[s][0];
				int c=sub[s][1];
				int nd=(p+c)%k;
				int nm=dp[i-1][p]+sum;
				dp[i][nd]=max(dp[i][nd],nm);
			}
		}
	}
	cout<<max(dp[n][0],0);
}

