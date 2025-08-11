#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
const int MOD=1000000007;
struct T
{
	int h,w,l,x;
}c[N];
int h[N],w[N];
int mypow(int a,int b)
{
	if(b==0)return 1;
	int mi=mypow(a,b>>1);
	mi=mi*mi%MOD;
	if(b&1)mi=mi*a%MOD;
	return mi;
}
int C(int x)
{
	x%=MOD;
	return x*(x-1)%MOD*mypow(2,MOD-2)%MOD;
}
signed main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,top=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int t=w[i];
		ans+=C(h[i]+1)*C(w[i]+1)%MOD;
		while(top&&c[top].h>=h[i])w[i]=(w[i]+c[top].w)%MOD,top--;
		c[++top]={h[i],w[i],sum,0};
		c[top].x=(c[top-1].x+C(h[i]+1)*w[i]%MOD)%MOD;
		ans+=C(h[i]+1)*(w[i]-t)%MOD;
		ans+=c[top-1].x*t%MOD;
		ans%=MOD;
		sum+=w[i];
		sum%=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}
