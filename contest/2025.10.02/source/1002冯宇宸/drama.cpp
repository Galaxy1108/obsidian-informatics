#include<bits/stdc++.h>
#define ll __int128
using namespace std;
const  int N=2e6+5;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(ll x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll max(ll a,ll b)
{
	if(a>b) return a;
	return b;
}
int a[N][21],b[N][21],lg[21];
int n,i,j;
ll ans,dp[N];
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++)
	{
		a[i][0]=read();
		b[i][0]=a[i][0];
		dp[i]=a[i][0]*a[i][0];
	}
	lg[1]=0;
	for(i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(j=1;j<=lg[n];j++)
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]);
			b[i][j]=min(b[i][j-1],b[i+(1<<(j-1))][j-1]);
		}
	for(int len=2;len<=n;++len)
		for(i=1;i+len-1<=n;i++)
		{
			j=i+len-1;
			int k=lg[len];
			int x=max(a[i][k],a[j-(1<<k)+1][k]),
			y=min(b[i][k],b[j-(1<<k)+1][k]);
			dp[j]=max(x*y*len,dp[j]);
		}
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	write(ans);
	return 0;
}
