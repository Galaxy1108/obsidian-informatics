#include<bits/stdc++.h>
#define int long long
#define IL inline
#define RG register
using namespace std;
const int p = 1e9 + 9;
int n, m, q, root[100005], cnt = 0, ct = 0;
struct node {
    int val, fl, lson, rson;
} t[8000007];
IL int clone(int o) {
    t[++cnt] = t[o];
    return cnt;
}
IL void pushup(int o, int L, int R) {
    t[o].val = (t[t[o].lson].val + t[t[o].rson].val +
    t[o].fl * (R - L + 1) % p) % p;
}
IL void build(int &o, int L, int R) {
    o = ++cnt;
    t[o].val = 0, t[o].fl = 0;
    t[o].lson = 0, t[o].rson = 0;
    if (L < R) {
        RG int M = (L + R) >> 1;
        build(t[o].lson, L, M);
        build(t[o].rson, M + 1, R);
    }
}
IL void update(int l, int r, int v, int &o, int L, int R) {
    o = clone(o);
    if (l > L || R > r) {
        RG int M = (L + R) >> 1;
        if (l <= M)
            update(l, r, v, t[o].lson, L, M);
        if (r > M)
            update(l, r, v, t[o].rson, M + 1, R);
    } else t[o].fl = (t[o].fl + v + p) % p;
    pushup(o, L, R);
}
IL int query(int l, int r, int o, int L, int R) {
    if (l > L || R > r) {
        RG int ans = t[o].fl *
        (min(R, r) - max(L, l) + 1) % p,
        M = (L + R) >> 1;
        if (l <= M) ans = (ans +
            query(l, r, t[o].lson, L, M)) % p;
        if (r > M) ans = (ans +
            query(l, r, t[o].rson, M + 1, R)) % p;
        return ans;
    } else return t[o].val;
}
IL int read() {
    RG int ans = 0, fl = 1;
    RG char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans * fl;
}
IL void write(int n) {
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
signed main() {
    freopen("newfile.in", "r", stdin);
    freopen("newfile.out", "w", stdout);
    n = read(), m = read(), q = read();
    build(root[ct++], 1, n);
    for (RG int i = 1; i <= m; ++i) {
        RG int l = read(), r = read(), v = read();
        root[ct] = root[ct - 1];
        update(l, r, v, root[ct], 1, n);
        ++ct;
    }
    for (RG int i = 1; i <= q; ++i) {
        RG int u = read(), d = read(),
        l = read(), r = read(), ans = 0;
        for (int j = u; j <= d; ++j)
            ans = (ans +
            query(l, r, root[j], 1, n)) % p;
        write(ans), putchar('\n');
    }
    return 0;
}
