#include<bits/stdc++.h>
using namespace std;
#define int long int 
#define D double
const int N=2005;

inline int read()
{
	char ch=getchar();int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}

int n;
D cost;
D w[N],c[N],d[N];
D f[N][N];
D g[N][N];

signed main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	n=read();cin>>cost;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i]>>d[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int cst1=cost;int cst2=cost;
			if(g[i-1][j]==0)cst1=0;
			if(g[i-1][j-1]==0)cst2=0;
			D mx=max(f[i-1][j-1]-cst2+g[i-1][j-1]*d[i] ,max( f[i-1][j]-cst1+g[i-1][j]*d[i] , ( f[i-1][j-1]*c[i] + g[i-1][j-1] ) *d[i] -cost ) ) +w[i];
			if(mx==f[i-1][j-1]-cst2+g[i-1][j-1]*d[i]+w[i])
			{
				g[i][j]=0;
				f[i][j]=mx;
			}
			else if(mx==f[i-1][j]-cst1+g[i-1][j]*d[i]+w[i])
			{
				f[i][j]=mx;
			}
			else if(mx==( f[i-1][j-1]*c[i] + g[i-1][j-1] ) *d[i] -cost +w[i] ) 
			{
				f[i][j]=0;
				g[i][j]=f[i-1][j-1]*c[i] + g[i-1][j-1];
			}
		}
	}
	D ans=0.0000;	
	for(int j=0;j<=n;j++)
	{
		int cst=cost;
		if(g[n][j]-cost==0)cst=0;
		ans=max( ans, f[n][j]+g[n][j]*d[n]-cst );
	}
	printf("%.4lf",ans);
	return 0;
}
