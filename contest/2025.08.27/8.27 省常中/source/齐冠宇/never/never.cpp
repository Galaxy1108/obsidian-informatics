#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,s,t,x,y,ans;
int f[405][32];
void solve()
{
	if(abs(x)<=100 && abs(y)<=100 && abs(s)<=100 && abs(t)<=100)
	{
		for(int i=0;i<=400;i++)
		{
			int pos=i-200;
			if(pos<t)
				f[i][0]=i+y;
			else
				f[i][0]=i-x;
		}
		for(int j=1;j<=30;j++)
			for(int i=0;i<=400;i++)
				f[i][j]=f[f[i][j-1]][j-1];
		s+=200;
		for(int j=30;~j;j--)
			if(n&(1<<j))
				s=f[s][j];
		for(int j=0;j<=30;j++)
			for(int i=0;i<=400;i++)
				f[i][j]=0;
		return void(ans=s-200);
	}
//	if(s==t)
//	{
//		ans=-1;
//	}
	if(x>=y)
	{
		if(x%y==0)
		{
			if(s<=t)
			{
				int cnt=ceil(1.0*(t-s)/y);
				if(n<=cnt)
					return void(ans=s+n*y);
				int ns=s+cnt*y;
				if((n-cnt)%(1+(x/y))==1)
					return void(ans=ns-x);
				else
					return void(ans=ns-x+y*(n-cnt)%(1+(x/y)));
			}
			else
			{
				int cnt=(s-t)/x;
				if(n<=cnt)
					return void(ans=s-n*x);
				int ns=s-cnt*x;
				if((n-cnt)%(1+(x/y))==1)
					return void(ans=ns-x);
				else
					return void(ans=ns-x+y*(n-cnt)%(1+(x/y)));
			}
		}
		else
		{
			ans=-1;
		}
	}
	else
	{
		if(y%x==0)
		{
			if(s<=t)
			{
				int cnt=(t-s)/y-((t-s)%y==0);
				if(n<=cnt)
					return void(ans=s+n*y);
				int ns=s+cnt*y;
				if((n-cnt)%(1+(y/x))==1)
					return void(ans=ns+y);
				else
					return void(ans=ns+y-x*(n-cnt)%(1+(y/x)));
			}
			else
			{
				int cnt=(s-t)/x+1;
				if(n<=cnt)
					return void(ans=s-n*x);
				int ns=s-cnt*x;
				if((n-cnt)%(1+(y/x))==1)
					return void(ans=ns+y);
				else
					return void(ans=ns+y-x*(n-cnt)%(1+(y/x)));
			}
		}
		else
		{
			ans=-1;
		}
	}
}
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>s>>t>>x>>y;
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
