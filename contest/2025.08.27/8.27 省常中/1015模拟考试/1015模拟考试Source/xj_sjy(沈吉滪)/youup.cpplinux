#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define mod 998244353
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
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define poly vector<modint>
const modint G=3,Ginv=modint(1)/3;
inline poly one(){poly a;a.push_back(1);return a;}
vector<int>rev;
vector<modint>rts;
inline int ext(int n){
	int k=0;
	while((1<<k)<n)++k;return k; 
}
inline void init(int k){
	int n=1<<k;
	if(rev.size()==n)return;
	rev.resize(n);
	For(i,0,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	if(rts.size()>=n)return;
	int lst=max(1,(int)rts.size()); rts.resize(n);
	for(int mid=lst;mid<n;mid<<=1){
		modint wn=G^((mod-1)/(mid<<1));
		rts[mid]=1;
		For(i,1,mid-1)rts[i+mid]=rts[i+mid-1]*wn;
	}
}
void ntt(poly&a,int k,int typ)
{
	int n=1<<k;
	if(typ<0) reverse(a.begin()+1,a.end());
	For(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]); 
	for(int mid=1;mid<n;mid<<=1)
		for(int r=mid<<1,j=0;j<n;j+=r)
			for(int k=0;k<mid;++k){
				modint x=a[j+k],y=rts[mid+k]*a[j+k+mid];
				a[j+k]=x+y,a[j+k+mid]=x-y;
			}
	if(typ<0){
		modint inv=modint(1)/n;
		For(i,0,n-1)a[i]*=inv;
	}
}
 
poly operator +(poly a,poly b){
	int n=max(a.size(),b.size());a.resize(n),b.resize(n);
	For(i,0,n-1)a[i]+=b[i];return a;
}
poly operator -(poly a,poly b){
	int n=max(a.size(),b.size());a.resize(n),b.resize(n);
	For(i,0,n-1)a[i]-=b[i];return a;
}
poly operator *(poly a,modint b){
	int n=a.size();
	For(i,0,n-1)a[i]*=b;return a;
} 
poly operator *(poly a,poly b)
{
	if((int)a.size()<=64 && (int)b.size()<=64){
		poly c(a.size()+b.size()-1,0);
		for(int i=0;i<a.size();++i)
			for(int j=0;j<b.size();++j)
				c[i+j]+=a[i]*b[j];
		return c; 
	}
	int n=(int)a.size()+(int)b.size()-1,k=ext(n);
	a.resize(1<<k),b.resize(1<<k),init(k);
	ntt(a,k,1),ntt(b,k,1);
	For(i,0,(1<<k)-1)a[i]*=b[i];
	ntt(a,k,-1),a.resize(n);return a;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 300005
#define inf 0x3f3f3f3f

int n,m;
struct edge{
	int to,nxt;
}e[maxn<<1];
int tot,head[maxn];
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}

int dep[maxn],lg[maxn<<1],st[maxn<<1][21];
int dfn[maxn<<1],que[maxn<<1],idx;
void dfs(int u,int pa)
{
    dfn[u]=++idx,que[idx]=u;
    dep[u]=dep[pa]+1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==pa)continue;
        dfs(v,u);
        que[++idx]=u;
    }
}
void buildst()
{
    For(i,1,idx)st[i][0]=que[i];
    For(j,1,20)
        for(int i=1;i+(1<<j)<=idx;++i){
            int f1=st[i][j-1],f2=st[i+(1<<j-1)][j-1];
            st[i][j]=dep[f1]<dep[f2]?f1:f2;
        }
    lg[0]=-1;
    For(i,1,idx)lg[i]=lg[i>>1]+1;
}
inline int lca(int u,int v)
{
    if(dfn[u]>dfn[v])swap(u,v);
    u=dfn[u],v=dfn[v];
    int kk=lg[v-u+1],f1=st[u][kk],f2=st[v-(1<<kk)+1][kk];
    return dep[f1]<dep[f2]?f1:f2;
}
inline int dist(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

int rt,sum;
bool vis[maxn];
int sz[maxn],mxp[maxn],dfa[maxn],dsz[maxn];
void getrt(int u,int pa)
{
	sz[u]=1,mxp[u]=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(vis[v]||v==pa)continue;
		getrt(v,u);
		sz[u]+=sz[v];
		mxp[u]=max(mxp[u],sz[v]);
	}mxp[u]=max(mxp[u],sum-sz[u]);
	if(mxp[u]<mxp[rt])rt=u;
}
void solve(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(vis[v])continue;
		sum=sz[v],rt=0,mxp[0]=inf;
		getrt(v,0);
		dfa[rt]=u,dsz[rt]=sum;
		solve(rt);
	}
}

#define N 20000005
int cnt,root[maxn][2],lc[N],rc[N],val[N];
int newn(){return ++cnt;}
void modify(int&p,int l,int r,int x,int v)
{
	if(!p)p=newn();
	val[p]+=v;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)modify(lc[p],l,mid,x,v);
	else modify(rc[p],mid+1,r,x,v);
}
int ask(int p,int l,int r,int ql,int qr)
{
	if(!p)return 0;
	if(l>=ql&&r<=qr)return val[p];
	int mid=l+r>>1,res=0;
	if(ql<=mid)res+=ask(lc[p],l,mid,ql,qr);
	if(qr>mid)res+=ask(rc[p],mid+1,r,ql,qr);
	return res;
} 

void change(int p,int x)
{
	int u=p;
	while(u)
	{
		int f=dfa[u];
		modify(root[u][0],0,dsz[u],dist(u,p),x);
		if(f) modify(root[u][1],0,dsz[f],dist(f,p),x);
		u=f;
	}
}
int qry(int p,int k)
{
	int u=p,res=0,lst=0;
	while(u)
	{
		int d=dist(u,p);
		if(d>k){
			lst=u,u=dfa[u];
			continue;
		}
		res+=ask(root[u][0],0,dsz[u],0,k-d);
		if(lst)res-=ask(root[lst][1],0,dsz[u],0,k-d);
		lst=u,u=dfa[u];
	}
	return res;
}
int d,id[maxn];

inline bool cmp(int x,int y){
	return dep[x]>dep[y] || (dep[x]==dep[y] && x<y);
}

signed main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	read();
	n=read(),d=read();
	For(i,2,n){
		int u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dfs(1,0);buildst();mxp[rt]=sum=n;
	getrt(1,0);dsz[rt]=n;solve(rt);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	poly f; f.resize(n+1);
	Rep(i,n,1){
		int u=id[i];
		change(u,1);
		int c=qry(u,d);
//		cout<<"c: "<<c<<endl;
		f[c-1]+=1;
	}
	// g[i]*fac[i] <- f[j]*fac[j]*ifac[j-i] 
	poly g; g.resize(n+1); initC(n+1);
	For(i,0,n) f[i]*=fac[i],g[i]=ifac[n-i];
	f=f*g;
	For(i,0,n-1){
		modint res=f[i+n]*ifac[i];
		printf("%d ",res.x);
	}
    return 0;
}