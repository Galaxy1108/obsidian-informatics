#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	vector<ll> a(n+1);
	ll max_a=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		max_a=max(max_a,a[i]);
	}
	ll ans=0;
	ll x=1;
	while(x<=max_a){
		vector<ll> t(n+1);
		ll T=0;
		for(int i=1;i<=n;i++){
			t[i]=a[i]/x;
			T^=t[i];
		}
		ll next_x=max_a+1;
		for(int i=1;i<=n;i++){
			if(t[i]>0){
				next_x=min(next_x,a[i]/t[i]+1);
			}
		}
		for(int i=1;i<=n;i++){
			if(T==(t[i]^(t[i]-1))){
				int l=x,r=min(next_x-1,a[i]);
				if(l<=r) ans+=(r-l+1);
			}
		}
		x=next_x;
	}
	printf("%lld",ans);
	return 0;
}
