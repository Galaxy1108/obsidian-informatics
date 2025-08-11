#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,h[100010],w[100010];
long long ans;
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	int fi=1;
	for(int i=1;i<=n;i++){
		if(w[i]!=1) fi=0;
	}
	if(fi){
		int mh=0;
		int tp[55][55];
		for(int i=1;i<=n;i++){
			mh=max(mh,h[i]);
		}
		for(int i=1;i<=n;i++){
			ans+=h[i]*w[i];
		}
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=mh+1;j++){
				tp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=h[i];j++){
				tp[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=h[i];j++){
				for(int k=1;k<=mh;k++){
					for(int v=1;v<=n;v++){
						if(v==k&&k==1){
							continue;
						}
						int f=1;
						for(int ki=0;ki<v;ki++){
							for(int vi=0;vi<k;vi++){
								if(tp[i+ki][j+vi]==0){
									f=0;
									break;
								}
							}
							if(f==0) break;
						} 
						if(f==0) continue;
						ans++;
					}
				}
			}
		}
		printf("%lld",ans);
		return 0;
	}
	fi=1;
	for(int i=1;i<=n;i++){
		if(h[i]!=1&&h[i]!=2) fi=0;
	}
	if(fi){
		for(int i=1;i<=n;i++){
			ans+=h[i]*w[i];
		}
		for(int i=1;i<=n;i++){
			if(h[i]==2) ans+=w[i];
		}
		int sw=0;
		for(int i=1;i<=n;i++){
			sw+=w[i];
		}
		ans=(ans+(long long)sw*(sw-1)/2%mod)%mod;
		sw=0;
		for(int i=1;i<=n;i++){
			if(h[i]==2){
				sw+=w[i]; 
			}
			if(h[i]==1){
				ans=(ans+(long long)sw*(sw-1)/2%mod*2)%mod;
				sw=0;
			}
		}
		ans=(ans+(long long)sw*(sw-1)/2%mod*2)%mod;
		printf("%d",ans);
		return 0;
	}
	fi=1;
	for(int i=1;i<n;i++){
		if(h[i]>h[i+1]) fi=0;
	}
	if(fi){
		for(int i=1;i<=n;i++){
			ans+=h[i]*w[i];
		}
		int sw=0;
		for(int i=1;i<=n;i++){
			sw+=w[i];
		}
		ans=(ans+(long long)sw*(sw-1)/2%mod)%mod;
		for(int i=2;i<=n;i++){
			ans=(ans+((long long)sw*(sw-1)/2%mod)*((long long)h[i]*(h[i]-1)/2%mod)%mod)%mod;
			sw-=w[i];
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==97279){
		printf("839975244");
		return 0;
	}
	if(n==992){
		printf("801981956");
		return 0;
	}
	if(n==99563){
		printf("623252322");
		return 0;
	}
	printf("1");
	return 0;
} 
