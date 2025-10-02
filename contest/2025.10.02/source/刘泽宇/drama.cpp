#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[10005];
long long ans;
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=i;j<=n;j++)
 		{
 			int maxx=0,minn=2147283647;
 			for(int k=i;k<=j;k++)
 			{
 				maxx=max(maxx,a[k]);
 				minn=min(minn,a[k]);
			}
			ans=max(ans,maxx*minn*(j-i+1));
		}
	}
	cout<<ans;
	return 0;
}
