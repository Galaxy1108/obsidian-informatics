#include<bits/stdc++.h>
#define L(i,j,k) for(int i = (j); i <= (k); ++i)
#define R(i,j,k) for(int i = (j); i >= (k); --i)
#define ll long long
#define ls wi<<1, l, mi
#define rs wi<<1|1, mi + 1, r
using namespace std;
const int N = 1e5 + 6;
const ll M = 1e9 + 9;
int lx[N], rx[N]; ll xx[N];
int n, m ,q;
inline void chek(ll &s){
	if(s > M) s -= M;
	if(s < 0) s += M; 
}
struct qwq{
	int l, r;
	int op, id;
};
vector <qwq> Q[N];
ll ans[N];
ll tr[2][N<<2];
ll tag[2][N<<2];
void upd(int nw ,int wi){
	tr[nw][wi] = (tr[nw][wi << 1] + tr[nw][wi << 1|1] )%M;
}
void ff(int nw, int wi, int l, int r, ll x){
	tag[nw][wi] += x; chek(tag[nw][wi]); 
	tr[nw][wi] += ((r - l + 1) * x %M) ; chek(tr[nw][wi]);
}
void down(int nw ,int wi, int l, int r){
	if(tag[nw][wi] == 0) return ;
	int mi = (l + r) >> 1;
	ff(nw, ls, tag[nw][wi]); ff(nw, rs, tag[nw][wi]);
	tag[nw][wi] = 0;
}
void add(int nw, int wi, int l, int r, int L, int R, ll x){
	if(L <= l && r <= R){
		ff(nw, wi, l, r, x);
		return;
	}
	down(nw, wi, l , r);
	int mi = (l + r)>>1;
	if(L <= mi){
		add(nw, ls, L, R, x);
	}
	if(R > mi) add(nw, rs, L, R, x);
	upd(nw, wi);
}
ll query(int nw, int wi, int l, int r, int L, int R){
	if(L <= l && r <= R){
		return tr[nw][wi];
	}
	down(nw, wi, l, r);
	ll as = 0;
	int mi = (l + r) >> 1;
	if(L <= mi) as += query(nw, ls, L, R);
	if(R > mi) as+= query(nw, rs, L, R);
	as %= M;
	return as;
} 
void solve(){
	ll az;
	L(i, 1, m){
		add(0, 1, 1, n, lx[i], rx[i], xx[i]);
		add(1, 1, 1, n, lx[i], rx[i], (xx[i] * (i - 1)) % M);
		for(auto v:Q[i]){
			az = i * query(0, 1, 1, n, v.l, v.r) - query(1, 1, 1, n, v.l, v.r);
			az %= M;
			ans[v.id] = ans[v.id] + v.op * az;
		}
	}
}
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	L(i, 1, m){
		cin >> lx[i] >> rx[i] >> xx[i];
	}
	int u, d, l ,r;
	L(i, 1, q){
		cin >> u >> d >> l >> r;
		if(u == 0) ++u;
		Q[u - 1].push_back((qwq){l, r, -1, i});
		Q[d].push_back((qwq){l, r, 1, i});
	}
	solve();
	L(i, 1, q){
		cout << (ans[i] % M + M) % M <<"\n";
	}
	return 0;
}

