#include <bits/stdc++.h>
using namespace std; 
long long mod,dp[1005][1005];
int n,m;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
    cin>>n>>m>>mod;
    if(m==1)
    {
    	cout<<1<<endl;
		return 0; 
	} 
	if(n==1)
	{
		cout<<(n*(n+1)/2)%mod;
		return 0;
	}
    for(int i=1;i<=m;i++)
	{
		dp[1][i]=i;
	}
    for(int i=2;i<=n;i++)
	{
        long long zjjsb=0,zjj2b=0,zjjjb=0;
        for(int j=1;j<=m;j++)
		{
            zjjsb+=dp[i-1][m-j+1];
            zjj2b+=dp[i-1][j];
            dp[i][j]=(zjjsb*j-zjjjb)%mod;
            zjjjb+=zjj2;
        }
    }
    long long ans=0;
    for (int i=1;i<=m;i++)
	{
		ans+=dp[n][i]%mod;
	}
    cout<<ans%mod;
    return 0;
}
/* 


1   i+1   i+k   n 
长度为k的区间的下一个区间有k(n-k)+max(0,(i-1)(n-i-k))+1种情况 

*/
