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

#define maxn 10000005
#define inf 0x3f3f3f3f

int n,m,w;

modint ivn;
int pri[maxn],tot,vis[maxn],mn[maxn],mu[maxn];
void sieve(int n){
	vis[1]=1;
	mu[1]=1;
	For(i,2,n){
		if(!vis[i])pri[++tot]=i,mn[i]=i,mu[i]=-1;
		For(j,1,tot){
			if(i*pri[j]>n)break;
			vis[i*pri[j]]=1;
			mn[i*pri[j]]=pri[j];
			if(i%pri[j])mu[i*pri[j]]=-mu[i];
			else break;
		}
	}
}

int pw[maxn],P[maxn],A[maxn];

signed main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	n=read();
	ivn=((modint(1))/((n%mod)));
	w=read();
	m=1;
	sieve(n);
	For(i,1,w){
		int p=read(),alp=read();
		P[i]=p,A[i]=alp;
		pw[i]=1;
		while(alp--)m*=p,pw[i]*=p;
	}
	if(m==1){
		modint res=0;
		For(i,1,n){
			if(!mu[i])continue;
			modint tmp=(modint(n)/(n-n/i)-1);
			if(mu[i]==1) res-=tmp;
			else res+=tmp;
		}
		cout<<res.x<<"\n";exit(0);
	}
	modint res=0;
	For(i,1,n){
		int x=i;
		int xi=1;
		bool no=0;
	//	cout<<"wk "<<i<<endl;
		For(j,1,w){
			int cx=0;
			while(x%P[j]==0)x/=P[j],cx++;
			if(cx==0)continue;
			if(cx!=A[j]+1){no=1;break;}
			xi*=-1;
		}
		if(no)continue;
		xi*=mu[x];
		modint tmp=(modint(n)/(n-n/i)-1);
		if(xi==1)res-=tmp;
		else res+=tmp;
	}
	cout<<res.x;
	return 0;
}
