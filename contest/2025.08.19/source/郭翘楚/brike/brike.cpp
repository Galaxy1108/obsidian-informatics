#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int f[55][55][505];
int sbzjj[55][55];
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sbzjj[j][i]=sbzjj[j-1][i] + a[j][i];
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=0;i<=n;i++)
		{
			for(int k=i;k<=m;k++)
			{
				for(int zjj=0;zjj<=i+1;zjj++)
				{
					f[i][j][k]=max(f[i][j][k],f[zjj][j-1][k-i]+sbzjj[i][j]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,f[i][n][m]);
	}
	cout<<ans;
	return 0;
} 
