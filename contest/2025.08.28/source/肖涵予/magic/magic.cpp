#include <bits/stdc++.h>
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
using namespace std;
typedef long long ll;
constexpr int Mod = 998244353;
constexpr int N = 3e5;
constexpr int T = (N << 3);
int n, m, A[N], B[N], C[N], opt[N], l[N], r[N], v[N];
struct SMT {
	int sumA, sumB, sumC;
	int tagA, tagB, tagC;
} tr[T];
struct Sump {
	int sumA, sumB, sumC;
	Sump () = default;
	Sump (int sumA, int sumB, int sumC) : sumA(sumA), sumB(sumB), sumC(sumC) {}
};
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
	for(int t = 1; t <= m; ++t) {
		int ropt = opt[t], rl = l[t], rr = r[t], rv = v[t];
		if (ropt == 1)
			for (int i = rl; i <= rr; ++i)
				A[i] = (A[i] + B[i]) % Mod;
		else if (ropt == 2)
			for (int i = rl; i <= rr; ++i)
				B[i] = (B[i] + C[i]) % Mod;
		else if (ropt == 3)
			for (int i = rl; i <= rr; ++i)
				C[i] = (C[i] + A[i]) % Mod;
		else if (ropt == 4)
			for (int i = rl; i <= rr; ++i)
				A[i] = (A[i] + rv) % Mod;
		else if (ropt == 5)
			for (int i = rl; i <= rr; ++i)
				B[i] = ((ll)B[i] * rv) % Mod;
		else if (ropt == 6)
			for (int i = rl; i <= rr; ++i)
				C[i] = rv;
		else {
			int sumA = 0, sumB = 0, sumC = 0;
			for (int i = rl; i <= rr; ++i)
				sumA = (sumA + A[i]) % Mod, sumB = (sumB + B[i]) % Mod, sumC = (sumC + C[i]) % Mod;
			write(sumA), putchar(' '), write(sumB), putchar(' '), write(sumC), putchar('\n');
		}
	}
	return ;
}
void addtag(int p, int l, int r, int add, int mul, int cov) {
	if (add)
		tr[p].sumA = (tr[p].sumA + (ll)add * (r - l + 1) % Mod) % Mod, tr[p].tagA = (tr[p].tagA + add) % Mod;
	if (mul > 1)
		tr[p].sumB = ((ll)tr[p].sumB * mul) % Mod, tr[p].tagB = ((ll)tr[p].tagB * mul) % Mod;
	if (~cov)
		tr[p].sumC = (ll)cov * (r - l + 1) % Mod, tr[p].tagC = cov;
	return ;
}
void push_up(int p) {
	tr[p].sumA = (tr[ls(p)].sumA + tr[rs(p)].sumA) % Mod;
	tr[p].sumB = (tr[ls(p)].sumB + tr[rs(p)].sumB) % Mod;
	tr[p].sumC = (tr[ls(p)].sumC + tr[rs(p)].sumC) % Mod;
	return ;
}
void push_down(int p, int l, int r) {
	int mid = (l + r) >> 1;
	addtag(ls(p), l, mid, tr[p].tagA, tr[p].tagB, tr[p].tagC);
	addtag(rs(p), mid + 1, r, tr[p].tagA, tr[p].tagB, tr[p].tagC);
	tr[p].tagA = 0, tr[p].tagB = 1, tr[p].tagC = -1;
	return ;
}
void Build(int p, int l, int r) {
	tr[p].tagA = 0, tr[p].tagB = 1, tr[p].tagC = -1;
	if (l == r) {
		tr[p].sumA = A[l], tr[p].sumB = B[l], tr[p].sumC = C[l];
		return ;
	}
	int mid = (l + r) >> 1;
	Build(ls(p), l, mid), Build(rs(p), mid + 1, r);
	push_up(p);
	return ;
}
Sump Query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R)
		return Sump(tr[p].sumA, tr[p].sumB, tr[p].sumC);
	push_down(p, l, r);
	int mid = (l + r) >> 1, sumA = 0, sumB = 0, sumC = 0;
	if (L <= mid) {
		Sump tmp = Query(ls(p), l, mid, L, R);
		sumA = (sumA + tmp.sumA) % Mod, sumB = (sumB + tmp.sumB) % Mod, sumC = (sumC + tmp.sumC) % Mod;
	}
	if (R > mid) {
		Sump tmp = Query(rs(p), mid + 1, r, L, R);
		sumA = (sumA + tmp.sumA) % Mod, sumB = (sumB + tmp.sumB) % Mod, sumC = (sumC + tmp.sumC) % Mod;
	}
	return Sump(sumA, sumB, sumC);
}
void Update(int p, int l, int r, int L, int R, int add, int mul, int cov) {
	if (L <= l && r <= R) {
		addtag(p, l, r, add, mul, cov);
		return ;
	}
	push_down(p, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid)
		Update(ls(p), l, mid, L, R, add, mul, cov);
	if (R > mid)
		Update(rs(p), mid + 1, r, L, R, add, mul, cov);
	push_up(p);
	return ;
}
void Solve_Sub2(void) {
	Build(1, 1, n);
	for (int t = 1; t <= m; ++t) {
		int ropt = opt[t], rl = l[t], rr = r[t], rv = v[t];
		if (ropt == 4)
			Update(1, 1, n, rl, rr, rv, 1, -1);
		else if (ropt == 5)
			Update(1, 1, n, rl, rr, 0, rv, -1);
		else if (ropt == 6)
			Update(1, 1, n, rl, rr, 0, 1, rv);
		else {
			Sump tmp = Query(1, 1, n, rl, rr);
			write(tmp.sumA), putchar(' '), write(tmp.sumB), putchar(' '), write(tmp.sumC), putchar('\n');
		}
	}
	return ;
}
void Solve_Sub3(void) {
	return ;
}
int main(void) {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i)
		A[i] = read(), B[i] = read(), C[i] = read();
	m = read();
	bool flag_Sub2 = true, flag_Sub3 = true;
	for (int i = 1; i <= m; ++i) {
		opt[i] = read(), l[i] = read(), r[i] = read();
		if (opt[i] >= 4 && opt[i] <= 6)
			v[i] = read(); 
		if (opt[i] <= 3)
			flag_Sub2 = false;
		else
			flag_Sub3 = false;
	}
	if (n <= 1000 && m <= 1000) {
		Solve_Sub1();
		return 0;
	}
	if (flag_Sub2) {
		Solve_Sub2();
		return 0;
	}
	if (flag_Sub3) {
		Solve_Sub3();
		return 0;
	}
	return 0;
}
