#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	register int x=0;
	register char ch=cin.get();
	register bool op=0;
	while(!isdigit(ch)) {if(ch=='-')op=1;ch=cin.get();}
	while(isdigit(ch)) {(x*=10)+=(ch^48);ch=cin.get();}
	return op?-x:x;	
} 
const int N = 1e6+9;
int n,fa[N],a[N];
struct edge{int v,w,net;}e[N<<1]; 
int head[N],cnt;
inline void add(int u,int v,int w) {e[++cnt]={v,w,head[u]};head[u]=cnt;} 
long long ans[N]; 
long long dis[N];
int Log[N],dfn[N],f[N][29],dep[N],tot,id[N];
void dfs(int u) 
{
	dfn[++tot]=u;dep[u]=dep[fa[u]]+1;id[u]=tot;
	for(register int i(head[u]);i;i=e[i].net) 
	{
		int v=e[i].v;
		dis[v]=dis[u]+e[i].w;
		dfs(v);
		dfn[++tot]=u;
	}
}
inline int LCA(int x,int y)
{
    if(id[x]>id[y]) swap(x,y);
    int s=Log[id[y]-id[x]+1],l=id[x],r=id[y];
    return dep[f[l][s]]<dep[f[r-(1<<s)+1][s]] ? f[l][s] :f[r-(1<<s)+1][s];
}
inline long long calu(int x,int y) {x-=n,y-=n;return dis[x]+dis[y]-2*dis[LCA(x,y)];}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(register int i(2);i<=n;++i) fa[i]=read();
	for(register int i(2),w;i<=n;++i) {w=read();add(fa[i],i,w);} 
	for(register int i(2);i<=n;++i) fa[i+n]=read()+n;
	for(register int i(2);i<=n;++i) add(fa[i+n],i+n,0);
	for(register int i(1);i<=n;++i) a[i+n]=read();
	dfs(1);
	for(register int i(2);i<=tot;++i) Log[i]=Log[i>>1]+1;
	for(register int i(1);i<=tot;++i) f[i][0]=dfn[i]; 
    for(register int i(2);i<=tot;++i) Log[i]=Log[i>>1]+1;
    for(register int j(1);j<=Log[tot];++j) for (register int i(1);i+(1<<j)-1<=tot;++i) 
    f[i][j]= dep[f[i][j-1]]<dep[f[i+(1<<(j-1))][j-1]]? f[i][j-1] :f[i+(1<<(j-1))][j-1];
	for(register int i(1+n);i<=2*n;++i) 
	{
		int x=i,num=0;long long sum=0;
		while(x) 
		{
			sum+=1ll*a[x]*num;
			ans[x-n]=max(ans[x-n],sum+calu(x,i));
			x=fa[x];
			++num;
		}  
	}
	for(register int i(1);i<=n;++i) printf("%lld ",ans[i]);
	return 0; 
}
