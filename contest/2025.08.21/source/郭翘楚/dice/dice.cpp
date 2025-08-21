#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll m=1e9+7;
long long binpow(long long a, long long b) {
  long long res = 1;
  a=(a%m+m)%m;
  b=(b%m+m)%m;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res%m;
}
ll a[5005];
ll p[1000005];
ll p1[1000005];
ll sum[1000005];
ll t[1000005];
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ll n;
	cin>>n;
	p[0]=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(ll i=a[n];i>=1;i--) 
	{
		p1[i]=(p1[i+1]+t[i])%m;
	}
	for(ll i=1;i<=a[n];i++)
	{
		p[i]=p[i-1]*binpow(i,t[i]);
		p[i]%=m;
	}
	ll y=binpow(p[a[n]],m-2)%m;
	sum[1]=1;
	for(ll i=2;i<=a[n];i++)
	{
		sum[i]=p[i-1]*(binpow(i,p1[i])%m-binpow(i-1,p1[i]%m));
		sum[i]%=m;
	}
	ll ans=0;
	for(ll i=1;i<=a[n];i++)
	{
		ans+=sum[i]%m*i;
		ans%=m;
	}
	cout<<ans*y%m;
	return 0;
 } 
