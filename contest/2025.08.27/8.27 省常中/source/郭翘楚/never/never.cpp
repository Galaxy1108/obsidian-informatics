#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		ll n,s,t,x,y;
		cin>>n>>s>>t>>x>>y;
		ll k;
		while(n>0)
		{
			if(s<t)
			{
				k=1;
				while(s+2*k*y<t and n-2*k>=0)
				{
					k*=2;
				}
				s+=k*y;
				n-=k;
			}
			else
			{
				k=1;
				while(s-2*k*x>=t and n-2*k>=0)
				{
					k*=2;
				}
				s-=k*x;
				n-=k;
			}
		}
		cout<<s<<endl;
	}
	return 0;
 } 
