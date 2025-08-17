/*
start coding at : 9:10
*/
#include<bits/stdc++.h>
#define ll long long 
#define iL inline ll
#define iI inline int 
#define iV inline void
#define gc getchar()
#define pt putchar
#define eb emplace_back
#define FOR(i,s,t) for(int i=(s);i<=(t);++i)
using namespace std;
iI read() {
	int x=0,f=1;char c=gc;
	while(!isdigit(c)) f=(c=='-'?-1:f),c=gc;
	while(isdigit(c)) x=x*10+(c^48),c=gc;
	return x*f;
}
iV chx(ll &x,ll y) {x=x>y?x:y;}
const int N=5e5+3,M=1e6+3;
const ll inf=1e18; 
int n,m,a[N],col[M],p[N],q[N];
int Y[N];
ll X[N],W[M],ANS[N],cur;
struct func{ll k,b;}line[N];
iL F(int i,int x) {return i?line[i].k*X[x]+line[i].b:-inf;}
struct LiChaotree{
	int cnt,rt[N],ls[N*20],rs[N*20],tg[N*20];
	#define L ls[x]
	#define R rs[x]
	#define T tg[x]
	#define I ((l+r)>>1)
	iI nd(int &x) {return x?x:(x=++cnt,L=R=T=0,x);}
	iV upd(int x,int y,int l=1,int r=n) {
		while(1) {
			if(F(T,I)<F(y,I)) swap(T,y);
			if(l==r) return;
			if(F(T,l)<F(y,l)) x=nd(L),r=I;
			else if(F(T,r)<F(y,r)) x=nd(R),l=I+1;
			else return;
		}
	}
	iI mer(int x,int y,int l=1,int r=n) {
		if(!x||!y) return x|y;
		L=mer(L,ls[y],l,I),R=mer(R,rs[y],I+1,r);
		return upd(x,tg[y],l,r),x;
	}
	iV Mer(int x,int y) {rt[x]=mer(rt[x],rt[y]);}
	iV Ins(int x) {upd(nd(rt[x]),x);}
	iL que(int x,int y) {
		x=rt[x];
		int l=1,r=n;ll res=-inf;
		while(x) {
			chx(res,F(T,y));
			if(l==r) break;
			y<=I?(x=L,r=I):(x=R,l=I+1);
		} 
		return res;
	}
	#undef L
	#undef R
	#undef T
	#undef I
}T[2];
namespace T2{
	struct edge{int v,nxt;}e[N<<1];
	int tot=-1,h[N],f[N],lv[N],s[N],t,qk[N],tk;
	int Lg[N],I[20]={1},g[20][N],df,dfn[N];
	ll c[N],d[N];
	iV add(int u,int v) {e[++tot]={v,h[u]},h[u]=tot;}
	iI mih(int x,int y) {return lv[x]<lv[y]?x:y;}
	iV dfs(int u) {
		g[0][dfn[u]=++df]=f[u],p[df]=u;
		for(int i=h[u],v;~i;i=e[i].nxt) 
			v=e[i].v,c[v]=c[u]+a[v],d[v]=d[u]+1ll*(lv[v]=lv[u]+1)*a[v],dfs(v);
	}
	iV afs(int u) {
		qk[++tk]=u;
		for(int i=h[u],v;~i;i=e[i].nxt) {
			afs(v=e[i].v);
			T[0].Mer(u,v),T[1].Mer(u,v);
		}
		int C=col[u];
		if(!~C) return;
		chx(ANS[u],d[f[u]]+W[u]+cur+T[C^1].que(u,Y[u]));
		line[u]={-lv[u],c[u]*lv[u]-d[u]+W[u]},T[C].Ins(u);
	}
	iI lca(int x,int y) {
		if(x==y) return x;
		if((x=dfn[x])>(y=dfn[y])) swap(x,y);
		int s=Lg[y-x];
		return mih(g[s][x+1],g[s][y-I[s]+1]);
	}
	iV vst(int l,int r) {
		h[s[t=1]=1]=tot=-1;
		FOR(i,l,r) if(p[i]^1) {
			int u=p[i],v=lca(u,s[t]);
			if(v^s[t]) {
				while(dfn[v]<dfn[s[t-1]]) add(s[t-1],s[t]),s[t--]=0;
				if(dfn[v]>dfn[s[t-1]]) h[v]=-1,add(v,s[t]),s[t]=v;
				else add(v,s[t]),s[t--]=0;
			}
			h[s[++t]=u]=-1;
		}
		FOR(i,1,t-1) add(s[i],s[i+1]);
		memset(s+1,0,t<<2),afs(1);
		FOR(i,1,tk) T[0].rt[qk[i]]=T[1].rt[qk[i]]=0;
		T[0].cnt=T[1].cnt=tk=0;
	}
	iV ini() {
		memset(h,-1,sizeof(h)),memset(col,-1,sizeof(col));
		FOR(i,2,n) add(f[i]=read(),i),Lg[i]=Lg[i>>1]+1;
		FOR(i,1,n) a[i]=read();
		c[1]=a[1],dfs(1);
		FOR(i,1,n) X[i]=c[f[i]];
		sort(X+1,X+n+1);
		FOR(i,1,n) Y[i]=lower_bound(X+1,X+n+1,c[f[i]])-X;
		FOR(i,1,Lg[n]) I[i]=I[i-1]<<1;
		FOR(j,1,Lg[n]) FOR(i,1,n+1-I[j]) g[j][i]=mih(g[j-1][i],g[j-1][i+I[j-1]]); 
	}
}
using namespace T2;
namespace T1{
	int tot=-1,cnt,h[M],Mx,rt,All,sz[M],ct,t[M];
	bool vis[M];
	struct bian{int u,v,w;}E[M];
	struct edge{int v,w,nxt;}e[M<<1];
	iV add(int u,int v,int w) {e[++tot]={v,w,h[u]},h[u]=tot;}
	iV lnk(int u,int v,int w) {add(u,v,w),add(v,u,w);}
	iV dfs(int u,int f) {
		for(int i=h[u],j=u,v;~i;i=e[i].nxt) 
            if((v=e[i].v)^f) 
			    E[++cnt]={j,v,e[i].w},E[++cnt]={j,++m,0},j=m,dfs(v,u);
	}
	iV afs(int u,int f) {
		sz[u]=1;
		for(int i=h[u],v;~i;i=e[i].nxt) 
        if(!vis[i>>1]&&(v=e[i].v)^f) {
			afs(v,u),sz[u]+=sz[v];
			int mn=min(sz[v],All-sz[v]);
			if(mn>Mx) rt=i,Mx=mn;
		}
	}
	iV Nxt(int s,int u) {All=s,Mx=rt=0,afs(u,0);}
	iV bfs(int u,int f) {
		t[++ct]=u;
		for(int i=h[u],v;~i;i=e[i].nxt) 
            if(!vis[i>>1]&&(v=e[i].v)^f) 
                col[v]=col[u],W[v]=W[u]+e[i].w,bfs(v,u);
	}
	iV sol(int l,int r) {
		if(!Mx||l>r) return;
		int S=e[rt].v,T=e[rt^1].v,sl=sz[S],sr=All-sl;
		vis[rt>>1]=1,cur=e[rt].w,ct=0,col[S]=0,col[T]=1;
		bfs(S,0),bfs(T,0),vst(l,r);
        int R=l,L=l;
        FOR(i,l,r) R+=(!col[p[i]]);
    	FOR(i,l,r) q[col[p[i]]?R++:L++]=p[i];
        memcpy(p+l,q+l,(r-l+1)<<2);
		FOR(i,1,ct) W[t[i]]=0,col[t[i]]=-1;
		Nxt(sl,S),sol(l,L-1);
        Nxt(sr,T),sol(L,r);
	}
	int g[N];
	iV ini() {
		memset(h,-1,sizeof(h));
		FOR(i,2,n) g[i]=read();
		FOR(i,2,n) lnk(i,g[i],read());
		dfs(1,0),tot=-1,memset(h,-1,sizeof(h));
		FOR(i,1,cnt) lnk(E[i].u,E[i].v,E[i].w);
	}
}
using namespace T1;
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	std::ios::sync_with_stdio(false);cout.tie(0);
	double st=clock();
	n=m=read();
	T1::ini(),T2::ini();
	Nxt(m,1),sol(1,n);
	FOR(i,1,n) cout<<ANS[i]<<' ';
	cerr<<"std : "<<(clock()-st)/CLOCKS_PER_SEC<<"\n";
	return 0;
}
