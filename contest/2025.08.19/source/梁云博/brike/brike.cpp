#include <bits/stdc++.h>
using namespace std;
int a[55][55],s[55][55];
int f[55][55][505],ans=-1e9;
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
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n-j+1;i++)
		{
			s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n-j+1;i++)
		{
			for(int k=i;k<=m;k++)
			{
				f[i][j][k]=s[i][j]; 
				//当前列从前一列1~i+1转移
				for(int lst=1;lst<=i+1;lst++)
				{
					f[i][j][k]=max(f[i][j][k],s[i][j]+f[lst][j-1][k-i]);	
				}
				if(k==m)ans=max(ans,f[i][j][k]);
			}
		}
	}
	cout<<ans;
}
