#include<bits/stdc++.h>
using namespace std;
typedef long long lt;
inline lt read()
{
	lt sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=303;
const int M=90;
const int Q=2e5+3;
struct G
{
	lt x1,x2,y1,y2;
}gg[Q];
lt a[N][N];
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	lt n=read(),T=read(),i,j,x1,x2,y1,y2,k,l;
	for(i=1;i<=n;++i) for(j=1;j<=n;++j) a[i][j]=read();
	if(n<=100)
	{
		lt dp[M][M][M][M];
		for(i=1;i<=n;++i) for(j=1;j<=n;++j) for(k=i;k<=n;++k) for(l=j;l<=n;++l) dp[i][j][k][l]=1e18+3;
		for(i=1;i<=n;++i) for(j=1;j<=n;++j) dp[i][j][i][j]=a[i][j];
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				for(k=i;k<=n;++k)
				{
					for(l=j;l<=n;++l)
					{
						if(k==i&&l==j) continue;
						if(k-1<i) dp[i][j][k][l]=dp[i][j][k][l-1]+a[k][l];
						else
						{
							if(l-1<j) dp[i][j][k][l]=dp[i][j][k-1][l]+a[k][l];
							else dp[i][j][k][l]=min(dp[i][j][k-1][l],dp[i][j][k][l-1])+a[k][l];
						}
					}
				}
			}
		}
		while(T--)
		{
			x1=read(),x2=read(),y1=read(),y2=read();
			printf("%lld\n",dp[x1][y1][x2][y2]);
		}
		return 0;
	}
	bool f=true;
	for(i=1;i<=T;++i)
	{
		gg[i].x1=read(),gg[i].x2=read(),gg[i].y1=read(),gg[i].y2=read();
		if(gg[i].x1!=1) f=false;
	}
	if(f)
	{
		lt dp[201][201][201];
		for(j=1;j<=n;++j) for(k=1;k<=n;++k) for(l=j;l<=n;++l) dp[j][k][l]=1e18+3;
		for(j=1;j<=n;++j) dp[j][1][j]=a[1][j];
		for(j=1;j<=n;++j)
		{
			for(k=1;k<=n;++k)
			{
				for(l=j;l<=n;++l)
				{
					if(k==1&&l==j) continue;
					if(k==1) dp[j][1][l]=dp[j][1][l-1]+a[1][l];
					else
					{
						if(l-1<j) dp[j][k][l]=dp[j][k-1][l]+a[k][l];
						else dp[j][k][l]=min(dp[j][k-1][l],dp[j][k][l-1])+a[k][l];
					}
				}
			}
		}
		for(i=1;i<=T;++i) printf("%lld\n",dp[gg[i].y1][gg[i].x2][gg[i].y2]);
	}
}
