#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
ll read(){
	ll p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
} 
const int N=4050;
struct edge{
	int to,nxt;
	ll w,t;
}e[N<<1];
int head[95],tot;
void add(int u,int v,ll w,ll t){
	e[++tot]={v,head[u],w,t};
	head[u]=tot;
}
int n,m,q;
ll s;
ll dis[95];
bool vis[95];
ll dij(int a,int b,ll t){
	for(register int i=1;i<=n;i++) vis[i]=0,dis[i]=1e18;
	dis[a]=t;
	for(register int asd=1;asd<=n;asd++){
		int u=0;ll mi=1e18;
		for(register int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(mi>dis[i]){
				mi=dis[i];
				u=i;
			}
		}
		vis[u]=1;
		ll op=dis[u]%s;
		for(register int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			ll t=dis[u];
			if(op<=e[i].t) t+=e[i].w;
			else{
				t+=s-op+e[i].w;
			}
			if(dis[v]>t){
				dis[v]=t;
			}
		}
	}
	return dis[b];
}
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	n=read(),m=read(),s=read(),q=read();
	while(m--){
		int x=read(),y=read();
		ll l=read(),c=read();
		x++;y++;
		add(x,y,l,c-l);
		add(y,x,l,c-l);
	}
	while(q--){
		int u=read(),v=read();
		u++;v++;
		ll t=read();
		write(dij(u,v,t)-t);
		putchar('\n');
	}
	return 0;
}
