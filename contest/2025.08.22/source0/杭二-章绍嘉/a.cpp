#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii<=Ii##_;Ii++)
#define per(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii>=Ii##_;Ii--)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double db;
#define fir first
#define sec second
#define siz(Aa) ((int)(Aa).size())
#define all(Aa) (Aa).begin(),(Aa).end()
#define ckmx(Aa,Bb) (Aa=max(Aa,Bb))
#define ckmn(Aa,Bb) (Aa=min(Aa,Bb))
struct red{
	int k,m;using big=__int128;ll x;
	void init(const int&n){m=n,k=3*__lg(m-1+m),x=((big(1)<<k)-1)/m+1;}// 1<=n<=2^30
	inline int operator()(const ll&v)const{return v-(big(v)*x>>k)*m;}// 0<=v<n^2
}o;
int P;
struct mod_int{
	using Z=mod_int;
	static signed mo(signed x){return x<0?x+P:x;}
	signed x;
	signed val()const{return x;}
	mod_int():x(0){}
	template<class T>mod_int(const T&x_):x(x_>=0&&x_<P?static_cast<signed>(x_):mo(static_cast<signed>(x_%P))){}
	bool operator==(const Z&rhs)const{return x==rhs.x;}
	bool operator!=(const Z&rhs)const{return x!=rhs.x;}
	Z operator-()const{return Z(x?P-x:0);}
	Z pow(long long k)const{Z res=1,t=*this;while(k){if(k&1)res*=t;if(k>>=1)t*=t;}return res;}
	Z operator~()const{assert(x);return pow(P-2);}
	Z&operator++(){x<P-1?++x:x=0;return *this;}
	Z&operator--(){x?--x:x=P-1;return *this;}
	Z operator++(signed){Z ret=x;x<P-1?++x:x=0;return ret;}
	Z operator--(signed){Z ret=x;x?--x:x=P-1;return ret;}
	Z&operator+=(const Z&rhs){(x+=rhs.x)>=P&&(x-=P);return *this;}
	Z&operator-=(const Z&rhs){(x-=rhs.x)<0&&(x+=P);return *this;}
	Z&operator*=(const Z&rhs){x=o(1ULL*x*rhs.x);return *this;}
	Z&operator/=(const Z&rhs){return *this*=~rhs;}
#define setO(o) friend Z operator o(const Z&lhs,const Z&rhs){Z res=lhs;return res o##=rhs;}
	setO(+)setO(-)setO(*)setO(/)
#undef setO
	friend istream& operator>>(istream&is,Z&x){long long y;is>>y;x=Z(y);return is;}
	friend ostream& operator<<(ostream&os,const Z&x){return os<<x.val();}
};
using Z=mod_int;
const int N=1e7+10;
int n,m;
Z b[4][N],*L[N],*R[N];
inline void cl(Z*a){ fill(a+1,a+1+m,0); }
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>P;
	o.init(P);
	L[1]=b[0],R[1]=b[1];
	cl(L[1]),cl(R[1]);
	rep(r,1,m) L[1][r]+=r;
	rep(l,1,m) R[1][l]+=(m-l+1);
	int base=2;
	rep(i,2,n){
		L[i]=b[base],R[i]=b[base|1];
		cl(L[i]),cl(R[i]);
		base^=2;
		rep(j,1,m) L[i-1][j]+=L[i-1][j-1];
		per(j,m,1) R[i-1][j]+=R[i-1][j+1];
		
		rep(l,1,m) L[i][l]-=L[i-1][l-1];
		rep(j,1,m) L[i][j]+=L[i][j-1];
		rep(r,1,m) L[i][r]-=R[i-1][r+1]*r;
		
		rep(r,1,m) R[i][r]-=R[i-1][r+1];
		per(j,m,1) R[i][j]+=R[i][j+1];
		rep(l,1,m) R[i][l]-=L[i-1][l-1]*(m-l+1);
		
		rep(r,1,m) L[i][r]+=L[i-1][m]*r;
		rep(l,1,m) R[i][l]+=L[i-1][m]*(m-l+1);
	}
	Z ans=0;
	rep(r,1,m) ans+=L[n][r];
	cout<<ans<<"\n";
return 0;}
/*
*/