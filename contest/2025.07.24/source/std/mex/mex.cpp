#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline void add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
int qpow(int a,int p)
{
	int ret=1;
	for(;p;p>>=1,a=1ll*a*a%Mod)
		if(p&1) ret=1ll*ret*a%Mod;
	return ret;
}
int dp[5010][5010];
int n,m,ans;
int s[5010];
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	
	n=Qread(),m=Qread();m++;
	for(int i=1;i<=n;i++) s[i]=Qread();

	if(m>=n)
	{
		ans=1;
		for(int i=1;i<=n;i++) if(!s[i])
			ans=1ll*ans*(m-1)%Mod;
		printf("%d\n",ans);
		return 0;
	}

	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i])
		{
			for(int j=1;j<=m;j++)
				dp[i][j]=dp[i-1][j-1];
		}
		else
		{
			for(int j=0;j<=m;j++) if(dp[i-1][j])
			{
				dp[i][j]=(dp[i][j]+1ll*dp[i-1][j]*j)%Mod;
				dp[i][j+1]=(dp[i][j+1]+1ll*dp[i-1][j]*(m-j-1))%Mod;
			}
		}
	}
	for(int j=1;j<=m;j++)
		add(ans,dp[n][j]);
	printf("%d\n",ans);
	return 0;
}