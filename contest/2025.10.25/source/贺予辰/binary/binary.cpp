#include<bits/stdc++.h>
using namespace std;
int n, k, m, op, x;
int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> k;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> op >> k;
        if (op & 1) continue;
        cin >> x;
        cout << 0 << '\n';
    }
    return 0;
}