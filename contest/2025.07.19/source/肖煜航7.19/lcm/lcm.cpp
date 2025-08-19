#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=1e6+5;
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int n,k;
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
ll ans=1;
ll a[N],fact[N];
ll phi[N];
int pri[N],tot;
bool vis[N];
ll lcm(ll x,ll y){
	ll gc=gcd(x,y);
	return x*y/gc;
}
void dfs(int x){
	if(x==k+1){
		ll lc=1;
		for(int i=1;i<=k;i++) lc=lcm(lc,a[i]);
		ans=(ans*lc)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	phi[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!vis[i]) pri[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*pri[j]<=1000000;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	for(int i=2;i<=1000000;i++) phi[i]=(phi[i-1]+phi[i])%mod;
	fact[0]=1;
	for(int i=1;i<=1000000;i++) fact[i]=1ll*fact[i-1]*i%mod;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(k==1){
			printf("%lld\n",fact[n]);
			continue;
		}
		ans=1;
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
} 
