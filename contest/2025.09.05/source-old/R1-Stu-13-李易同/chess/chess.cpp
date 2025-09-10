#include <iostream>
#define g m-p-q
using namespace std;
const int mod=9999973;
int n,m;
long long dp[110][110][110];
long long ans;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	dp[0][m][0]=1;
	for(int i=1;i<=n;++i)
		for(int p=0;p<=m;++p)
			for(int q=0;q<=m;++q)
			{
				dp[i][p][q]=dp[i-1][p][q];
				if(p+2<=m && q-2>=0) dp[i][p][q]=(dp[i][p][q]+dp[i-1][p+2][q-2]*(p+2)*(p+1)/2)%mod;
				if(p+1<=m && q>0 && g-1>=0) dp[i][p][q]=(dp[i][p][q]+dp[i-1][p+1][q]*(p+1)*q)%mod;
				if(q+2<=m && g-2>=0) dp[i][p][q]=(dp[i][p][q]+dp[i-1][p][q+2]*(q+2)*(q+1)/2)%mod;
				if(p+1<=m && q-1>=0) dp[i][p][q]=(dp[i][p][q]+dp[i-1][p+1][q-1]*(p+1))%mod;
				if(q+1<=m && g-1>=0) dp[i][p][q]=(dp[i][p][q]+dp[i-1][p][q+1]*(q+1))%mod;
			}
	for(int p=0;p<=m;++p)
		for(int q=0;q<=m;++q)
			ans=(ans+dp[n][p][q])%mod;
	cout<<ans;
	return 0;
}
