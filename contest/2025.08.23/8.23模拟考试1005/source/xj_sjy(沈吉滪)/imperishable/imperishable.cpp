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

#define maxn 500005
#define inf 0x3f3f3f3f

int n,k,a[maxn],V=200000,c[maxn];
modint pw[maxn],spw[maxn];

int s[maxn<<2],mn[maxn<<2],mx[maxn<<2],mxp[maxn<<2];
modint t[maxn<<2];
void up(int p){
	t[p]=t[p<<1]+t[p<<1|1];
	s[p]=s[p<<1]+s[p<<1|1];
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	if(mx[p<<1]>=mx[p<<1|1])mxp[p]=mxp[p<<1];
	else mxp[p]=mxp[p<<1|1];
}
void init(int p,int l){
	mxp[p]=l;
	mn[p]=mx[p]=s[p]=c[l];
	t[p]=pw[l];
}

void build(int p,int l,int r){
	if(l==r)return init(p,l),void();
	int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r),up(p);
}
void upd(int p,int l,int r,int x){
	if(l==r)return init(p,l),void();
	int mid=l+r>>1;
	x<=mid?upd(p<<1,l,mid,x):upd(p<<1|1,mid+1,r,x); up(p);
}

int qsum(int p,int l,int r,int ql,int qr){
	if(ql>qr)return 0;
	if(l>=ql&&r<=qr)return s[p];
	int mid=l+r>>1,res=0;
	if(ql<=mid)res+=qsum(p<<1,l,mid,ql,qr);
	if(qr>mid)res+=qsum(p<<1|1,mid+1,r,ql,qr);return res;
}

modint tmp=0;

void ask(int p,int l,int r,int qr,int &v){
	if(r>qr){
		int mid=l+r>>1;
		if(qr>mid) ask(p<<1|1,mid+1,r,qr,v);
		ask(p<<1,l,mid,qr,v);
		return;
	}
	if(mn[p]>v)return;
	if(s[p]<=v){
		v-=s[p];
		tmp+=t[p];
		return;
	}
	int mid=l+r>>1;
	ask(p<<1|1,mid+1,r,qr,v);
	ask(p<<1,l,mid,qr,v);
}

void query()
{
	int u=mxp[1];
	int sma=qsum(1,1,V,1,u-1);
//	cout<<"mx,sma "<<u<<' '<<sma<<"\n";
	if(sma<mx[1]){
		cout<<pw[u].x<<'\n';
		return;
	}
	tmp=0;
	int nd=sma-mx[1];
	// 选出若干个省去 
	ask(1,1,V,u-1,nd);
	modint res=spw[u-1]-tmp;
	cout<<res.x<<'\n';
}

signed main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	read();
	pw[1]=2; For(i,2,V+1)pw[i]=pw[i-1]*2;
	spw[1]=2; For(i,2,V+1)spw[i]=spw[i-1]+pw[i];
	n=read();
	For(i,1,n)c[i]=read();
	build(1,1,V);
	query();
	int Q=read();
	while(Q--){
		int x=read();
		c[x]=read();
		upd(1,1,V,x);
		query();
	}
	return 0;
}
