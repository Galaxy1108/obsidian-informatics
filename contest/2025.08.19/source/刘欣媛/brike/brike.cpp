#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][55];
int f[55][55][505];
bool mp[55][55][505];
int mx[505];
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			//f[0][j]=1;
			cin>>a[i][j];
		}
	}
	//f[0][n+1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			for(int l=1;l<=m;l++)
			{
				if(i==1)
				{
					if(mx[l]>mx[l-1]+a[i][j])
					{
						f[i][j][l]=mx[l];
					}
					else
					{
						
					}
					f[i][j][l]=max(mx[l],mx[l-1]+a[i][j]);
				}
				else
				{
					if(mp[i-1][j][l-1]&&mp[i-1][j+1][l-1])
					{
						f[i][j][l]=max(mx[l],mx[l-1]+a[i][j]);
						
					}
					else
					{
						f[i][j][l]=mx[l];
					}
				}
				
				mx[l]=max(mx[l],f[i][j][l]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		ans=max(ans,f[n][1][i]);
	}
	cout<<ans;
	return 0;
} 
