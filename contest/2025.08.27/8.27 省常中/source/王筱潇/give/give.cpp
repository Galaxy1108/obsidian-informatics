#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,m,s,n,a[40],f[40],cnt,ans,sum;
void dfs(ll x){
	if(x==m){
		if(s==sum) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		dfs(x+1);
		sum-=a[i];
	}
}
int main(){
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&m,&s,&n);
		if(m<=9){
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			dfs(0);
			printf("%lld\n",ans%2);
		}
		else printf("%lld\n",n%2);	
	}
	return 0;
}
