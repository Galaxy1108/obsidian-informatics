#include <bits/stdc++.h>
#define int long long
#define N 305
using namespace std;
int n,q;
int g[N][N];
int f[N][N];
//由1出发的最短路径 
int xa,xb,ya,yb,flg=1;
signed main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
		}
	} 	
	while(q--)
	{
		cin>>xa>>xb>>ya>>yb;
		for(int i=xa-1;i<=xb;i++)f[i][ya-1]=0x3f3f3f3f3f3f3f3f;
		for(int j=ya-1;j<=yb;j++)f[xa-1][j]=0x3f3f3f3f3f3f3f3f;
		f[xa][ya]=0;
		for(int i=xa;i<=xb;i++)
		{
			for(int j=ya;j<=yb;j++)
			{
				if(i==xa && j==ya)f[i][j]=min({f[i][j],f[i-1][j],f[i][j-1]})+g[i][j];
				else f[i][j]=min(f[i-1][j],f[i][j-1])+g[i][j];
			}
		}
		cout<<f[xb][yb]<<"\n";
	}
	return 0;
} 

