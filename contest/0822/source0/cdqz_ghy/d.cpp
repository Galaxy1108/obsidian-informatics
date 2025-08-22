#include<bits/stdc++.h>
#define ll long long
#define INF 214748364719260817ll
using namespace std;
ll t,n,q;
ll x[100005];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=1;i<=n;++i)cin>>x[i];
		ll l,r;
		bool ok=1;
		if(n!=1)
		{
		ll a=(x[n]-x[1])/(n-1);
		ll b=x[1];
		for(ll i=1;i<=n;++i)
			if(a*(i-1)+b!=x[i])
			{
				ok=0;break;
			}
		}
		else ok=0;
		cin>>q;
		while(q--)
		{
			cin>>l>>r;
			if(l==r)
			{
				cout<<"0 "<<l<<' '<<1<<'\n';continue;
			}
			else if(ok||r-l+1>=21)
			{
				ll a=(x[r]-x[l])/(r-l);
				ll b=x[l];
				cout<<a<<' '<<b<<' '<<1<<'\n';
				continue;
			}
			else
			{
				ll a=(x[r]-x[l])/(r-l);
				ll b=x[l];
				bool ok=1;
				for(ll i=l;i<=r;++i)
				if((i-l)*a+b!=x[i])
				{
					ok=0;break;
				}
				if(ok)
				{
					cout<<a<<' '<<b<<' '<<1<<'\n';continue;
				}
				ll ov=1;
				for(ll c=1;c&&ov;++c)
					for(ll a=(x[r]-x[l])/(r-l)*c;ov&&a<=(c<=10?10:2147483647)&&a*(r-l)/c<=x[r];++a)
						for(ll b=x[l]*c;b<=(c<=10?10:2147483647)&&ov&&(a*(r-l)+b)/c<=x[r];++b)
						{
							bool ok=1,ck=1;
							for(ll i=l;i<=r;++i)
							{
								if((a*(i-l)+b)/c!=x[i])
								{
									if((a*(i-l)+b)/c>x[i])ck=0;
									ok=0;break;
								}
							}
							if(ok)
							{
								cout<<a<<' '<<b<<' '<<c<<'\n';ov=0;break;
							}
							if(!ck)break;
						}	
			}
		}
	}
}
