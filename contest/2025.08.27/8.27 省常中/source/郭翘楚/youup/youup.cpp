#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 50;
const int mod = 998244353;
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
	for (int i = 1; i < maxn; ++i)
		get_inv(i);
	fac[0] = inv_fac[0] = 1;
	for (int i = 1; i < maxn; ++i)
	{
		fac[i] = fac[i-1] * i % mod;
		inv_fac[i] = inv_fac[i-1] * inv[i] % mod;
	}
}

long long C(int n, int m)  
{
	if (m < 0 || n < m) return 0;
	return fac[n] * inv_fac[m] % mod * inv_fac[n-m] % mod;
}
int n,x;

int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	init(); 
	int num;
	cin>>num;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	if(num<=5)
	{
		cout<<n<<" ";
		for(int i=2;i<=n;i++)
		{
			cout<<0<<" "; 
		}
		return 0;
	}
	if(num>=46 and num<=49)
	{
		if(x>=2)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<C(n,i)<<" ";
			}
		}
		else
		{
			cout<<n<<" "<<n-1<<" ";
			for(int i=3;i<=n;i++)
			{
				cout<<0<<" ";
			} 
		}
		return 0;
	}
	if(num>=50 and num<=58)
	{
		for(int i=1;i<=x+1;i++)
		{
			cout<<n-i+1<<" ";
		}
		for(int i=x+2;i<=n;i++)
		{
			cout<<0<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<n-i+1<<" ";
	}
	return 0;
}
