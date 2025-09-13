// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

// modint
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
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
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

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f3f3f3f3f

int n,a[maxn],c[maxn],t[maxn],m,id[maxn];

int hav[maxn];

int mx[maxn<<2],tag[maxn<<2],cnt[maxn<<2];
void up(int p){
	cnt[p]=cnt[p<<1]+cnt[p<<1|1];
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void pusht(int p,int x){
	tag[p]+=x;
	mx[p]+=x;
}
void down(int p){
	if(tag[p]) pusht(p<<1,tag[p]),pusht(p<<1|1,tag[p]),tag[p]=0;
}
void add(int p,int l,int r,int nl,int nr,int x){
	if(nl>nr)return;
	if(l>=nl&&r<=nr)return pusht(p,x);
	int mid=l+r>>1; down(p);
	if(nl<=mid)add(p<<1,l,mid,nl,nr,x);
	if(nr>mid)add(p<<1|1,mid+1,r,nl,nr,x); up(p); 
}
void mdf(int p,int l,int r,int x,int y){
	if(l==r){
		mx[p]=y,cnt[p]=1,tag[p]=0;
		return;
	}
	int mid=l+r>>1; down(p);
	if(x<=mid)mdf(p<<1,l,mid,x,y);
	else mdf(p<<1|1,mid+1,r,x,y); up(p); 
}
int resmx,rescnt;
void ask(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){
		rescnt+=cnt[p];
		resmx=max(resmx,mx[p]);
		return;
	}
	int mid=l+r>>1; down(p); 
	if(ql<=mid)ask(p<<1,l,mid,ql,qr);
	if(qr>mid)ask(p<<1|1,mid+1,r,ql,qr);
}
void ask(int l,int r){
	resmx=-inf,rescnt=0;
	if(l>r)return;
	ask(1,1,n,l,r);
}

void work()
{
	n=read();
	For(i,1,n)a[i]=read(),c[i]=t[i]=a[i]-i,id[i]=i;
	sort(t+1,t+n+1),m=unique(t+1,t+n+1)-t-1;
	if(m<n){
		puts("-1");
		return;
	}
	For(i,0,n)hav[i]=-inf;
	int res=0;
	sort(id+1,id+n+1,[&](int x,int y){return c[x]>c[y];});
	For(i,0,4*n)mx[i]=-inf,tag[i]=cnt[i]=0;
	// c[i] >= 0
	For(i,1,n){
		int u=id[i];
//		int cnt=0;
//		For(j,1,u-1)cnt+=(hav[j]>=0);
//		hav[u]=c[u]+cnt*2+1;
//		For(j,u+1,n)
//			if(hav[j]!=-inf) hav[j]+=2,res=max(res,c[u]+hav[j]);
		ask(1,u-1);
		int cs=rescnt;
		int val=c[u]+cs*2+1;
		mdf(1,1,n,u,val);
		add(1,1,n,u+1,n,2);
		ask(u+1,n);
		if(resmx>=0) res=max(res,resmx+c[u]);
		
	}
	cout<<res<<'\n';
}

signed main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	int T=read();
	while(T--)work();
	return 0;
}
