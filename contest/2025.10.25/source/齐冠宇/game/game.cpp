#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e6+5,M=1e6+5;
int n,a[M],b[M],ans;
int t[M],mx; 
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),t[a[i]]++;
	for(int i=1;i<=mx;i++)t[i]+=t[i-1];
	for(int i=1;i<=mx;i++)
	{
		int cnt=mx/i,sm=0;
		for(int j=1;j<=cnt;j++)b[j]=t[min(i*(j+1)-1ll,mx)]-t[i*j-1],sm+=b[j]&1;
		if(sm==1)if(b[1]&1)ans+=b[1];
		if(sm==2)for(int j=2;j<=cnt;j++)if((b[j]&1) && (b[j-1]&1))ans+=b[j];
	}
	cout<<ans;
	return 0;
}