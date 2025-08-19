#include <cstring>
#include <iostream>
#include <algorithm>
#define lowbit(x) (-x&x)
using namespace std;
typedef long long ll;
const int N=500001;
int n,h[N],a[N],p[N];
ll ans,s[N],dp[N],t1[N],t2[N];
void update(ll* t,int i,ll x)
{
	while(i<=n+1) t[i]=min(t[i],x),i+=lowbit(i);
}
ll query(ll* t,int i)
{
	ll ans=t[i];
	while(i) ans=min(ans,t[i]),i-=lowbit(i);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]),a[i]=h[i];
		s[i]=s[i-1]+abs(h[i]-h[i-1]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=lower_bound(a+1,a+n+1,h[i])-a+1;
	memset(t1,0x3f,sizeof(t1));
	memset(t2,0x3f,sizeof(t2));
	update(t1,1,0);update(t2,n+1,0);
	dp[1]=h[1],ans=s[n];
	for(int i=2;i<=n;i++)
	{
		dp[i]=s[i-1]+min(query(t1,p[i])+h[i],query(t2,n+2-p[i])-h[i]);
		ans=min(ans,dp[i]+s[n]-s[i]);
		update(t1,p[i-1],dp[i]-s[i]-h[i-1]);
		update(t2,n+2-p[i-1],dp[i]-s[i]+h[i-1]);
	}
	printf("%lld\n",ans);
	return 0;
}