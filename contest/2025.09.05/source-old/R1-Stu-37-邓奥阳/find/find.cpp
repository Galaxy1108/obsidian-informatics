#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll f(ll x)
{
	ll ans=1;
	while(x)ans*=x%10,x/=10;
	return ans;
}
void add(ll &a,ll b){a+=b;a=a>=mod?a%mod:a;}
ll e[1001][1001];
ll st[1000001];
ll n,ans;int k;
bool cmp(ll a,ll b){return a>b;}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	scanf("%lld%d",&n,&k);
	
	for(int i=1;i<=min(n,1000ll);++i)
		for(int j=1;j<=min(n,1000ll);++j)
			add(e[f(i)][f(j)],1);
	
	for(int i=1;i<=min(n,1000ll);++i)
		for(int j=1;j<=min(n,1000ll);++j)
			st[++st[0]]=e[i][j];
			
	sort(st+1,st+1+st[0],cmp);
	for(int i=1;i<=k;++i)add(ans,st[i]);
	printf("%lld",ans);
	return 0;
}
