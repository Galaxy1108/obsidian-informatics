#include<bits/stdc++.h>
using namespace std;
const int mod=9999973;
inline int qread()
{
	register int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,m;
long long dp[110][110][110],ans;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	n=qread();
	m=qread();
	dp[0][0][0]=1;
	for(register int i=1;i<=n;++i)
	{
		for(register int j=0;j<=m;++j)
		{
			for(register int k=0;k<=m-j;++k)
			{
				dp[i][j][k]+=dp[i-1][j][k];
				if(k)dp[i][j][k]+=dp[i-1][j][k-1]*(m-j-k+1);
				if(k>=2)dp[i][j][k]+=dp[i-1][j][k-2]*(m-j-k+2)*(m-j-k+1)/2;
				if(j&&k<m)dp[i][j][k]+=dp[i-1][j-1][k+1]*(k+1);
				if(j>=2&&k<m-1)dp[i][j][k]+=dp[i-1][j-2][k+2]*(k+2)*(k+1)/2;
				if(j)dp[i][j][k]+=dp[i-1][j-1][k]*(m-j-k+1)*(k);
				dp[i][j][k]%=mod;
				if(i==n&&j+k<=m)(ans+=dp[i][j][k])%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
