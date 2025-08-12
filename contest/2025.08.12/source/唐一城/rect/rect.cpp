#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=55;
int n,m,f[N][N][N][N],a[N][N],sum[N][N];
struct node
{
	int a,b,c,d;
};
node to1[N][N][N][N],to2[N][N][N][N];
il bool get(int a,int b,int c,int d)
{
	return (c-a+1)*(d-b+1)==sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}
int ans[N][N];
int num=0;
il void dfs(node x)
{
	if(x.a==-1)return;
	if(get(x.a,x.b,x.c,x.d))
	{
		++num;
		for(int i=x.a;i<=x.c;i++)for(int j=x.b;j<=x.d;j++)ans[i][j]=num;
		return;
	}
	dfs(to1[x.a][x.b][x.c][x.d]);
	dfs(to2[x.a][x.b][x.c][x.d]);
}
il void solve1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i;k>=1;k--)
			{
				for(int l=j;l>=1;l--)
				{
					if(get(k,l,i,j))f[k][l][i][j]=1,to1[k][l][i][j]=(node){k,l,i,j},to2[k][l][i][j]=(node){-1,-1,-1,-1};
					else if(k==i&&l==j)f[k][l][i][j]=0,to1[k][l][i][j]=(node){-1,-1,-1,-1},to2[k][l][i][j]=(node){-1,-1,-1,-1};
					else 
					{
						f[k][l][i][j]=0x7f7f7f7f;
						for(int t=l;t<j;t++)
						{
							if(f[k][l][i][j]>f[k][l][i][t]+f[k][t+1][i][j])
							{
								f[k][l][i][j]=f[k][l][i][t]+f[k][t+1][i][j];
								to1[k][l][i][j]=(node){k,l,i,t};
								to2[k][l][i][j]=(node){k,t+1,i,j};
							}
						}
						for(int t=k;t<i;t++)
						{
							if(f[k][l][i][j]>f[k][l][t][j]+f[t+1][l][i][j])
							{
								f[k][l][i][j]=f[k][l][t][j]+f[t+1][l][i][j];
								to1[k][l][i][j]=(node){k,l,t,j};
								to2[k][l][i][j]=(node){t+1,l,i,j};
							}
						}
					}
				}
			}
		}
	}
//	cout<<f[1][1][n][m];
	dfs(to1[1][1][n][m]);
	dfs(to2[1][1][n][m]);
}
il void solve2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==0&&a[i][j]==1)ans[i][j]=++num;
		}
	}
}
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			if(c=='C')a[i][j]=1;
			else a[i][j]=0;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	int nn=n,mm=m;
	n=min(50,n),m=min(50,m);
	solve1();
	if(n>50&&m>50)
	{
		n=nn,m=mm;
		solve2();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cout<<ans[i][j]<<' ';
			cout<<'\n';
		}
	}
	else
	{
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cout<<ans[i][j]<<' ';
			cout<<'\n';
		}
	}
	return 0;
}
/*
4 5
CCBCB
CCBBB
CCCBB
CCCBB
*/
