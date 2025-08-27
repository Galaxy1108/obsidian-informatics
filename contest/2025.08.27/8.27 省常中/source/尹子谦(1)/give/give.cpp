#include<bits/stdc++.h>
using namespace std;
const int N=210,M=2e3+10,S=5e3+10;
int a[N],dp[M][S];
void solve()
{
	memset(dp,0,sizeof dp);
	int m,n,s;
	cin>>m>>s>>n;
	if(m>=1e9)
	{
		cout<<0<<endl;
		return ;
	} 
	for(int i=1;i<=n;i++) cin>>a[i],dp[1][a[i]]=1;
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int p=a[j];p<=s;p++)
			{
				dp[i][p]+=dp[i-1][p-a[j]];
				dp[i][p]%=2;
			}
		}
	}
	cout<<dp[m][s]%2<<endl;
}
signed main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	} 
	return 0;
} 
