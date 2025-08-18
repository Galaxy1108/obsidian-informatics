#include <iostream>
using namespace std;
int n;
long long val[2020];
long long dp[2010][2010];
long long sum[2010];
long long ans=-100000000000000;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) val[i]=read();
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+read();
	for(int i=1;i+2<=n;++i) dp[i][i+2]=val[i]+val[i+2];
	for(int len=4;len<=n;++len)
		for(int i=1;i+len-1<=n;++i)
		{
			dp[i][i+len-1]=max(dp[i+1][i+len-1]+val[i],dp[i][i+len-2]+val[i+len-1]);
			dp[i][i+len-1]=max(dp[i][i+len-1],val[i]+val[i+len-1]);
		}
	for(int i=1;i+2<=n;++i)
		for(int j=i+2;j<=n;++j)
			ans=max(ans,sum[j]-sum[i-1]+dp[i][j]);
	cout<<ans;
	return 0;
}
