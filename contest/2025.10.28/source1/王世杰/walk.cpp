#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005];
int hzh[200005];
int h0[200005];
ll n;
ll dp[200005];
ll ans;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n;
	ans=n*n;
	int st=1,ed=n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	while(a[st]==0)
	{
		st++;
	}
	while(a[ed]==0)
	{
		ed--;
	}
	for(int i=n;i>=1;i--)
	{
		hzh[i]=hzh[i+1]+(a[i]+1)%2-(int)(a[i]==0);
		h0[i]=h0[i+1]+(int)(a[i]==0&&i>=st&&i<=ed);
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=h0[i]-h0[i+1];
		dp[i]=min((ll)(hzh[1]-hzh[i]+h0[1]-h0[i]+hzh[i+1]+h0[i+1]),(ll)(i-1-(hzh[1]-hzh[i])+2*(h0[1]-h0[i])+(n-i)-(hzh[i+1])+2*h0[i+1]));
		dp[i]=min(dp[i],(ll)(hzh[i+1]+h0[i+1]+i-1-(hzh[1]-hzh[i])+2*(h0[1]-h0[i])));
		dp[i]=min(dp[i],(ll)(hzh[1]-hzh[i]+h0[1]-h0[i]+(n-i)-(hzh[i+1])+2*h0[i+1]));
		ans=min(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
