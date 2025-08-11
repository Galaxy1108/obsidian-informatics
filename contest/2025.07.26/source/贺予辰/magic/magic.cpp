#include<bits/stdc++.h>
using namespace std;
int a[200005], n, m, ans[1000006];
struct Q {
    int t, i, id;
    bool operator < (Q b) {
        return t < b.t;
    }
} q[1000006];
inline int read() {
    int ans = 0, fl = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans;
}
inline void write(int n) {
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
inline void upd() {
    int a0[200005], a1[200005];
    for (int i = 1; i <= (n >> 1); ++i)
        a0[i] = a[i], a1[i] = a[i + (n >> 1)];
    int l0 = 1, l1 = 1, i = 1;
    while (l0 <= (n >> 1) && l1 <= (n >> 1)) {
        if (a0[l0] < a1[l1]) a[i] = a0[l0++];
        else a[i] = a1[l1++];
        ++i;
    }
    if (l1 > (n >> 1)) {
        while (l0 <= (n >> 1)) a[i++] = a0[l0++];
    } else while (l1 <= (n >> 1)) a[i++] = a1[l1++];
}
int main() {
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i)
        cin >> q[i].t >> q[i].i, q[i].id = i;
    sort(q + 1, q + 1 + m);
    for (int i = 1, t = 0; i <= m; ++i) {
        while (t < q[i].t) upd(), ++t;
        ans[q[i].id] = a[q[i].i];
    }
    for (int i = 1; i <= m; ++i)
        write(ans[i]), putchar('\n');
    return 0;
}