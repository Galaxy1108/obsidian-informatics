#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans[1000];
int a,b,dep;
void dfs(int stp,ll x,ll y)
{
	if(stp>dep)return ;
	if(stp==dep-1)
	{
    	int minK=ceil(sqrt(4*y/(x*x)));
		for(ll k=minK;;k++){
			ll delta=x*x*k*k-4*y*k;
			ll t=sqrt(delta),gd=-1;
			if(t*t==delta)gd=t;
			else if((t-1)*(t-1)==delta)gd=t-1;
			else if((t+1)*(t+1)==delta)gd=t+1;
			ll nx=(x*k-gd)/2;
			ll ny=(x*k+gd)/2;
			if(ny>1e7) break;
			if(gd<=0||(x*k-gd)%2!=0)continue;
			cout<<dep<<endl;
			for(ll i=1;i<dep-1;i++)cout<<ans[i]<<' ';
			cout<<nx<<' '<<ny;
			exit(0);
		}
		return;
	}
	ll l=max(ans[stp-1]+1ll,y/x+1ll);
	ll r=(dep-stp+1ll)*y/x;
	for(int i=l;i<r;i++)
	{
		ll nx=x*i-y,ny=y*i;
		ll gcd=__gcd(nx,ny);
		nx/=gcd,ny/=gcd;
		ans[stp]=i;
		dfs(stp+1,nx,ny);
	}
}
signed main() 
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>a>>b;
	int gcd=__gcd(a,b);
	a/=gcd,b/=gcd;
	for(dep=1;dep<=10;dep++)
	{
		dfs(1,a,b);
	}
	return 0;
}
