#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=505;
struct edge{
	int to,nxt;
}e[N<<1];
int head[N],tot;
void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
}
int n,K;
ll a[N];
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
} 
ll f[205][205][15],tmp[205][15];
void dfs(int u,int fa){
	memset(f[u],-0x3f,sizeof f[u]);
	f[u][0][a[u]]=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		memcpy(tmp,f[u],sizeof tmp);
		memset(f[u],-0x3f,sizeof f[u]);
		for(int j=0;j<=K;j++){
			for(int k=1;k<=10;k++){
				for(int l=0;j+l<=K;l++){
					for(int li=1;li<=10;li++){
						f[u][j+l][gcd(k,li)]=max(f[u][j+l][gcd(k,li)],tmp[j][k]+f[v][l][li]);
						if(j+l<K) f[u][j+l+1][k]=max(f[u][j+l+1][k],tmp[j][k]+f[v][l][li]+li);
					}
				}
			}
		}
	}
}
namespace solve1{
	ll f[N][N];
	void solve(){
		for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=-1e16;
		f[0][0]=0;	
		for(int i=1;i<=n;i++){
			ll op=a[i];
			for(int j=i;j;j--){
				op=gcd(op,a[j]);
				for(int k=0;k<=K+1;k++){
					f[i][k+1]=max(f[i][k+1],f[j-1][k]+op);
				}
			}
		}
		printf("%lld",f[n][K+1]);
	}
}
int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout); 
	n=read(),K=read();
	bool flag=1;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		if(x!=i+1) flag=0;
		if(y!=i) flag=0;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++) a[i]=read();
	if(flag){
		solve1::solve();
		return 0;
	}
	dfs(1,0);
	ll mx=0;
	for(int i=1;i<=10;i++) mx=max(mx,f[1][K][i]+i);
	printf("%lld",mx);
	return 0;
}
