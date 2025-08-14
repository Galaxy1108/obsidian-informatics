#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
constexpr int N=1e6+5;
int T;
int n,mod;
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
vector<int>pr;
bitset<N>vis;
int mu[N];
int f[N],h[N],inv[N];
int ans;
void init()
{
	mu[1]=f[1]=inv[1]=1;
	for(int i=2;i<=N-5;i++)
	{
		if(!vis[i])
			mu[i]=-1,pr.pb(i);
		for(auto j:pr)
		{
			if(j*i>N-5)
				break;
			vis[i*j]=1;
			if(i%j==0)
			{
				mu[i*j]=0;
				break;
			}
			mu[i*j]=-mu[i];
		}
	}
} 
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	init();
	while(T--)
	{
		cin>>n>>mod;
		ans=0;
		for(int i=2;i<=n;i++)
			f[i]=(2ll*f[i-1]%mod+f[i-2])%mod,inv[i]=qpow(f[i],mod-2);
		for(int i=0;i<=n;i++)
			h[i]=1;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j+=i)
				if(mu[j/i])
					if(~mu[j/i])
						h[j]=1ll*h[j]*f[i]%mod;
					else
						h[j]=1ll*h[j]*inv[i]%mod;
		for(int i=1,g=1;i<=n;i++)
			g=1ll*g*h[i]%mod,ans=(ans+1ll*i*g%mod)%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
