#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
struct line {
    int len, a[20];
    int& operator [] (int pos) {
        return a[pos];
    }
} a[1 << 20], b;
bool operator < (line a, line b) {
    int l = min(a.len, b.len);
    for (int i = 0; i < l; ++i) {
        if (a[i] > b[i]) return false;
        if (a[i] < b[i]) return true;
    }
    return a.len < b.len;
}
bool operator != (line a, line b) {
    if (a.len != b.len) return true;
    for (int i = 0; i < a.len; ++i)
        if (a[i] != b[i]) return true;
    return false;
}
bool operator == (line a, line b) {
    return !(a != b);
}
int n, m, x[20], ans = 0;
void work() {
    for (int i = 0; i < (1 << n); ++i) {
        a[i].len = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                a[i][a[i].len++] = x[j];
    }
}
int check(int k) {
    for (int i = 0; i < k; ++i)
        if (a[i] == a[k]) return 0;
    return 1;
}
signed main() {
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    cin >> m;
    b.len = m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    work();
    for (int i = 1; i < (1 << n); ++i)
        if (a[i] < b) ans = (ans + check(i)) % p;
    cout << ans + 1 << endl;
    return 0;
}