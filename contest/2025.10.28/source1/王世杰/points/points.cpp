#include<bits/stdc++.h>
#define lol long long
using namespace std;
lol a[200005];
struct xd
{
	int l,r,ln,rn;
}s[200005];
bool cmp(xd a,xd b)
{
	return a.l==b.l ? a.r>=b.r : a.l<b.l;
}
int n,m,cnt,lan;
lol dp[200005][2];
int fidl(int x)
{
	int ll=1,rr=n+1;
	while(ll!=rr)
	{
		int mid=(ll+rr)/2;
		if(a[mid]>=x) rr=mid;
		else ll=mid+1;
	}
	return ll;
}
int fidr(int x)
{
	int ll=0,rr=n;
	while(ll!=rr)
	{
		int mid=(ll+rr)/2+1;
		if(a[mid]>x) rr=mid-1;
		else ll=mid;
	}
	return ll;
}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	a[0]=-2e9-7;a[n+1]=2e9+7;
	int li,ri;
	for(int i=1;i<=m;i++)
	{
		cin>>li>>ri;
		int lsl=fidl(li),lsr=fidr(ri);
		if(lsl>lsr)
		{
			cnt++;
			s[cnt].l=li;
			s[cnt].r=ri;
			s[cnt].ln=lsl-1;
			s[cnt].rn=lsr+1;
		}
	}
	sort(s+1,s+cnt+1,cmp);
	int st=1,mir=a[1];
	while(s[st].rn==1)
	{
		mir=min(mir,s[st].r);
		st++;
	}
	lan=a[1]-mir;
	a[1]=mir;
	for(int i=st;i<=cnt;i++)
	{
		dp[i][0]=min(dp[i-1][1]+(s[i-1].rn==s[i].ln ? s[i].l-s[i-1].r : s[i].l-a[s[i].ln]),dp[i-1][0]+(s[i].ln==s[i-1].ln ? s[i].l-s[i-1].l : s[i].l-a[s[i].ln]));
		dp[i][1]=min(dp[i-1][1]+(s[i-1].rn==s[i].rn ? max(0,s[i-1].r-s[i].r) : a[s[i].rn]-s[i].r),dp[i-1][0]+a[s[i].rn]-s[i].r);
	}
	cout<<min(dp[cnt][0],dp[cnt][1])+lan;
	return 0;
}
