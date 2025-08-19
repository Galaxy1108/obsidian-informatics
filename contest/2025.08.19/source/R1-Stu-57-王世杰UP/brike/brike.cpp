#include<bits/stdc++.h>
using namespace std;
int n,z[55][55],mtt;
int f[55][55][505];
int gt(int x,int y)
{
	int ret=0;
	while(x>0)
	{
		ret+=z[x][y];
		x--;y++;
	}
	return ret;
}

int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>mtt;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cin>>z[i][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			for(int m=(j*(j+1)/2);m<=(i*(i+1)/2)&&m<=mtt;m++)
			{
				if(j!=0)
				{
					f[j][i-j+1][m]=max(f[j][i-j+1][m],f[j-1][i-j+1][m-j]+gt(j,i-j+1));
					f[j][i-j+1][m]=max(f[j][i-j+1][m],f[j+1][i-j][m]);
				}
				else
				{
					f[j][i-j+1][m]=max(f[j][i-j+1][m],f[j+1][i-j][m]);
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			for(int m=(j*(j+1)/2);m<=(i*(i+1)/2)&&m<=mtt;m++)
			{
				if(j!=0)
				{
					f[j][i-j+1][m]=max(f[j][i-j+1][m],f[j-1][i-j+1][m-j]+gt(j,i-j+1));
					f[j][i-j+1][m]=max(f[j][i-j+1][m],f[j+1][i-j][m]);
				}
				else
				{
					f[j][i-j+1][m]=max(f[j][i-j+1][m],f[j+1][i-j][m]);
				}
			}
		}
	}
	int maxe=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			maxe=max(maxe,f[i][j][mtt]);
		}
	}
	cout<<maxe;
	return 0;
}
