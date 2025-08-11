#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
const int mod=1e9+7;
#define ll long long
ll n,k;
ll a[maxn],f[maxn];


int main(){
	freopen("beetle.in","r",stdin);
//	freopen("beetle.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	ll ma=a[1];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=k;i++){
		ma=max(ma,a[i]);
		f[i]=ma;
	}
	for(int i=k+1;i<=n;i++){
		ma=a[i];
		for(int j=i;j>=i-k+1;j--){
			ma=max(ma,a[j]);
			f[i]=min(f[i],f[j-1]+ma);
		}
	}
	ll tmp=1;ll ans=0;
//	for(int i=1;i<=n;i++)printf("%lld ",f[i]);
	for(int i=n;i>=1;i--){
		ans+=f[i]*tmp;ans%=mod;
		tmp*=23;tmp%=mod;
	}
	printf("%lld",ans);
	return 0;
}
