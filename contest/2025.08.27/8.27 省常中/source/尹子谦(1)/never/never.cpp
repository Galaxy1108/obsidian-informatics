#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	set<int> st;
	int n,s,t,x,y;
	cin>>n>>s>>t>>x>>y;
	int nn=n;
	if(n<=1e18)
	{
		while(n)
		{
			if(s>t)
			{
				int mv=ceil(1.0*(s-t)/x);
				if(mv<=n)s=s-mv*x,n=n-mv;
				else s=s-n*x,n=0;
			}
			else if(s==t) s-=x,n--;
			else
			{
				int mv=ceil(1.0*(t-s)/y);
				if(mv<=n) s=s+mv*y,n=n-mv;
				else s=s+n*y,n=0;
			}
		}
		cout<<s<<endl;
		return ;
	}
}
signed main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdin);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
} 
