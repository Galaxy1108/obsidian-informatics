#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 1e5;
const int MOD = 1e9+7;

struct Node{
	int ls,rs;
	ll sum,tag;	
	void operator = (const Node& a){ ls = a.ls; rs = a.rs; tag = a.tag; }
}tr[55][MAXN*5];

int ncnt = 0;

int build(int l,int r){

	pr("build() %d %d\n",l,r);
	
	int p = ncnt++;
	if(l == r){ tr[p].ls = 0,tr[p].rs = 0; return p;}
	int m = (l+r)/2;
	tr[p].ls = build(l,m);tr[p].rs = build(m+1,r);
	return p;
}

void clone(int ov,int nv,int p,int l,int r){
	tr[nv][p] = tr[ov][p];
	if(l == r) return;
	int m = (l+r)/2;
	clone(ov,nv,tr[nv][p].ls,l,m);
	clone(ov,nv,tr[nv][p].rs,m+1,r);
}

void update(int vis,int p,int l,int r,int s,int t,ll val){
	pr("update() %d %d %d %d\n",nrt,l,r,tr[nrt].tag);
	if(s <= l && r <= t){ tr[p].sum += (l-r+1)*val,tr[p].tag += val; return; }
	if(l == r) return;
	int m = (l+r)/2;
	if(tr[p].tag){
		tr[vis][tr[p].ls].tag = tr[p].tag;
		tr[vis][tr[p].rs].tag = tr[p].tag;
		tr[vis][p].tag = 0;
	}
	if(s <= m) update(vis,tr[p].ls,l,m,s,t,val);
	if(t > m) update(vis,tr[p].rs,m+1,r,s,t,val);
	return;
}

ll query(int p,int l,int r,int s,int t){
	if(s <= l && r <= t) return tr[p].sum;
	int m = (l+r)/2;
	ll ret = 0;
	if(s <= m) ret += query(tr[p].ls,l,m,s,t);
	if(t > m) ret += query(tr[p].rs,m+1,r,s,t);
	return ret;
}

int main(){

    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
	int n,m,q,l,r,u,d; ll x,ans;
	
	sc("%d%d%d",&n,&m,&q);
	vector<int> vrt(m+5);
	vrt.push_back(build(1,n));
	REP(i,1,m){
		sc("%d%d%lld",&l,&r,&x);
		vrt.push_back(update(vrt.back(),1,n,l,r,x));
	}
	REP(i,1,q){
		sc("%d%d%d%d",&u,&d,&l,&r);
		ans = 0;
		REP(k,u,d){
			ans += query(vrt[k],1,n,l,r);
		}
		pr("%lld\n",ans);
	}

	return 0;
}

