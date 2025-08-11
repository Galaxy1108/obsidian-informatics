#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=1e9+7;
ll a[1010][1010],n,k,s[1010];
ll cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int xi=i,xj=j,fi=1,fj=1;
			while(xi){
				fi*=xi%10;
				xi/=10;
			}	
			while(xj){
				fj*=xj%10;
				xj/=10;
			}
			a[fi][fj]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]>s[k+1]){
				s[k+1]=a[i][j];
				sort(s+1,s+k+2,cmp);
			} 
		}
	}
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans=(ans+s[i])%mod;
	}
	ans=ans%mod;
	printf("%lld",ans);
	return 0;
}
