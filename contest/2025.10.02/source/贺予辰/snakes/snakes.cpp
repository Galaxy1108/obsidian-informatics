#include<bits/stdc++.h>
using namespace std;
struct node {
    int val, pri, siz, lson, rson;
} t[1000006];
int root = 0, cnt = 0;
void init() {
    root = cnt = 0;
}
int newnode(int v) {
    t[++cnt] = (node) {v, rand(), 1, 0, 0};
    return cnt;
}
void pushup(int o) {
    t[o].siz = 1 +
    t[t[o].lson].siz + t[t[o].rson].siz;
}
void split(int o, int v, int &l, int &r) {
    if (!o) {
        l = r = 0;
        return;
    }
    if (t[o].val <= v) l = o,
        split(t[o].rson, v, t[o].rson, r);
    else r = o,
        split(t[o].lson, v, l, t[o].lson);
    pushup(o);
}
int merge(int l, int r) {
    if (!l || !r) return l + r;
    if (t[l].pri < t[r].pri) {
        t[l].rson = merge(t[l].rson, r);
        pushup(l);
        return l;
    }
    t[r].lson = merge(l, t[r].lson);
    pushup(r);
    return r;
}
void insert(int v) {
    int l, r;
    split(root, v, l, r);
    root = merge(merge(l, newnode(v)), r);
}
void del(int v) {
    int l, m, r;
    split(root, v, l, r);
    split(l, v - 1, l, m);
    m = merge(t[m].lson, t[m].rson);
    root = merge(merge(l, m), r);
}
int rnk(int v) {
    int ans, l, r;
    split(root, v - 1, l, r);
    ans = t[l].siz;
    root = merge(l, r);
    return ans + 1;
}
int tmax() {
    int o = root;
    while (t[o].rson) o = t[o].rson;
    return t[o].val;
}
int tmin() {
    int o = root;
    while (t[o].lson) o = t[o].lson;
    return t[o].val;
}
int n, a[1000006], T;
int solve() {
    init();
    for (int i = 1; i <= n; ++i)
        insert(a[i]);
    while ("XJR AK IOI") {
        if (t[root].siz == 1) return 1;
        int vmin = tmin(), vmax = tmax();
        if (rnk(vmax - vmin) <= 2
        && t[root].siz > 2)
            break;
        del(vmin), del(vmax), insert(vmax - vmin);
    }
    return t[root].siz - ((t[root].siz & 1) ^ 1);
}
int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    t[0] = (node) {0, 0, 0, 0, 0};
    cin >> T >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << solve() << '\n';
    while (--T) {
        int p, q, w;
        cin >> w;
        for (int i = 1; i <= w; ++i)
            cin >> p >> q, a[p] = q;
        cout << solve() << '\n';
    }
    return 0;
}
