#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod;
ll f[55]={1,1,2,9,96,2500,162000,26471025,11014635520,1159522374656,32406091200000000};
ll g[55];
int a[200005];
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
ll ys(ll N)
{
	memset(a,0,sizeof(a));
	ll cnt=2;
	ll n=N;
	while(n>1)
	{
		while(n%cnt==0)
		{
			a[cnt]++;
			n/=cnt;
		}
		cnt++;
	}
	ll ans=1;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]!=0)
		{
			ans*=(binpow(i,a[i]+1,mod)-1ll)/(i-1ll);
			ans%=mod;
		}
	}
	return ans%mod;
}
void solve(int n)
{
	for(int i=1;i<=n;i++)
	{
		g[i]=ys(f[i])%mod;
		cout<<g[i]<<","<<endl;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=g[i];
		ans%=mod;
	}
	cout<<ans%mod<<endl;
	return;
}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	int n;
	cin>>n>>mod;
	solve(n);
	return 0;
} 
