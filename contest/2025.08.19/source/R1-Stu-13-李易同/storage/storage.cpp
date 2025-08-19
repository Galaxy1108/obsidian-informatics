#include <iostream>
#include <cstring>
using namespace std;
int n;
int x[1000010],p[1000010],c[1000010];
long long total[1000010],sum[1000010];
int la;
long long dp[1000010];
long long cost(int now,int st)
{
	return total[now]-total[st]-sum[st-1]*(x[now]-x[st]);
}
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
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		x[i]=read();
		p[i]=read();
		c[i]=read();
		sum[i]=sum[i-1]+p[i];
		total[i]=total[i-1]+sum[i-1]*(x[i]-x[i-1]);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	la=1;
	for(int i=1;i<=n;++i)
		for(int j=la;j<=i;++j)
		{
			long long temp=dp[j-1]+cost(i,j)+c[i];
			if(temp<=dp[i])
			{
				dp[i]=temp;
				la=j;
			}
		}
	cout<<dp[n];
	return 0;
}
