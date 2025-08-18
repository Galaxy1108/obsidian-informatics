#include<bits/stdc++.h>
using namespace std;
const int mi=-10000000;
int n,m,k;
int mt[101][3];
int he[101][101][4];
int fu[101][101][11];
int fd[101][101][11];
int fz[101][101];
int f[101][11];

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			cin>>mt[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				he[i][j][1]=mt[i][1];
				he[i][j][2]=mt[i][2];
				he[i][j][3]=mt[i][1]+mt[i][2];
			}
			else
			{
				he[i][j][1]=max(0,he[i][j-1][1])+mt[j][1];
				he[i][j][2]=max(0,he[i][j-1][2])+mt[j][2];
				he[i][j][3]=max(0,he[i][j-1][3])+mt[j][1]+mt[j][2];
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			he[i][j][1]=max(he[i][j][1],he[i][j-1][1]);
			he[i][j][2]=max(he[i][j][2],he[i][j-1][2]);
			he[i][j][3]=max(he[i][j][3],he[i][j-1][3]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			fz[i][j]=max(he[i][j][1],he[i][j][2]);
			fz[i][j]=max(fz[i][j],he[i][j][3]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int s=i;s<=n;s++)
		{
			fu[i][s][1]=he[i][s][1];
			fd[i][s][1]=he[i][s][2];
			for(int r=2;r<=k;r++)
			{
				for(int j=i;j<s;j++)
				{
					fu[i][s][r]=max(fu[i][j][r-1]+he[j+1][s][1],fu[i][s][r]);
					fd[i][s][r]=max(fd[i][j][r-1]+he[j+1][s][2],fd[i][s][r]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int r=1;r<=k;r++)
		{
			f[i][r]=f[i-1][r];
			for(int j=0;j<i;j++)
			{
				f[i][r]=max(f[i][r],f[j][r-1]+fz[j+1][i]);
				for(int r0=2;r0<=r;r0++)
				{
					for(int r1=0;r1<=r0;r1++)
					{
						f[i][r]=max(f[j][r-r0]+fu[j+1][i][r1]+fd[j+1][i][r0-r1],f[i][r]);
					}
				}
			}
		}
	}
	cout<<f[n][k];
	return 0;
}
