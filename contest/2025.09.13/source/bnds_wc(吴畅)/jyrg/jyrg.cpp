#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 100005
#define int long long
using namespace std;
const int INF = 2e18;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
mt19937 Rand(time(NULL));
int n, a[maxn], rt;
unordered_map<int, int> vis;
int ch[maxn][2], rnk[maxn], val[maxn], mx[maxn], rnd[maxn], tag[maxn], siz[maxn], tot;
inline int new_node(int a, int b) {
	tot++;
	rnk[tot] = a, val[tot] = mx[tot] = b;
	ch[tot][0] = ch[tot][1] = 0, siz[tot] = 1, rnd[tot] = Rand() % (int)(1e9), tag[tot] = 0;
	return tot;
}
inline void work(int x, int v) {
	tag[x] += v, val[x] += v, mx[x] += v;
}
inline void pushdown(int x) {
	if(ch[x][0]) work(ch[x][0], tag[x]);
	if(ch[x][1]) work(ch[x][1], tag[x]);
	tag[x] = 0;
}
inline void pushup(int x) {
	mx[x] = max(max(mx[ch[x][0]], mx[ch[x][1]]), val[x]);
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}
void split(int now, int k, int &x, int &y) {
	if(!now) {x = y = 0; return;}
	pushdown(now);
	if(rnk[now] > k) {
		x = now;
		split(ch[now][1], k, ch[x][1], y);
	}
	else {
		y = now;
		split(ch[now][0], k, x, ch[y][0]);
	}
	pushup(now);
}
int merge(int x, int y) {
	if(!x || !y) return x + y;
	if(rnd[x] <= rnd[y]) {
		pushdown(x);
		ch[x][1] = merge(ch[x][1], y);
		pushup(x);
		return x;
	}
	else {
		pushdown(y);
		ch[y][0] = merge(x, ch[y][0]);
		pushup(y);
		return y;
	}
}
/*
void dfs(int x) {
	if(!x) return;
	pushdown(x);
	dfs(ch[x][0]);
	printf("%d %d %d\n", rnk[x], val[x], mx[x]);
	dfs(ch[x][1]);
}
*/
void solve() {
	tot = rt = 0, mx[0] = val[0] = -INF;
	n = read(); vis.clear();
	int fl = 1;
	ru(i, 1, n) {
		a[i] = read();
		fl &= !vis[a[i] - i];
		vis[a[i] - i] = 1;
	}
	if(!fl) {printf("-1\n"); return;}
	int las = 0, ans = 0;
	ru(i, 1, n) {
		int x, y, z;
		split(rt, a[i] - i, x, y);
		ans = max(ans, a[i] + mx[y]);
		work(x, -1), work(y, 1);
		rt = merge(x, merge(new_node(a[i] - i, a[i] - 2 * siz[y]), y));
		//printf("----\n");
		//dfs(rt);
	}
	printf("%lld\n", ans);
}
signed main() {
	freopen("jyrg.in", "r", stdin);
	freopen("jyrg.out", "w", stdout);
	int T = read();
	while(T--) solve();
	return 0;
}