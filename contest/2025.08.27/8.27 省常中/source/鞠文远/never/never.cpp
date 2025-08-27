#include<bits/stdc++.h>
#define int long long
using namespace std;
int T; 
signed main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		int n,s,t,x,y;
		cin>>n>>s>>t>>x>>y;
		if(x==y&&n>1000000)
		{
			if(s>=t)
			{
				int st=(s-t)/x;
				if(n<=st)cout<<s-n*x<<"\n";
				else
				{
					s-=st*x;
					n-=st;
					n%=2;
					if(n==1)s-=x;
					cout<<s<<"\n";
				}
			}
			else
			{
				int st=(t-s)/y;
				if(n<=st)cout<<s+n*y<<"\n";
				else
				{
					s+=st*y;
					n-=st;
					n%=2;
					if(n==1)s+=y;
					cout<<s<<"\n";
				}
			}
			continue;
		}
		while(n--)
		{
			if(s>=t)s-=x;
			else s+=y;
		}
		cout<<s<<"\n";
	}
	
	return 0;
} 
