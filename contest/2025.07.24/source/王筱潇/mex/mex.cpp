#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,a[5010],cnt=0,ans=1;
ll kpow(int x,int y){
	if(y==1) return x;
	ll tmp=kpow(x,y/2);
	tmp=tmp*tmp%mod;
	if(y%2==1) tmp=tmp*x%mod;
	return tmp;
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0) cnt++;
	}
	ans=kpow(m,cnt);
	printf("%lld",ans)%mod;
	return 0;
} 
