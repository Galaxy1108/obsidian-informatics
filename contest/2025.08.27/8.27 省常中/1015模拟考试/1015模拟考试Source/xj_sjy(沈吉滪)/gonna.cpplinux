// what is matter? never mind. 
#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define ll long long
using namespace std;
inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}

int mod;
typedef unsigned long long ull;
namespace FM{
	typedef __uint128_t L;
	struct FastMod{
		ull b,m;
		FastMod(ull b):b(b),m(ull((L(1)<<64)/b)){}
		ull reduce(ull a){ull q=(ull)((L(m)*a)>>64),r=a-q*b;return r>=b?r-b:r;}
	};
	FastMod F(2);
}

struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=FM::F.reduce(1ull*x*o.x),*this;}
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
#define inf 0x3f3f3f3f

void initmod(){mod=read(),FM::F=FM::FastMod(mod);}
int n;

int vis[maxn];
int pri[maxn],tot;
void sieve(int n){
	vis[1]=0;
	For(i,2,n){
		if(!vis[i])pri[++tot]=i;
		else continue;
		for(int j=i;j<=n;j+=i)
			if(!vis[j])vis[j]=tot;
	}
}

#define M 2271

int tmp[M]; // fac
int now[M],mx[M]; // now
modint res;

modint f[M][20005];
vector<modint>g[37];
int tab[37]={
0,
219138,167306,101563,88037,67216,57672,57728,40392,43018,37996,37800,37800,36520,36540,39330,38948,34510,36900,35640,30030,31752,37206,27388,31504,37440,20300,21114,22790,23652,25424,32130,34190,37400,38502,19832
};


signed main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	sieve(20005);
//	cout<<tot<<"\n"; (tot=2262)
	n=read(),initmod();
	For(i,1,34){
		g[i].resize(tab[i]+1);
		g[i][0]=1;
		modint pw=1;
		For(j,1,tab[i]){
			pw*=pri[i];
			g[i][j]=g[i][j-1]+pw;
		}
	}
	For(i,35,tot){
		f[i][0]=1;
		modint pw=1;
		For(j,1,20000){
			pw*=pri[i];
			f[i][j]=f[i][j-1]+pw;
		}
	}
	res=1;
	// {1-34} use g
	// else   use f
	For(i,2,n){
		for(int u=i;u!=1;u/=pri[vis[u]]){
			int p=vis[u];
			++tmp[p],now[p]+=i;
		}
		modint prod=1;
		For(j,1,tot){
			now[j]-=tmp[j];
			if(now[j]){
				if(j<=34)prod*=g[j][now[j]];
				else prod*=f[j][now[j]];
			}
		}
		res+=prod;
	}
	cout<<res.x;
	return 0;
}
/*
20000 1000000007
*/