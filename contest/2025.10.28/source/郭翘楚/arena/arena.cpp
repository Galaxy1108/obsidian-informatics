#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod=998244353;
long long f[505][505];
const long long maxn = 1000;
ll fac[maxn];       
ll inv[maxn];       
ll inv_fac[maxn]; 
ll get_inv(ll x)
{
	if (inv[x]) return inv[x];
	if (x == 1) return inv[x] = 1;
	return inv[x] = (mod - mod/x) * get_inv(mod % x) % mod;
}
void init()         
{
	for (long long i = 1; i < maxn; ++i)
		get_inv(i);
	fac[0] = inv_fac[0] = 1;
	for (long long i = 1; i < maxn; ++i)
	{
		fac[i] = fac[i-1] * i % mod;
		inv_fac[i] = inv_fac[i-1] * inv[i] % mod;
	}
}
long long qpow(long long n,long long k)
{
	long long ans=1;
	while(k)
	{
		if(k&1) ans*=n;
		ans%=mod;
		n*=n;
		n%=mod;
		k>>=1;
	}
	return ans; 
}
long long C(long long n, long long m)  
{
	if (m < 0 || n < m) return 0;
	return fac[n] * inv_fac[m] % mod * inv_fac[n-m] % mod;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	long long n,x;
	cin>>n>>x;
	init();
	long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=x;j++)
			{
				if(j>=i)
				{
					for(long long k=1;k<=i;k++)
					{
						f[i][j]+=qpow(i-1,i-k)%mod*f[k][j-i+1]%mod*C(i,k)%mod;
						f[i][j]%=mod;
					}
				}
				if(j<i)
				{
					f[i][j]+=(qpow(j,i)-qpow(j-1,i)+mod)%mod;
				}
	//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
		for(long long i=1;i<=x;i++)
		{
			ans+=f[n][i];
			ans%=mod;
		}
		cout<<ans;
}
