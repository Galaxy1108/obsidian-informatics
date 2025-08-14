#include <bits/stdc++.h>
#define N 1000005
#define int __int128
using namespace std;
int e[N]={0,1},f[N]={0,1},lcm[N]={0,1};
long long n,p;
void init()
{
	for(int i=2;i<=n;i++)
	{
//		e[i]=(e[i-1]+2*f[i-1])%p;
		e[i]=(e[i-1]+2*f[i-1]);
//		f[i]=(f[i-1]+e[i-1])%p;
		f[i]=(f[i-1]+e[i-1]);
		lcm[i]=f[i]/__gcd(f[i],lcm[i-1])*lcm[i-1];
	}
}

signed main()
{
//	freopen("lcm.in","r",stdin);
//	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long t;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		init();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
//			write(f[i]);
			ans=(ans+((i%p)*(lcm[i])%p)%p)%p;
//			cout<<(long long)lcm[i]<<'\n';
		}
//		write(ans);
		cout<<(long long)ans<<'\n';
	}
	return 0;
} 
