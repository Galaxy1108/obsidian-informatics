#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5;
int n,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int xr=0,mx=0;
		for(int j=i;j<=n;j++)
		{
			xr^=a[j],mx=max(mx,a[j]);
			if(xr<=mx)ans++;
		}
	}
	cout<<ans;
	return 0;
}
