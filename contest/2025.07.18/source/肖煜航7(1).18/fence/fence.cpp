#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inv2=500000004;
const int N=1e5+5;
int n;
ll h[N],w[N],s[N];
pair<ll,ll> st[N];
int top,tot;
ll ans;
pair<ll,ll> a[N];
ll get(ll x){
	x=(x%mod+mod)%mod;
	return x;
}
void solve(){
	if(!tot) return;
	reverse(a+1,a+tot+1);
	for(int i=tot;i;i--){
		ll len=a[tot].second-a[i-1].second;
		len%=mod;
		ll op=len*(len+1)%mod*inv2%mod;
		ll po=1ll*get(a[i].first+a[i-1].first+1)*get(a[i].first-a[i-1].first)%mod*inv2%mod;
		ans=(ans+op*po%mod)%mod;
	}	
}
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+w[i];
	st[++top]={0,0};
	for(int i=1;i<=n;i++){
		tot=0;
		while(top&&st[top].first>=h[i]){
			a[++tot]=st[top];
			top--;
		}
		a[0]={h[i],st[top].second};
		st[++top]={h[i],s[i]};
		solve();
	}
	tot=0;
	while(top>1) a[++tot]=st[top],top--;
	a[0]={0,0};
	solve();
	ans=(ans%mod+mod)%mod;
	printf("%lld",ans); 
	return 0;
} 
