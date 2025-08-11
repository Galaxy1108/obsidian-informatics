#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'&&c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=1e6+3;
const int M=1e3+3;
int a[N],b[N],h,w;
ll dp[M][M],ans;
void dfs(int x,int y)
{
	if(x==h&&y==w)
	{
		cout<<ans;
		return;
	}
	if(x==h&&y<w)
	{
		ans+=a[x];
		dfs(x,y+1);
	}
	if(x<h&&y==w)
	{
		ans+=b[y];
		dfs(x+1,y);
	}
	if(x<h&&y<w)
	{
		if(a[x]<b[y])
		{
			ans+=a[x];
			dfs(x,y+1);
		}
		else
		{
			ans+=b[y];
			dfs(x+1,y);
		}
	}
}
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	int i,j;
	h=read();
	w=read();
	for(i=1;i<=h;++i) a[i]=read();
	for(i=1;i<=w;++i) b[i]=read();
	if(h<=1e3&&w<=1e3)
	{
		for(i=h;i;--i)
		{
			for(j=w;j;--j)
			{
				if(i==h&&j!=w) dp[i][j]=dp[i][j+1]+a[i];
				if(j==w&&i!=h) dp[i][j]=dp[i+1][j]+b[j];
				if(j!=w&&i!=h) dp[i][j]=min(dp[i+1][j]+b[j],dp[i][j+1]+a[i]);
				if(i==h&&j==w) dp[i][j]=0;
			}
		}
		cout<<dp[1][1];
		return 0;
	}
	dfs(1,1);
}
