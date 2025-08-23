#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,q,Num,a[200010],dp[200010],to=1,maxn=1,sum;
ll kpow(ll x,ll y){
	if(y==1) return x;
	ll tmp=kpow(x,y/2);
	tmp=(tmp*tmp)%mod;
	if(y%2) tmp=(tmp*2)%mod;
	return tmp;
}
int main(){
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout); 
	scanf("%lld",&Num);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dp[1]=2;
	sum=maxn=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<=maxn) dp[i]=dp[i-1];
		else{
			if(sum<a[i]) dp[i]=kpow(2,i);
			else{
				int flag=a[i],asn=0,fg=0;
				while(flag>0){
					fg++;
					flag-=a[fg];
					asn=(asn+kpow(2,fg))%mod;
				}
				for(int j=fg-1;j>=1&&flag<0;j--){
					if(flag+a[j]<=0){
						asn=(asn-kpow(2,j)+mod)%mod;
						flag+=a[j];
					}
				}
				dp[i]=asn%mod;
			}
			maxn=a[i];
		}
		sum+=a[i];
	}
	printf("%d\n",dp[n]);
	scanf("%lld",&q);
	while(q--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		a[x]=y;
		sum=maxn=0;
		for(int i=1;i<=x-1;i++){
			sum=sum+a[i];
			maxn=max(maxn,a[i]);
		}
		for(int i=x;i<=n;i++){
			if(a[i]<=maxn) dp[i]=dp[i-1];
			else{
				if(sum<a[i]) dp[i]=kpow(2,i);
				else{
					int flag=a[i],asn=0,fg=0;
					while(flag>0){
						fg++;
						flag-=a[fg];
						asn=(asn+kpow(2,fg))%mod;
					}
					for(int j=fg-1;j>=1&&flag<0;j--){
						if(flag+a[j]<=0){
							asn=(asn-kpow(2,j)+mod)%mod;
							flag+=a[j];
						}
					}
					dp[i]=asn%mod;
				}
				maxn=a[i];
			}
			sum+=a[i];
		}
		printf("%d\n",dp[n]);
	}
}
