#include <bits/stdc++.h>
#define pre(i) (i - 1)
#define nxt(i) (i + 1)
using namespace std;
typedef pair <int, int> P;

inline int read() {
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    return x;
}
void write(int x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return ;
}

const int N = 1000005, M = 25;

int n, q;
P opt[N];

int lft[N], rgt[N];
inline void brk(int x, int* l, int* r) {
    int lx = l[x], rx = r[x];
    l[rx] = lx, r[lx] =rx;
    return ;
}
int lt[N], rt[N];
inline int Solve_B(int m) {
    if (rgt[0] > n) return -1;
    memcpy(lt, lft, sizeof lft), memcpy(rt, rgt, sizeof rgt);
    int ans = 0;
    while (rt[0] <= n) {
        for (int j = rt[0], cnt = 0; j <= n; j = rt[j]) {
            ++cnt;
            if (cnt % m == 1) ans = j, brk(j, lt, rt);
        }
        if (rt[0] > n) return ans;
        for (int j = lt[nxt(n)], cnt = 0; j; j = lt[j]) {
            ++cnt;
            if (cnt % m == 1) ans = j, brk(j, lt, rt);
        }
    }
    return ans;
}
inline void Brute() {
    for (int i = 1; i <= n; ++i) lft[i] = pre(i), rgt[i] = nxt(i);
    rgt[0] = 1, lft[nxt(n)] = n;
    for (int i = 1; i <= q; ++i) {
        int tp = opt[i].first, m = opt[i].second;
        if (tp == 1)
            for (int j = rgt[0]; j <= n; j = rgt[j])
                if (j % m == 1) brk(j, lft, rgt);
                else ;
        else if (tp == 2)
            for (int j = rgt[0], cnt = 0; j <= n; j = rgt[j]) {
                ++cnt;
                if (cnt % m == 1) brk(j, lft, rgt);
            }
        else write(Solve_B(m)), putchar('\n');
    }
    return ;
}

int res[M];
void Solve_2() {
    for (int i = 1; i <= n; ++i) lft[i] = pre(i), rgt[i] = nxt(i);
    lft[nxt(n)] = n, rgt[0] = 1;
    for (int m = 2; m <= 20; ++m) res[m] = Solve_B(m);
    for (int i = 1; i <= q; ++i) write(res[opt[i].second]), putchar('\n');
    return ;
}

int main() {
	freopen("bounce.in", "r", stdin), freopen("bounce.out", "w", stdout);
    n = read(), q = read();
    bool check_2 = true;
    for (int i = 1; i <= q; ++i) {
        opt[i].first = read(), opt[i].second = read();
        if (opt[i].first != 3) check_2 = false;
    }
    if (n <= 1000 && q <= 1000) Brute();
    else if (check_2) Solve_2();
    return 0;
}
