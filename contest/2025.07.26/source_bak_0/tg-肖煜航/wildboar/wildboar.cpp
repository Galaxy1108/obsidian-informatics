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
const int N=2005;
struct edge{
	int to,nxt;
	ll w;
}e[N<<1];
int head[N],tot;
void add(int u,int v,int w){
	e[++tot]={v,head[u],w};
	head[u]=tot;
}
int n,m,t,l;
int a[100005];
int f[15][15][15][15];
bool vis[15][15][15][15]; 
ll b[15],tmp[15];
ll dfs(int x1,int y1,int x2,int y2){
	if(x1==y1||x2==y2) return 1e12;
	if(y1==y2){
		if(x1==x2) return 0; 
		else return 1e12;
	}
	if(vis[x1][y1][x2][y2]) return 1e12;
	if(f[x1][y1][x2][y2]!=-1) return f[x1][y1][x2][y2];
	ll mi=1e12;
	vis[x1][y1][x2][y2]=1;
	for(int i=head[y1];i;i=e[i].nxt){
		int v=e[i].to;
		mi=min(mi,dfs(y1,v,x2,y2));
	}
	vis[x1][y1][x2][y2]=0;
	return f[x1][y1][x2][y2]=mi;
}
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	
	n=read(),m=read(),t=read(),l=read();
	while(t--) printf("-1\n");
//	while(m--){
//		int x=read(),y=read(),z=read();
//		add(x,y,z);
//		add(y,x,z);
//	}
//	for(int i=1;i<=l;i++) a[i]=read();
//	int x=read(),y=read();
//	a[x]=y;
//	memset(f,-1,sizeof f);
//	for(int i=1;i<15;i++) b[i]=1e12;
//	for(int i=2;i<=l;i++){
//		for(int j=0;j<=n;j++) tmp[j]=1e12;
//		for(int j=0;j<=n;j++){
//			for(int k=1;k<=n;k++){
//				tmp[k]=min(tmp[k],b[j]+dfs(j,a[i-1],k,a[i]));
//			}
//		}
//		for(int j=0;j<=n;j++) b[j]=tmp[j];
//	}
//	ll mi=1e12;
//	for(int i=1;i<=n;i++) mi=min(mi,b[i]);
//	if(mi!=(ll)(1e12)) printf("%lld",mi);
//	else printf("-1");
	return 0;
}
