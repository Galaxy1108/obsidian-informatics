#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2.5e5 + 5, p = 998244353,
mts = 4;
int a[N], b[N], c[N], n, m, op, l, r, v;
struct Mtrx {
    int v[mts][mts];
    int * operator [] (int p) {
        return v[p];
    }
    void init_e() {
        memset(v, 0, sizeof(v));
        v[0][0] = v[1][1] =
        v[2][2] = v[3][3] = 1;
    }
};
Mtrx operator * (Mtrx a, Mtrx b) {
    Mtrx ans;
    ans[0][0] =
    (a[0][0] * b[0][0] + a[0][1] * b[1][0] +
    a[0][2] * b[2][0] + a[0][3] * b[3][0]) % p;
    ans[0][1] =
    (a[0][0] * b[0][1] + a[0][1] * b[1][1] +
    a[0][2] * b[2][1] + a[0][3] * b[3][1]) % p;
    ans[0][2] =
    (a[0][0] * b[0][2] + a[0][1] * b[1][2] +
    a[0][2] * b[2][2] + a[0][3] * b[3][2]) % p;
    ans[0][3] =
    (a[0][0] * b[0][3] + a[0][1] * b[1][3] +
    a[0][2] * b[2][3] + a[0][3] * b[3][3]) % p;
    ans[1][0] =
    (a[1][0] * b[0][0] + a[1][1] * b[1][0] +
    a[1][2] * b[2][0] + a[1][3] * b[3][0]) % p;
    ans[1][1] =
    (a[1][0] * b[0][1] + a[1][1] * b[1][1] +
    a[1][2] * b[2][1] + a[1][3] * b[3][1]) % p;
    ans[1][2] =
    (a[1][0] * b[0][2] + a[1][1] * b[1][2] +
    a[1][2] * b[2][2] + a[1][3] * b[3][2]) % p;
    ans[1][3] =
    (a[1][0] * b[0][3] + a[1][1] * b[1][3] +
    a[1][2] * b[2][3] + a[1][3] * b[3][3]) % p;
    ans[2][0] =
    (a[2][0] * b[0][0] + a[2][1] * b[1][0] +
    a[2][2] * b[2][0] + a[2][3] * b[3][0]) % p;
    ans[2][1] =
    (a[2][0] * b[0][1] + a[2][1] * b[1][1] +
    a[2][2] * b[2][1] + a[2][3] * b[3][1]) % p;
    ans[2][2] =
    (a[2][0] * b[0][2] + a[2][1] * b[1][2] +
    a[2][2] * b[2][2] + a[2][3] * b[3][2]) % p;
    ans[2][3] =
    (a[2][0] * b[0][3] + a[2][1] * b[1][3] +
    a[2][2] * b[2][3] + a[2][3] * b[3][3]) % p;
    ans[3][0] =
    (a[3][0] * b[0][0] + a[3][1] * b[1][0] +
    a[3][2] * b[2][0] + a[3][3] * b[3][0]) % p;
    ans[3][1] =
    (a[3][0] * b[0][1] + a[3][1] * b[1][1] +
    a[3][2] * b[2][1] + a[3][3] * b[3][1]) % p;
    ans[3][2] =
    (a[3][0] * b[0][2] + a[3][1] * b[1][2] +
    a[3][2] * b[2][2] + a[3][3] * b[3][2]) % p;
    ans[3][3] =
    (a[3][0] * b[0][3] + a[3][1] * b[1][3] +
    a[3][2] * b[2][3] + a[3][3] * b[3][3]) % p;
    return ans;
}
struct XL {
    int v[mts];
    int & operator [] (int p) {
        return v[p];
    }
};
XL operator + (XL a, XL b) {
    XL ans;
    ans[0] = (a[0] + b[0]) % p;
    ans[1] = (a[1] + b[1]) % p;
    ans[2] = (a[2] + b[2]) % p;
    ans[3] = (a[3] + b[3]) % p;
    return ans;
}
XL operator * (XL a, Mtrx b) {
    XL ans;
    ans[0] = (a[0] * b[0][0] + a[1] * b[1][0] +
    a[2] * b[2][0] + a[3] * b[3][0]) % p;
    ans[1] = (a[0] * b[0][1] + a[1] * b[1][1] +
    a[2] * b[2][1] + a[3] * b[3][1]) % p;
    ans[2] = (a[0] * b[0][2] + a[1] * b[1][2] +
    a[2] * b[2][2] + a[3] * b[3][2]) % p;
    ans[3] = (a[0] * b[0][3] + a[1] * b[1][3] +
    a[2] * b[2][3] + a[3] * b[3][3]) % p;
    return ans;
}
struct node {
    XL v;
    Mtrx fl;
} t[N << 2];
void pushup(int o) {
    t[o].v = t[o << 1].v + t[(o << 1) | 1].v;
}
void build(int o, int L, int R) {
    if (L < R) {
        int M = (L + R) >> 1;
        t[o].fl.init_e();
        build(o << 1, L, M);
        build((o << 1) | 1, M + 1, R);
        pushup(o);
    } else
        t[o].v[0] = a[L], t[o].v[1] = b[L],
        t[o].v[2] = c[L];
    t[o].v[3] = R - L + 1;
}
void pushdown(int o, int L, int R) {
    int M = (L + R) >> 1;
    t[o << 1].v = t[o << 1].v * t[o].fl;
    t[o << 1].fl = t[o << 1].fl * t[o].fl;
    t[(o << 1) | 1].v =
    t[(o << 1) | 1].v * t[o].fl;
    t[(o << 1) | 1].fl =
    t[(o << 1) | 1].fl * t[o].fl;
    t[o].fl.init_e();
}
void update(int l, int r, Mtrx v,
int o, int L, int R) {
    if (l > L || R > r) {
        int M = (L + R) >> 1;
        pushdown(o, L, R);
        if (l <= M)
            update(l, r, v, o << 1, L, M);
        if (r > M)
            update(l, r, v, (o << 1) | 1,
            M + 1, R);
        pushup(o);
    } else
        t[o].v = t[o].v * v,
        t[o].fl = t[o].fl * v;
}
XL query(int l, int r, int o, int L, int R) {
    if (l > L || R > r) {
        int M = (L + R) >> 1;
        pushdown(o, L, R);
        XL ans;
        ans[0] = ans[1] = ans[2] = ans[3] = 0;
        if (l <= M) ans = ans +
            query(l, r, o << 1, L, M);
        if (r > M) ans = ans +
            query(l, r, (o << 1) | 1, M + 1, R);
        return ans;
    }
    return t[o].v;
}
Mtrx op1() {
    Mtrx ans;ans.init_e();
    ans[1][0] = 1;return ans;
}
Mtrx op2() {
    Mtrx ans;ans.init_e();
    ans[2][1] = 1;return ans;
}
Mtrx op3() {
    Mtrx ans;ans.init_e();
    ans[0][2] = 1;return ans;
}
Mtrx op4(int v) {
    Mtrx ans;ans.init_e();
    ans[3][0] = v;return ans;
}
Mtrx op5(int v) {
    Mtrx ans;ans.init_e();
    ans[1][1] = v;return ans;
}
Mtrx op6(int v) {
    Mtrx ans;ans.init_e();
    ans[2][2] = 0, ans[3][2] = v;
    return ans;
}
signed main() {
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> op >> l >> r;
        if (op == 1)
            update(l, r, op1(), 1, 1, n);
        else if (op == 2)
            update(l, r, op2(), 1, 1, n);
        else if (op == 3)
            update(l, r, op3(), 1, 1, n);
        else if (op == 7) {
            XL ans = query(l, r, 1, 1, n);
            cout << ans[0] << ' ' <<
            ans[1] << ' ' << ans[2] << '\n';
        } else {
            cin >> v;
            if (op == 4)
                update(l, r, op4(v), 1, 1, n);
            if (op == 5)
                update(l, r, op5(v), 1, 1, n);
            if (op == 6)
                update(l, r, op6(v), 1, 1, n);
        }
    }
    return 0;
}
//10:00 T1 AC
