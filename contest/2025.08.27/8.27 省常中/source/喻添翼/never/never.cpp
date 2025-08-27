#include<bits/stdc++.h>
using namespace std;
int T;
long long n,s,t,x,y;
long long cnt;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>s>>t>>x>>y;
		cnt=0;
		if(x!=y)
		{
			while(cnt<n)
			{
				if(s>=t)
				{
					if(cnt+ceil(1.0*(s-t+1)/x)<=n) 
						cnt+=ceil(1.0*(s-t+1)/x),s=s-ceil(1.0*(s-t+1)/x)*x;
					else 
					{
						s-=(n-cnt)*x;
						break;
					}
				}
				else 
				{
					if(cnt+ceil(1.0*(t-s)/y)<=n) 
						cnt+=ceil(1.0*(t-s)/y),s=s+ceil(1.0*(t-s)/y)*y;
					else 
					{
						s+=(n-cnt)*y;
						break;
					}
				}
			}
			cout<<s<<endl;
		}
		else if(x==y)
		{
			if(s>=t)
			{
				if(cnt+ceil(1.0*(s-t+1)/x)<=n) 
				{
					cnt+=ceil(1.0*(s-t+1)/x),s=s-ceil(1.0*(s-t+1)/x)*x;
					if((n-cnt)%2==0) cout<<s<<endl;
					else cout<<s+x<<endl;
				}
				else 
				{
					s-=(n-cnt)*x,cout<<s<<endl;
					continue;
				}
			}
			else 
			{
				if(cnt+ceil(1.0*(t-s)/y)<=n) 
				{
					cnt+=ceil(1.0*(t-s)/y),s=s+ceil(1.0*(t-s)/y)*y;
					if((n-cnt)%2==0) cout<<s<<endl;
					else cout<<s-y<<endl;
				}
				else 
				{
					s+=(n-cnt)*y,cout<<s<<endl;
					continue;
				}
			}
		}
	}
	return 0;
} 
