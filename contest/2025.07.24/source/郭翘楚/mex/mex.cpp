#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
unsigned long long dp[5005]; 
int s[5005];
long long binmul(long long a, long long b, long long m)
{
	unsigned long long c =(unsigned long long)a * b -(unsigned long long)((long double)a / m * b + 0.5L) * m;
	if (c < m) return c;
	return c + m;
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	} 
	dp[0]=1;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1)
		{
			dp[i]=dp[i-1];
			dp[i]%=mod;
			cnt++;
		}
		else
		{
			dp[i]=binmul(dp[i-1],m,mod)%mod;	
		}
	}
	cout<<dp[n]%mod;
	return 0;
} 
