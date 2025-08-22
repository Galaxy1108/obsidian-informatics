#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<ll,ll> pll;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=x*10+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
const int N=100003;
const int P=998244353;
int n,q,sq;
int a[N];
int ql[N],qr[N];
inline int bel(int x){return (x-1)/sq+1;}
struct MinHull{
	int stk[N],tp;
	bool check(int x,int y,int z){
		return (ll)(a[z]-a[y])*(z-x)<=(ll)(a[z]-a[x])*(z-y);
	}
	void append(int i){
		while(tp>1&&check(stk[tp-1],stk[tp],i)) --tp;
		stk[++tp]=i;
	}
	int query(ll x,ll y){
		int l=1,r=tp;
		while(l<r){
			int o=(l+r)>>1;
			if((lll)x*(stk[o+1]-stk[o])<(lll)y*(a[stk[o+1]]-a[stk[o]])) r=o;
			else l=o+1;
		}
		return stk[l];
	}
}Mn1,Mn2;
struct MaxHull{
	int stk[N],tp;
	bool check(int x,int y,int z){
		return (ll)(a[z]-a[y])*(z-x)>=(ll)(a[z]-a[x])*(z-y);
	}
	void append(int i){
		if(tp&&a[i]<=a[stk[tp]]) return;
		while(tp>1&&check(stk[tp-1],stk[tp],i)) --tp;
		stk[++tp]=i;
	}
	int query(ll x,ll y){
		int l=1,r=tp;
		while(l<r){
			int o=(l+r)>>1;
			if((lll)x*(stk[o+1]-stk[o])>(lll)y*(a[stk[o+1]]-a[stk[o]])) r=o;
			else l=o+1;
		}
		return stk[r];
	}
}Mx1,Mx2;
int qmn(ll x,ll y){
	int ps=Mn1.query(x,y);
	if(Mn2.tp){
		int nps=Mn2.query(x,y);
		if((lll)y*a[nps]-(lll)x*nps<(lll)y*a[ps]-(lll)x*ps) ps=nps;
	}
	return ps;
}
int qmx(ll x,ll y){
	int ps=Mx1.query(x,y);
	if(Mx2.tp){
		int nps=Mx2.query(x,y);
		if((lll)y*a[nps]-(lll)x*nps>(lll)y*a[ps]-(lll)x*ps) ps=nps;
	}
	return ps;
}
int dir(ll x,ll y){
	int pmn=qmn(x,y);lll vmn=(lll)y*a[pmn]-(lll)x*pmn;
	int pmx=qmx(x,y);lll vmx=(lll)y*a[pmx]-(lll)x*pmx;
	if(vmx-vmn>=y){
		if(pmn>pmx) return -1;
		if(pmn<pmx) return 1;
	}
	return 0;
}
pll sol(ll a,ll b,ll c,ll d){
	int w=dir(a+b,c+d);
	if(w<0){
		int t=0;
		while(dir((a<<(t+1))+b,(c<<(t+1))+d)==w) ++t;
		b+=(a<<t);d+=(c<<t);
		while(t){--t;if(dir((a<<t)+b,(c<<t)+d)==w) b+=(a<<t),d+=(c<<t);}
		return sol(a,b,c,d);
	}
	if(w>0){
		int t=0;
		while(dir((b<<(t+1))+a,(d<<(t+1))+c)==w) ++t;
		a+=(b<<t);c+=(d<<t);
		while(t){--t;if(dir((b<<t)+a,(d<<t)+c)==w) a+=(b<<t),c+=(d<<t);}
		return sol(a,b,c,d);
	}
	return pll(a+b,c+d);
}
ll qa[N],qb[N],qc[N];
int ss[N];
void proc(int i){
	pll cur=sol(0,1,1,0);
	ll x=cur.first,y=cur.second;
	int ps=qmx(x,y);
	qa[i]=x;qb[i]=(lll)y*a[ps]-(lll)x*(ps-ql[i]);qc[i]=y;
}
void build(int l,int r){
	Mn1.tp=Mx1.tp=0;
	for(int i=l;i<=r;++i) Mn1.append(i);
	for(int i=l;i<=r;++i) Mx1.append(i);
}
vector<int> vec[N];
void solve(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=2;i<=n;++i) ss[i]=ss[i-1]+(a[i-1]!=a[i]);
	sq=ceil(sqrt(n));
	q=read();
	for(int i=1;i<=q;++i){
		ql[i]=read(),qr[i]=read();
		if(ss[ql[i]]==ss[qr[i]]){qa[i]=0;qb[i]=a[ql[i]];qc[i]=1;continue;}
		int bl=bel(ql[i]),br=bel(qr[i]);
		if(bl<br) vec[bl].emplace_back(i);
		else Mn2.tp=Mx2.tp=0,build(ql[i],qr[i]),proc(i);
	}
	for(int x=1;x<bel(n);++x){
		sort(vec[x].begin(),vec[x].end(),[](int a,int b){return qr[a]<qr[b];});
		Mn2.tp=Mx2.tp=0;
		int ps=x*sq+1;
		for(int t:vec[x]){
			build(ql[t],x*sq);
			while(ps<=qr[t]) Mn2.append(ps),Mx2.append(ps),++ps;
			proc(t);
		}
		vec[x].clear();
	}
	for(int i=1;i<=q;++i) printf("%lld %lld %lld\n",qa[i],qb[i],qc[i]);
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int tc=read();
	while(tc--) solve();
	return 0;
}
