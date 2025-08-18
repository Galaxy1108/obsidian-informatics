#include<bits/stdc++.h>
using namespace std;
int f[105][105][15],a[105][2],s[105][4];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=0;i<=n;i++)
		for(int p=0;p<=n;p++)
			for(int j=1;j<=k;j++)f[i][p][j]=-1e9;
	if(m==1)
	{
		for(int i=1;i<=n;i++)s[i][0]=s[i-1][0]+a[i][0];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				for(int p=1;p<=k;p++)
					f[i][0][p]=max(f[i-1][0][p],max(f[i][0][p],f[j-1][0][p-1]+s[i][0]-s[j-1][0]));
			}
		}
		cout<<f[n][0][k]<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		s[i][0]=s[i-1][0]+a[i][0];
		s[i][1]=s[i-1][1]+a[i][1];
		s[i][2]=s[i-1][2]+a[i][0]+a[i][1];
		//cout<<s[i][0]<<' '<<s[i][1]<<' '<<s[i][2]<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				for(int t=1;t<=i;t++)
					for(int p=1;p<=k;p++)
						f[i][j][p]=max(max(f[i-1][j][p],f[i][j-1][p]),max(f[i][j][p],f[t-1][t-1][p-1]+s[i][2]-s[t-1][2]));
			}
			for(int t=1;t<=i;t++)
				for(int p=1;p<=k;p++)
						f[i][j][p]=max(max(f[i-1][j][p],f[i][j-1][p]),max(f[i][j][p],f[t-1][j][p-1]+s[i][0]-s[t-1][0]));
			for(int t=1;t<=j;t++)
				for(int p=1;p<=k;p++)
						f[i][j][p]=max(max(f[i-1][j][p],f[i][j-1][p]),max(f[i][j][p],f[i][t-1][p-1]+s[j][1]-s[t-1][1]));
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int p=1;p<=k;p++)
			{
				cout<<"("<<i<<","<<j<<","<<p<<"): "<<f[i][j][p]<<'\n';
			}
		}
	}*/
	cout<<f[n][n][k]<<'\n';
	return 0;
}
/*
2 1 2
-1 -1
-1 -1
*/
