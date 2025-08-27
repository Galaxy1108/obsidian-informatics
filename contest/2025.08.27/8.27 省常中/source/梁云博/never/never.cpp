#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;//x+y为循环节大小 
	while(t--)
	{
		int n,s,t,x,y;
		cin>>n>>s>>t>>x>>y;
		if(x<=100 && y<=100 && abs(s)<=100 && abs(t)<=100)
		{
			n%=x+y;
			int cnt=0;
			while(cnt<n)
			{
				cnt++;
				if(s>=t)s-=x;
				else s+=y;
			}
			cout<<s<<"\n";
		}
		else if(x==y) 
		{
			if(s<t)
			{
				int step=((t-s)+x-1)/x;
				if(step>=n)cout<<s+x*n<<"\n";
				else 
				{
					s+=step*x;
					if(step%2==1)cout<<((n%2==1)?s:s-x)<<"\n";
					else cout<<((n%2==0)?s:s-x)<<"\n";
				}
			}
			else 
			{
				int step=((s-t)+x-1)/x;
				if(step>=n)cout<<s-x*n<<"\n";
				else
				{
					s-=step*x;
					if(step%2==1)cout<<((n%2==1)?s:s+x)<<"\n";
					else cout<<((n%2==0)?s:s-x)<<"\n";
				}
			}cout<<((n&1==1)?s-x:s)<<"\n";
		}
		
	}
	return 0;
} 
