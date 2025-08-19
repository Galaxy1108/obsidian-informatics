#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
using namespace std;
constexpr int N=1e6+5,mod=998244353;
int T;
int n,k;
int fs[N];
int ans;
vector<int>pr;
bitset<N>vis;
int phi[N];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return res;
}
void init()
{
	fs[0]=1;
	for(int i=1;i<=N-5;i++)
		fs[i]=fs[i-1]*i%mod;
	phi[1]=1;
	for(int i=2;i<=N-5;i++)
	{
		if(!vis[i])
			pr.pb(i),phi[i]=i-1;
		for(auto v:pr)
		{
			if(v*i>N-5)
				break;
			vis[v*i]=1;
			if(i%v==0)
			{
				phi[v*i]=phi[i]*v;
				break;
			}
			phi[v*i]=phi[i]*(v-1);
		}
	}
	for(int i=2;i<=N-5;i++)
		phi[i]+=phi[i-1];
}
void calc(int x,int sum)
{
	if(x>k)
	{
		ans=ans*sum%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		calc(x+1,(i*sum/__gcd(i,sum))%mod);
}
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	init();
	while(T--)
	{
		cin>>n>>k;
		ans=1;
		if(n<=10 && k<=5)
		{
			calc(1,1);
			cout<<ans<<'\n';
			continue;
		}
		if(k==1)
		{
			cout<<fs[n]<<'\n';
			continue;
		}
		if(k==2)
		{
			ans=qpow(fs[n],n*2)%mod;
			for(int d=1;d<=n;d++)
				ans=ans*qpow(qpow(d,phi[n/d]),mod-2)%mod;
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
