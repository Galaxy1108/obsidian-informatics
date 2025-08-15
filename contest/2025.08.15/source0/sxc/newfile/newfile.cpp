#include<bits/stdc++.h>
#define pb push_back
#define FOR(i,s,t) for(int i=(s);i<=(t);++i) 
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
using namespace std;
inline int read() {
	int x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	return x;
}
const int N=1e5+3,P=1e9+9;
inline int add(int x) {return x>=P?x-P:x;}
inline void Add(int &x,int y) {(x+=y)>=P&&(x-=P);}
int n,m,Q,a[N<<2][3];
long long ans[N];
struct opt{int l,r,x;}p[N];
struct que{int l,r,k,i;};
vector<que> q[N];
struct mtx{
	int a00,a10,a11,a20,a21,a22;
}E,I={1,0,1,0,0,1},t[N<<2],K;
bool operator==(mtx A,mtx B) {
	if(A.a00!=B.a00) return false;
	if(A.a10!=B.a10) return false;
	if(A.a11!=B.a11) return false;
	if(A.a20!=B.a20) return false;
	if(A.a21!=B.a21) return false;
	if(A.a22!=B.a22) return false;
	return true;
}
mtx operator*(mtx A,mtx B) {
	return mtx{
		1ll*A.a00*B.a00%P,
		(1ll*A.a10*B.a00+1ll*A.a11*B.a10)%P,
		1ll*A.a11*B.a11%P,
		(1ll*A.a20*B.a00+1ll*A.a21*B.a10+1ll*A.a22*B.a20)%P,
		(1ll*A.a21*B.a11+1ll*A.a22*B.a21)%P,
		1ll*A.a22*B.a22%P
	};
}
inline void ini(int x=1,int l=1,int r=n) {
	t[x]=I,a[x][2]=r-l+1;
	if(l==r) return;
	ini(ls,l,mid),ini(rs,mid+1,r);
}
inline void gtg(int x,mtx y) {
	int b[3];
	b[0]=(1ll*a[x][0]*y.a00+1ll*a[x][1]*y.a10+1ll*a[x][2]*y.a20)%P,
	b[1]=(1ll*a[x][1]*y.a11+1ll*a[x][2]*y.a21)%P,
	b[2]=a[x][2];
	memcpy(a[x],b,12),t[x]=t[x]*y;
}
inline void psd(int x) {
	if(t[x]==I) return;
	gtg(ls,t[x]),gtg(rs,t[x]),t[x]=I;
}
inline void psh(int x) {
	a[x][0]=add(a[ls][0]+a[rs][0]),
	a[x][1]=add(a[ls][1]+a[rs][1]);
}
inline void Mul(int L,int R,int x=1,int l=1,int r=n) {
	if(L>r||R<l) return;
	if(L<=l&&r<=R) return gtg(x,K);
	psd(x);
	Mul(L,R,ls,l,mid),Mul(L,R,rs,mid+1,r);
	psh(x);
}
inline int sum(int L,int R,int x=1,int l=1,int r=n) {
	if(L>r||R<l) return 0;
	if(L<=l&&r<=R) return a[x][0];
	psd(x);
	return add(sum(L,R,ls,l,mid)+sum(L,R,rs,mid+1,r));
}
int main() {
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0);
	n=read(),m=read(),Q=read();
	FOR(i,1,m) p[i]={read(),read(),read()};
	FOR(i,1,Q) {
		int u=read(),d=read(),l=read(),r=read();
		if(!d) continue;
		q[max(u-1,0)].pb(que{l,r,-1,i}),q[d].pb(que{l,r,1,i});
	}
	ini();
	FOR(i,1,m) {
		K={1,0,1,0,p[i].x,1},Mul(p[i].l,p[i].r);
		gtg(1,mtx{1,1,1,0,0,1});
		for(que j:q[i]) ans[j.i]+=j.k*sum(j.l,j.r);
	}
	FOR(i,1,Q) cout<<(ans[i]%P+P)%P<<'\n';
	return 0;
}
