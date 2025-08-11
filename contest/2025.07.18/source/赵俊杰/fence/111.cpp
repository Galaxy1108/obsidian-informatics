#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
const int MOD=1000000007;
struct T
{
	int h,w,l;
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
	freopen("fence4.in","r",stdin);
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
		ans+=C(h[i]+1)%MOD*C(w[i]+1)%MOD;
		while(top&&c[top].h>=h[i])w[i]+=c[top].w%MOD,top--;
		w[i]%=MOD;
		c[++top]={h[i]%MOD,w[i]%MOD,sum%MOD};
		ans+=C(h[i]+1)%MOD*(w[i]-t)%MOD;
		for(int j=top-1;j>=1;j--)
			ans+=C(c[j].h+1)%MOD*c[j].w%MOD*t%MOD;
		sum+=w[i]%MOD;ans%=MOD;
		sum%=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}
