#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,a[200010],opt;
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int j=1;j<=m;j++){
		scanf("%lld",&opt);
		if(opt==1){
			ll v;
			scanf("%lld",&v);
			for(int i=1;i<=n;i++) a[i]=min(a[i],v);
		}
		if(opt==2){
			for(int i=1;i<=n;i++) a[i]=a[i]+i;
		}
		if(opt==3){
			ll l,r,ans;
			scanf("%lld%lld",&l,&r);
			for(int i=l;i<=r;i++) ans+=a[i];
			printf("%lld\n",ans);
		}
	} 
	return 0;
}
