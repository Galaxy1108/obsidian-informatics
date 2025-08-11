#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int b[1000005],tot;
bool vis[1000005];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int T;scanf("%d",&T);
	if(T==1){
		ll s,k;
		scanf("%lld%lld",&s,&k);
		if(s%2==1){
			if(s&1){
				ll o=2ll*k;
				if(o<=s) printf("%lld\n",o);
				else puts("-1");
			}
			return 0;
		}
		for(int i=3;i<s;i++){
			if(s%i==0) continue;
			bool flag=0;
			for(int j=i;j<=s;j+=i){
				if(vis[s-j]){
					flag=1;
					break;
				}
			}
			if(flag) continue;
			b[++tot]=i;
			for(int j=i;j<=1000000;j+=i) vis[j]=1;
		}
		if(k<=tot) printf("%d",b[k]);
		else printf("%d",-1);
		return 0;
	} 
	while(T--){
		ll s,k;
		scanf("%lld%lld",&s,&k);
		if(s&1){
			ll o=2ll*k;
			if(o<=s) printf("%lld\n",o);
			else puts("-1");
		}
		else puts("-1");
	}
	return 0;
} 
