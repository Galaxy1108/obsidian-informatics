#include <bits/stdc++.h>
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
using namespace std;
constexpr int N = 5e5 + 3;
constexpr int T = (N << 2);
int n, m, a[N], l[N], r[N], c[N];
int tr[T][21];
int read(void) {
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}
void write(int x) {
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
void Solve_Sub1(void) {
	for (int t = 1; t <= m; ++t) {
		int rl = l[t], rr = r[t], now = c[t];
		for (int i = rl; i <= rr; ++i)
			if (now < a[i])
				++now;
			else if (now > a[i])
				--now;
		write(now), putchar('\n');
	}
	return ;
}
void push_up(int p) {
	for (int now = 0; now <= 20; ++now)
		tr[p][now] = tr[rs(p)][tr[ls(p)][now]];
	return ;
}
void Build(int p, int l, int r) {
	if (l == r) {
		for (int now = 0; now <= 20; ++now)
			if (now < a[l])
				tr[p][now] = now + 1;
			else if (now > a[l])
				tr[p][now] = now - 1;
			else
				tr[p][now] = now;
		return ;
	}
	int mid = (l + r) >> 1;
	Build(ls(p), l, mid), Build(rs(p), mid + 1, r);
	push_up(p);
	return ;
}
int Query(int p, int l, int r, int L, int R, int now) {
	if (L <= l && r <= R)
		return tr[p][now];
	int mid = (l + r) >> 1;
	if (L <= mid && R <= mid)
		return Query(ls(p), l, mid, L, R, now);
	if (L > mid && R > mid)
		return Query(rs(p), mid + 1, r, L, R, now);
	int nxt = Query(ls(p), l, mid, L, mid, now);
	return Query(rs(p), mid + 1, r, mid + 1, R, nxt);
}
int main(void) {
	freopen("thief.in", "r", stdin);
	freopen("thief.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 1; i <= m; ++i)
		l[i] = read(), r[i] = read(), c[i] = read();
	if (n <= 1000 && m <= 1000) {
		Solve_Sub1();
		return 0; 
	}
	Build(1, 1, n);
	for (int t = 1; t <= m; ++t) {
		int rl = l[t], rr = r[t], now = c[t];
		write(Query(1, 1, n, rl, rr, now)), putchar('\n');
	}
	return 0;
}
