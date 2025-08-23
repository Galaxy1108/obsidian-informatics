// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
using namespace std;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 10000005
#define inf 0x3f3f3f3f

int n;
struct edge{
	int to,nxt;
}e[maxn<<1];
int tot=1,head[maxn],w[maxn];
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}

int fa[maxn],sz[maxn],dfn[maxn],que[maxn],idx,out[maxn],U[maxn],V[maxn];

void dfs(int u){
	sz[u]=1;
	dfn[u]=++idx,que[idx]=u;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=fa[u])fa[v]=u,dfs(v),sz[u]+=sz[v];
	}out[u]=idx;
}

struct node{
	int l,r,id; ll v;
	bool operator <(const node&b)const{return v>b.v;}
}a[maxn*3];
int len;

int f[maxn]; 

int t[maxn<<2],tag[maxn<<2];
void up(int p){
	t[p]=t[p<<1]+t[p<<1|1];
}
void bd(int p,int l,int r){
	if(l==r)return t[p]=1,void();
	int mid=l+r>>1;
	bd(p<<1,l,mid),bd(p<<1|1,mid+1,r),up(p);
}
void mdf(int p,int l,int r,int nl,int nr){
	if(!t[p])return;
	if(l>=nl&&r<=nr){
		tag[p]=1,t[p]=0;
		return;
	} 
	int mid=l+r>>1;
	if(nl<=mid)mdf(p<<1,l,mid,nl,nr);
	if(nr>mid)mdf(p<<1|1,mid+1,r,nl,nr);
	up(p); 
}
int ask(int p,int l,int r,int ql,int qr){
	if(!t[p])return 0;
	if(l>=ql&&r<=qr)return t[p];
	int mid=l+r>>1,res=0;
	if(ql<=mid)res+=ask(p<<1,l,mid,ql,qr);
	if(qr>mid)res+=ask(p<<1|1,mid+1,r,ql,qr);return res;
}
void Upd(int l,int r){
	mdf(1,1,n,l,r);
}
int Q(int l,int r){
	return ask(1,1,n,l,r);
}

signed main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	n=read();
	For(i,1,n-1){
		int u=i+1,v=read(); w[i]=read(); U[i]=u,V[i]=v;
	//	cout<<"add "<<i+1<<" "<<v<<" "<<w[i]<<'\n';
		adde(u,v),adde(v,u);
	}
	bd(1,1,n);
	dfs(1);
//	For(i,1,n)cout<<dfn[i]<<' ';puts("");
	For(i,1,n-1){
		int u=U[i],v=V[i];
		if(fa[v]!=u)swap(u,v);
		if(dfn[v]!=1) a[++len]=(node){1,dfn[v]-1,i,1ll*w[i]*(sz[v])};
		a[++len]=(node){dfn[v],out[v],i,1ll*w[i]*(n-sz[v])};
		if(out[v]!=n) a[++len]=(node){out[v]+1,n,i,1ll*w[i]*(sz[v])};
	}
	sort(a+1,a+len+1);
	
	for(int l=1,r=1;l<=len;l=r+1){
		r=l;
		while(r+1<=len && a[r+1].v==a[l].v)++r;
		For(i,l,r) f[a[i].id]+=Q(a[i].l,a[i].r);
		For(i,l,r) Upd(a[i].l,a[i].r);
//		For(i,l,r) cout<<a[i].l<<' '<<a[i].r<<' '<<a[i].id<<' '<<a[i].v<<"\n";
//		puts("----");
	}
	int res=0;
//	For(i,1,n-1)cout<<f[i]<<" \n"[i==n-1];
	For(i,1,n-1)res^=f[i];
	cout<<res;
	return 0;
}
