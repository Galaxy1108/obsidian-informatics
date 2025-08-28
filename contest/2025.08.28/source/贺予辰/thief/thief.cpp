#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], l, r, c;
// const int N = 5e5 + 5;
// struct node{
//     int val, pri, siz, lson, rson, fl;
// } t[N];
// int root = 0;
// void maintain(int p) {
//     t[p].siz =
//     t[t[p].lson].siz + t[t[p].lson].siz + 1;
// }
// void pushdown(int p) {
//     t[p].val += t[p].fl;
//     t[t[p].lson].fl += t[p].fl;
//     t[t[p].rson].fl += t[p].fl;
//     t[p].fl = 0;
// }
// void split(int val, int pos, int &l, int &r) {
//     if (!pos) {
//         l = r = 0;
//         return;
//     }
//     pushdown(pos);
//     if (t[pos].val <= val) l = pos,
//         split(val, t[pos].rson, t[pos].rson, r);
//     else r = pos,
//         split(val, t[pos].lson, l, t[pos].lson);
//     maintain(pos);
// }
// int merge(int l, int r) {
//     if (!l || !r) return l | r;
//     if (t[l].pri < t[r].pri) {
//         pushdown(l);
//         merge(t[l].rson, r);
//         maintain(l);
//         return l;
//     } else {
//         pushdown(l);
//         merge(l, t[r].lson);
//         maintain(r);
//         return r;
//     }
// }
// int newnode(int val) {
//     static int cnt = 0;
//     t[++cnt].val = val;
//     t[cnt].pri = rand();
//     t[cnt].siz = 1;
//     t[cnt].lson = t[cnt].rson =
//     t[cnt].fl = 0;
//     return cnt;
// }
// void insert(int val) {
//     int l, r;
//     split(val, root, l, r);
//     root = merge(merge(l, newnode(val)), r);
// }
signed main() {
    freopen("thief.in", "r", stdin);
    freopen("thief.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r >> c;
        for (int j = l; j <= r; ++j)
            if (c < a[j]) ++c;
            else if (c > a[j]) --c;
        cout << c << '\n';
    }
    return 0;
}