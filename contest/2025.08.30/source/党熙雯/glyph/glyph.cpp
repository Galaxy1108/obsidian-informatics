#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
int n,q;
int a[210][210];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	n=fread(),q=fread();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) a[i][j]=fread();
	if(n<=100)
	{
		int f1[101][101][101][101];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int ii=i;ii<=n;ii++)
				{
					for(int jj=j;jj<=n;jj++)
					{
						if(i==ii&&j==jj) f1[i][j][ii][jj]=a[ii][jj];
						else if(ii==i)
						{
							f1[i][j][ii][jj]=f1[i][j][ii][jj-1]+a[ii][jj];
						}
						else if(jj==j)
						{
							f1[i][j][ii][jj]=f1[i][j][ii-1][j]+a[ii][jj];
						}
						else
						f1[i][j][ii][jj]=min(f1[i][j][ii][jj-1]+a[ii][jj],f1[i][j][ii-1][jj]+a[ii][jj]);
					}
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			cout<<f1[1][3][i][j]<<' ';
//			cout<<endl;
//		}
		while(q--)
		{
			int x=fread(),xx=fread(),y=fread(),yy=fread();
			cout<<f1[x][y][xx][yy]<<endl;
		}
	}
	else
	{
		int f2[201][201][201];
		memset(f2,0,sizeof(f2));
		for(int jj=1;jj<=n;jj++)
		for(int i=1;i<=n;i++)
		{
			for(int j=jj;j<=n;j++)
			{
				if(i==1)
				f2[jj][i][j]=f2[jj][i][j-1]+a[i][j];
				else if(j==jj)
				f2[jj][i][j]=f2[jj][i-1][j]+a[i][j];
				else
				f2[jj][i][j]=min(f2[jj][i-1][j]+a[i][j],f2[jj][i][j-1]+a[i][j]);
			}
		}
		while(q--)
		{
			int x=fread(),xx=fread(),y=fread(),yy=fread();
			cout<<f2[y][xx][yy]<<endl;
		}
	}
	return 0;
}

