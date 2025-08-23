#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 5e5 + 7, M = 1e5 + 7;

int ch[N][2], fa[N], siz[N];
bool rev[N];

bool get(int x) {
	return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}
void upd(int x) {
	if(x) siz[x] = 1 + siz[ch[x][0]] + siz[ch[x][1]];
}
void flip(int x) {
	if(x) rev[x] ^= 1, swap(ch[x][0], ch[x][1]);
}
void push(int x) {
	if(rev[x]) flip(ch[x][0]), flip(ch[x][1]), rev[x] = 0; 
}
void rotate(int x) {
	int y = fa[x], z = fa[y], fson = ch[y][1] == x, ano = ch[x][fson ^ 1];
	if(get(y)) ch[z][ch[z][1] == y] = x;
	if(ano) fa[ano] = y;
	fa[x] = z, fa[y] = x, ch[x][fson ^ 1] = y, ch[y][fson] = ano, upd(y), upd(x);
}
int F[N], ftot, fx;
void splay(int x) {
	F[ftot = 1] = fx = x;
	while(get(fx)) F[++ftot] = fx = fa[fx];
	while(ftot) push(F[ftot--]);
	while(get(x)) {
		int y = fa[x], z = fa[y];
		if(get(y)) rotate(((ch[y][1] == x) ^ (ch[z][1] == y)) ? x : y);
		rotate(x);
	}
}

void access(int x) {
	for(int y = 0; x; y = x, x = fa[x]) 
		splay(x), ch[x][1] = y, upd(x);
}
void makeroot(int x) {
	access(x), splay(x), flip(x);
}
void split(int x, int y) {
	makeroot(x), access(y), splay(y);
}
int findroot(int x) {
	access(x), splay(x); 
	while(ch[x][0]) push(x), x = ch[x][0];
	return splay(x), x;
}
void link(int x, int y) {
	makeroot(x);
	if(findroot(y) != x) fa[x] = y;
}
void cut(int x, int y) {
	makeroot(x);
	if(findroot(y) == x && ch[x][1] == y && !ch[y][0]) 
		fa[y] = ch[x][1] = 0, upd(x);
}

int kth(int x, int k) {
//	cout << siz[x] << ' ' << k << endl; 
	while(x) {
//		cout << siz[x] << "," << k << endl; 
		push(x);
		if(k <= siz[ch[x][0]]) x = ch[x][0];
		else {
			k -= siz[ch[x][0]] + 1;
			if(!k) return x;
			x = ch[x][1];
		}
	}
	return -1;
}

int type, n, m, lim, k, q, X[N], Y[N], tp;

set < pair < int, int > > sx[M];
set < pair < int, int > > sy[M];

set < int > e[N]; 

int OP[N];

void insert(int x, int y) {
	++tp, X[tp] = x, Y[tp] = y;
	auto rx = sx[x].lower_bound(make_pair(y, 0)), lx = rx;
	--lx;
	
	auto ry = sy[y].lower_bound(make_pair(x, 0)), ly = ry;
	--ly;
	
	int xl = lx -> second, xr = rx -> second;
	if(xl > lim) xl += !(xl & 1);
	if(xr > lim) xr -= xr & 1; 
	cut(xl, xr), link(xl, tp), link(tp + 1, xr);
	
	int yl = ly -> second, yr = ry -> second;
	if(yl > lim) yl -= yl & 1;
	if(yr > lim) yr += !(yr & 1); 
	cut(yl, yr), link(yl, tp + 1), link(tp, yr);
	
	++tp, X[tp] = x, Y[tp] = y;
	sx[x].insert(make_pair(y, tp));
	sy[y].insert(make_pair(x, tp));
}

int main() {
//	return system("fc corridor.out corridor2.ans"), 0;
	freopen("corridor.in", "r", stdin);
	freopen("corridor.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> type >> n >> m >> k;
	L(i, 1, n) ++tp, X[tp] = i, Y[tp] = 0, sx[i].insert(make_pair(0, tp));
	L(i, 1, n) ++tp, X[tp] = i, Y[tp] = m + 1, sx[i].insert(make_pair(m + 1, tp)), link(tp, tp - n);
	L(i, 1, m) ++tp, X[tp] = 0, Y[tp] = i, sy[i].insert(make_pair(0, tp));
	L(i, 1, m) ++tp, X[tp] = n + 1, Y[tp] = i, sy[i].insert(make_pair(n + 1, tp)), link(tp, tp - m);
	++tp, lim = tp;
	L(i, 1, (n + m) * 2) if(X[i] == n + 1 || Y[i] == m + 1) link(i, lim);
	L(i, 1, k) {
		int x, y;
		cin >> x >> y;
		insert(x, y); 
	}
	cin >> q;
	while(q--) {
		int op, x, y, q;
		cin >> op >> x >> y;
		if(op == 1) {
			insert(x, y);
		} else {
			cin >> q; 
			int cur = x;
			if(x == 0) cur = n * 2 + y;
			split(cur, lim);
			q = min(q, siz[lim] - 2) + 1; 
			cur = kth(lim, q); 
			cout << X[cur] << ' ' << Y[cur] << '\n';
		}
	}
	return 0;
}