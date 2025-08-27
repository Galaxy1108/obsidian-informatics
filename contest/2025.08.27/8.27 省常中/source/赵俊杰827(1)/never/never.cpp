#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ll n,s,t,x,y;
		cin>>n>>s>>t>>x>>y;
		if(x==y)
		{
			if(s<t)
			{
				if(n<=(t-s+x-1)/x)
				{
					cout<<s+n*x<<'\n';
					continue;
				}
				ll p=s+(t-s+x-1)/x*x;
				if((n-(t-s+x-1)/x)&1)cout<<p-x<<'\n';
				else cout<<p<<'\n';
			}
			else
			{
				if(n<=(s-t+x-1)/x)
				{
					cout<<s-n*x<<'\n';
					continue;
				}
				ll p=s-(s-t+x-1)/x*x;
				if((n-(s-t+x-1)/x)&1)cout<<p+x<<'\n';
				else cout<<p<<'\n';
			}
		}
		else
		{
			unordered_map<ll,int>vis;
			ll cnt=0,flag=0;
			while(!vis[s])
			{
				vis[s]=++cnt;
				if(cnt==n+1)
				{
					flag=1;
					cout<<s<<'\n';
					break;
				}
				if(s<t)s+=y;
				else s-=x;
			}
			if(flag)continue;
			n-=vis[s]-1;
			n%=cnt-vis[s]+1;
			while(n--)
			{
				if(s<t)s+=y;
				else s-=x;
			}
			cout<<s<<'\n';
		}
	}
	return 0;
}
