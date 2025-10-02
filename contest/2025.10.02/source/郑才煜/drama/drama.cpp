#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e6+3;
ll a[N];
inline ll read()
{
	ll sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
ll maxx(ll a,ll b)
{
	return a>b?a:b;
}
ll minn(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ll n=read(),i,j,ans=0;
	for(i=1;i<=n;++i) a[i]=read();
	if(n<=1000)
	{
		for(i=1;i<=n;++i)
		{
			ll ax,in;
			ax=in=a[i];
			for(j=i;j<=n;++j)
			{
				ax=maxx(ax,a[j]);
				in=minn(in,a[j]);
				ans=maxx(ans,ax*in*(j-i+1)); 
			}
		}
	}
	else
	{
		ll lx,ln,lsum,lans;
		lx=ln=a[1];
		lsum=1;
		lans=a[1]*a[1];
		for(i=2;i<=n;++i)
		{
			if(minn(ln,a[i])*maxx(lx,a[i])*(lsum+1)>a[i]*a[i])
			{
				ln=minn(ln,a[i]);
				lx=maxx(lx,a[i]);
				++lsum;
				ans=maxx(ans,ln*lx*lsum);
			}
			else
			{
				ans=max(ans,a[i]*a[i]);
				ln=lx=a[i];
				lsum=1;
			}
		}
	}
	cout<<ans;
}
