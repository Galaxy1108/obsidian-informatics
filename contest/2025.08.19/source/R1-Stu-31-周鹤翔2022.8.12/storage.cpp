#include<bits/stdc++.h>
#define int long long
#define MAXN 1000100
#define INF 9223372036854000000
using namespace std;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+(ch^48),ch=getchar());
	return (f==1)?s:-s;
}
int n,x[MAXN],p[MAXN],c[MAXN],sum1[MAXN],sum2[MAXN];
int dp[MAXN];
int Y(int i)
{
	return dp[i]+sum2[i];
}
int X(int i)
{
	return sum1[i];
}
double slove(int j,int i)
{
	return 1.000*(Y(i)-Y(j))/(X(i)-X(j));
}
int que[MAXN],hd=0,tl=0;
signed main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
//	freopen("1.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		p[i]=read();
		c[i]=read();
		sum1[i]=sum1[i-1]+p[i];
		sum2[i]=sum2[i-1]+x[i]*p[i];
		dp[i]=INF;
	}
	dp[1]=c[1];
	tl++;
	que[tl]=1;
	for(int i=2;i<=n;i++)
	{
		while(hd<tl&&slove(que[hd],que[hd+1])<x[i])hd++;
		dp[i]=dp[que[hd]]+x[i]*(sum1[i]-sum1[que[hd]])-sum2[i]+sum2[que[hd]]+c[i];
		while(hd<tl&&slove(que[tl],que[tl-1])>slove(i,que[tl-1]))tl--;
		tl++;que[tl]=i;
//		for(int j=0;j<=i;j++)
//		{
//			dp[i]=min(dp[i]-c[i],dp[j]+x[i]*(sum1[i]-sum1[j])-sum2[i]+sum2[j])+c[i];
//		}
	}
	cout<<dp[n]<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<dp[i]<<" ";
//		if(i%100==0)cout<<endl;
//	}
	return 0;
}
