#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 800005
#define ll long long
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int tp, n, m, k, tot;
int fa[maxn], ch[maxn][2], siz[maxn];
inline int I(int x) {
	if(ch[fa[x]][0] == x) return 0;
	if(ch[fa[x]][1] == x) return 1;
	return -1;
}
inline void pushup(int x) {
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}
void rotate(int x) {
	int y = fa[x], z = fa[y], k = I(x), tmp = ch[x][!k];
	if(I(y) != -1) ch[z][I(y)] = x; fa[x] = z;
	fa[y] = x, ch[x][!k] = y;
	fa[tmp] = y, ch[y][k] = tmp;
	pushup(y);
}
void splay(int x) {
	while(I(x) != -1) {
		int y = fa[x], z = fa[y];
		if(I(y) != -1) {
			if(I(x) == I(y)) rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	pushup(x);
} 
void access(int x) {
	for (int y = 0; x; x = fa[y = x]) splay(x), ch[x][1] = y, pushup(x);
}
void link(int x, int y) {
	fa[x] = y;
}
void cut(int x, int y) {
	access(x), splay(y);
	fa[x] = ch[y][1] = 0, pushup(y);
}
int X[maxn], Y[maxn];
set<int> row[50005], col[50005];
set<int>::iterator it;
struct node {
	int x, y, z;
	inline bool operator < (const node &a) const {
		if(x == a.x) {
			if(y == a.y) return z < a.z;
			return y < a.y;
		}
		return x < a.x;
	}
};
map<node, int> id;
void add(int x, int y) {
	it = row[x].lower_bound(y);
	int R = id[{x, (*it), 1}]; int L = id[{x, (*--it), 0}];
	it = col[y].lower_bound(x);
	int D = id[{(*it), y, 0}]; int U = id[{(*--it), y, 1}];
	int a = id[{x, y, 0}] = ++tot;
	int b = id[{x, y, 1}] = ++tot;
	X[tot] = X[tot - 1] = x, Y[tot] = Y[tot - 1] = y, siz[tot] = siz[tot - 1] = 1;
	//printf("!! %d %d %d %d %d %d %d %d\n", X[L], Y[L], X[R], Y[R], X[U], Y[U], X[D], Y[D]);
	cut(L, R), cut(U, D);
	link(L, b), link(b, D);
	link(U, a), link(a, R);
	row[x].insert(y), col[y].insert(x);
}
int find(int x, int step) {
	if(step == siz[ch[x][1]] + 1) return x;
	if(step <= siz[ch[x][1]]) return find(ch[x][1], step);
	return find(ch[x][0], step - siz[ch[x][1]] - 1);
}
void query(int x, int y, int step) {
	int pos = id[{x, y, x == 0}];
	access(pos);
	//for (int i = pos; i; i = fa[i]) printf("%d %d  ", X[i], Y[i]); printf("\n");
	splay(pos);
	pos = ch[pos][0], step = min(step, siz[pos]);
	pos = find(pos, step);
	printf("%d %d\n", X[pos], Y[pos]);
}
int main() {
	freopen("corridor.in", "r", stdin);
	freopen("corridor.out", "w", stdout);
	tp = read(), n = read(), m = read(), k = read();
	ru(i, 1, n) {
		row[i].insert(0), row[i].insert(m + 1);
		id[{i, 0, 0}] = ++tot, X[tot] = i, Y[tot] = 0;
		id[{i, m + 1, 1}] = ++tot, X[tot] = i, Y[tot] = m + 1;
		link(2 * i - 1, 2 * i);
	}
	ru(i, 1, m) {
		col[i].insert(0), col[i].insert(n + 1);
		id[{0, i, 1}] = ++tot, X[tot] = 0, Y[tot] = i;
		id[{n + 1, i, 0}] = ++tot, X[tot] = n + 1, Y[tot] = i;
		link(2 * (n + i) - 1, 2 * (n + i));
	}
	ru(i, 1, 2 * (n + m)) siz[i] = 1;
	ru(i, 1, k) {
		int x = read(), y = read();
		add(x, y);
	}
	int q = read();
	while(q--) {
		int opt = read(), x = read(), y = read();
		if(opt == 1) add(x, y);
		else query(x, y, read());
	}
	return 0;
}