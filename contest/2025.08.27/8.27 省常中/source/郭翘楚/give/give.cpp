#include <bits/stdc++.h>
using namespace std;
int a[205];
int dp[2005][5005];
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		int m,s,n;
		cin>>m>>s>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]; 
		}
		if(n*m*s>=1e9)
		{
			cout<<0<<endl;
			continue;
		} 
		dp[0][0]=1; 
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=a[j];k<=s;k++)
				{
					dp[i][k]+=dp[i-1][k-a[j]];
					dp[i][k]%=2;
				}
			}
		}
		cout<<dp[m][s]%2<<endl;
	} 
}
