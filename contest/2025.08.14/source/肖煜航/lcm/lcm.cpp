#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
int n,T;
vector<int> e[N];
ll mod;
ll f[N],g[N];
ll mu[N],inv[N];
int pri[N],tot;
bool vis[N];
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
} 
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	mu[1]=1;
	vis[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!vis[i]){
			pri[++tot]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=tot&&i*pri[j]<=1000000;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<=1000000;i++) for(int j=i;j<=1000000;j+=i) e[j].push_back(i);
	T=read();
	while(T--){
		n=read(),mod=read(); 
		f[1]=1;
		for(int i=2;i<=n;i++) f[i]=(2ll*f[i-1]%mod+f[i-2])%mod;
		for(int i=1;i<=n;i++) inv[i]=qpow(f[i],mod-2);
		ll ans=0;
		for(int i=1;i<=n;i++){
			g[i]=1;
			for(int j:e[i]){
				if(mu[i/j]==-1) g[i]=g[i]*inv[j]%mod;
				if(mu[i/j]==1) g[i]=g[i]*f[j]%mod;
			}
		}
		ll lst=1;
		for(int i=1;i<=n;i++){
			ans=(ans+1ll*lst*g[i]%mod*i%mod)%mod;
			lst=lst*g[i]%mod;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
} 
