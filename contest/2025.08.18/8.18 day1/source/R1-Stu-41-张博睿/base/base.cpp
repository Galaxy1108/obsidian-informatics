#include<bits/stdc++.h>
using namespace std;
const int N=2000+10;
int n;
int a[2][N];
int s[N];
int b[N];
int cnt=0;

signed main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[1][i];
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[1][i]+a[2][i];
	int ans=0;
	for(int l=1;l<=n-2;l++)
	{
		if(cnt>=1e7)break;
		for(int r=l+2;r<=n;r++)
		{
			if(cnt>=1e7)break;
			for(int i=l+1;i<=r-1;i++)
			{
				if(cnt>=1e7)break;
				for(int j=i;j<=r-1;j++)
				{
					if(cnt>=1e7)break;
					ans=max( ans, b[r]-b[l-1]-(s[j]-s[i-1]) );
					cnt++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
