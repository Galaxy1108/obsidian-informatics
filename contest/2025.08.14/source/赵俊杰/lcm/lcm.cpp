#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
ll b[N],c[N],f[N],ans,MOD;
void run(ll a)
{
	ll x=a;
	for(unsigned long long i=2;i*i<=x;i++)
	{
		if(a%i)continue;
		ll cnt=0;
		//cout<<i;
		while(a%i==0)
		{
			a/=i;
			cnt++;
		}
		if(i<=1000000&&cnt>c[i])
		{
			for(int j=c[i]+1;j<=cnt;j++)ans=ans*i%MOD;
			c[i]=cnt;
		}
		//cout<<"^"<<cnt<<"*";
	}
	if(a>1)
	{
		//cout<<a<<"^1";
		if(a<=1000000&&!c[a])
		{
			c[a]=1;
			ans=ans*a%MOD;
		}
	}
	//cout<<'\n';
}
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n>>MOD;
		b[1]=1;
		memset(c,0,sizeof(c));
		ans=1;
		ll sum=1;
		for(int i=2;i<=n;i++)
		{
			b[i]=2*b[i-1]+b[i-2];
			run(b[i]);
			sum=(sum+ans*i)%MOD;
			//cout<<b[i]<<' '<<ans<<'\n';
		}
		cout<<sum<<'\n';
	}
	return 0;
}
/*
1+1
3+2
17+12
577+204
*/
