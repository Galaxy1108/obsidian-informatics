#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=2e6+10;
int n,h[N],ans=-1;
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		int minn=1e18,maxx=-1;
		for(int j=i;j<=n;j++)
		{
			minn=min(minn,h[j]);
			maxx=max(maxx,h[j]);
			ans=max(ans,maxx*minn*(j-i+1));
		}
	}
	cout<<ans;
	return 0;
}
