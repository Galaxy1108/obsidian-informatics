#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int g[105][3],s[105][3],f[105][15];
int ans=-1e9;

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	if(m==1)
	{
		int a[105]={0};
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int cnt=1;cnt<=k;cnt++)
		{

			for(int i=cnt;i<=n;i++)
			{
				f[i][cnt]=max(a[i],f[i-1][cnt]+a[i]);
				if(cnt!=1)
				{
					int maxi=-1,maxx=-1e9;
					for(int p=1;p<i;p++)
					{
						maxx=max(maxx,f[p][cnt-1]);
					}
					f[i][cnt]=max(f[i][cnt],maxx+a[i]);
				}
				
			}
		}
		
		cout<<f[n][k];
	}
	else
	{

	}
	
	return 0;
}
/*
11 1 3
1 2 3 -5 7 -18 9 4 2 -3 7

*/
