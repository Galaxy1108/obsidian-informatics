#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}

int mod;
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 600005
#define inf 0x3f3f3f3f

int ch[maxn][2],fa[maxn],sz[maxn],ss[maxn],nxt[maxn];
#define ls(p) ch[p][0]
#define rs(p) ch[p][1]
bool chk(int p){return rs(fa[p])==p;}
bool nrt(int p){return ls(fa[p])==p||rs(fa[p])==p;}
void up(int p){sz[p]=sz[ls(p)]+sz[rs(p)]+ss[p];}
void rot(int x){
	int y=fa[x],z=fa[y],k=chk(x),s=ch[x][!k];
	fa[x]=z; if(nrt(y)) ch[z][chk(y)]=x;
	fa[y]=x; ch[x][!k]=y;
	if(s)fa[s]=y; ch[y][k]=s; up(y),up(x);
}
void splay(int x){
	while(nrt(x)){
		int y=fa[x];
		if(nrt(y))rot(chk(x)==chk(y)?y:x);
		rot(x);
	}
}
void acc(int x){
	for(int y=0;x;x=fa[y=x])
		splay(x),rs(x)=y,up(x); 
}
int findrt(int x){
	acc(x),splay(x);
	while(ls(x))x=ls(x);
	return splay(x),x; 
}

int n,m,k,tot,Q;
int to[maxn],pre[maxn];

void link(int x){
//	cout<<"link "<<x<<' '<<to[x]<<"\n";
	acc(x),splay(x),fa[x]=to[x];
}
void cut(int x){
//	cout<<"cut "<<x<<' '<<to[x]<<"\n";
	acc(x),splay(x),fa[ls(x)]=0,ls(x)=0,up(x); 
}
void mdf(int x){
	acc(x),splay(x);
	ss[x]=1,up(x);
}

int X[maxn],Y[maxn];
map<int,int>vx[200005],vy[200005];
int tx[maxn],ty[maxn],op[maxn];
int px[maxn],py[maxn];

void build(){
	For(i,1,tot)sz[i]=ss[i];
	For(i,1,n){
		auto it=vx[i].begin(),it2=next(it);
		while(it2!=vx[i].end()){
			int u=it->se,v=it2->se;
			to[u]=v,pre[v]=u,link(u);
			it=it2,++it2;
		}
	}
	For(i,1,m){
		auto it=vy[i].begin(),it2=next(it);
		while(it2!=vy[i].end()){
			int u=it->se,v=it2->se;
			to[u]=v,pre[v]=u,link(u);
			it=it2,++it2;
		}
	}
}

void wk(int x,int y){
	int u=vx[x][y],v=vy[y][x];
	mdf(u),mdf(v);
	int fu=pre[u],fv=pre[v];
	cut(fu),cut(fv);
	to[fu]=v,to[fv]=u,pre[u]=fv,pre[v]=fu;
	link(fu),link(fv);
}

int query(int x,int y,int d,bool fl){
	int u;
	if(x==0)u=vy[y][0];
	else u=vx[x][0];
//	puts("QAQ"),cout<<"u: "<<u<<"\n";
	acc(u),splay(u);
	d=sz[u]-d;
	if(d<=0)d=1;
//	if(fl)DFS(u);
	while(1){
		if(ss[u] && sz[ls(u)]+1==d)return splay(u),u;
		if(sz[ls(u)]>=d)u=ls(u);
		else d-=sz[ls(u)]+ss[u],u=rs(u);
	}
}

void FZ(int u,int x,int y){
	X[u]=x,Y[u]=y;
}

signed main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout); 
	read(),n=read(),m=read(),k=read();
	For(i,1,n)++tot,vx[i][0]=tot,FZ(tot,i,0),ss[tot]=1,++tot,vx[i][m+1]=tot,FZ(tot,i,m+1),ss[tot]=1;
	For(i,1,m)++tot,vy[i][0]=tot,FZ(tot,0,i),ss[tot]=1,++tot,vy[i][n+1]=tot,FZ(tot,n+1,i),ss[tot]=1;
	For(i,1,k){
		int x=read(),y=read();
		px[i]=x,py[i]=y;
		++tot,vx[x][y]=tot; FZ(tot,x,y);
		++tot,vy[y][x]=tot; FZ(tot,x,y);
	}
	Q=read();
	For(i,1,Q){
		int o=read();
		tx[i]=read(),ty[i]=read();
		if(o==1){
			op[i]=-1;
			++tot,vx[tx[i]][ty[i]]=tot; FZ(tot,tx[i],ty[i]);
			++tot,vy[ty[i]][tx[i]]=tot; FZ(tot,tx[i],ty[i]);
		}
		else op[i]=read();
	}
	build();
	For(i,1,k) wk(px[i],py[i]);
	For(i,1,Q){
	//	cerr<<"i: "<<i<<"\n";
		if(op[i]==-1) wk(tx[i],ty[i]);
		else {
			int u=query(tx[i],ty[i],op[i],i==15);
			printf("%d %d\n",X[u],Y[u]);
		}
	}
//	For(i,0,n+1)For(j,0,m+1)cout<<vx[i][j]<<" \n"[j==m+1];puts("---");
//	For(i,0,n+1)For(j,0,m+1)cout<<vy[j][i]<<" \n"[j==m+1];puts("");
	return 0;
}