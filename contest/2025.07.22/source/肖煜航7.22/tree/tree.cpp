#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=998244353;
ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
} 
const int N=5005;
ll inv[N];
int n,l[N],r[N];
ll f[N][N];
ll ans[N]; 
void add(int x1,int y1,int x2,int y2,ll v){
	if(x1>x2) return;
	if(y1>y2) return;
	f[x2][y2]=(f[x2][y2]+v)%mod;
	f[x1-1][y1-1]=(f[x1-1][y1-1]+v)%mod;
	f[x1-1][y2]=((f[x1-1][y2]-v)%mod+mod)%mod;
	f[x2][y1-1]=((f[x2][y1-1]-v)%mod+mod)%mod; 
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=qpow(i,mod-2);
	for(int i=2;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	int m;scanf("%d",&m);
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) swap(x,y);
		if(x==y) continue;
		add(x,y,x,y,z);
	}
	for(int i=n;i;i--){
		for(int j=n;j>=i;j--){
			f[i][j]=(f[i][j]+f[i+1][j])%mod;
			f[i][j]=(f[i][j]+f[i][j+1])%mod;
			f[i][j]=((f[i][j]-f[i+1][j+1])%mod+mod)%mod;
			if(i<j){//j点向上走 
				ll w=f[i][j]*inv[r[j]-l[j]+1]%mod;
				add(i,max(i+1,l[j]),i,r[j],w);
				add(l[j],i,min(i-1,r[j]),i,w);
				ans[j]=(ans[j]+f[i][j])%mod;
			}
		}
	}
	for(int i=2;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}
