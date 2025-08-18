#include <iostream>
using namespace std;
int n,k;
int a[10010];
int dp[10010];
int ans=0x3f3f3f3f;
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
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i)
	{
		dp[i]=0x3f3f3f3f;
		if(i<=k) for(int j=1;j<i;++j) dp[i]=min(dp[i],a[i]+a[j]);
		else for(int j=i-1;j>=i-k+1;--j) dp[i]=min(dp[i],dp[j]+a[i]);
	}
	for(int i=n;i>n-k+1;--i)
		for(int j=i-1;j>=n-k+1;--j)
			ans=min(ans,a[i]+dp[j]);
	cout<<ans;
	return 0;
}
