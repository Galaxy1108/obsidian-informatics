#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ls[100005], rs[100005];
int n, m;

bool check(ll maxs) {
    if (m < n) {
        int j = 1;
        for (int i = 1;i <= n;i++) {
            if (abs(ls[i] - rs[j]) <= maxs) {
                j++;
            }
            if (j == m + 1) {
                return true;
            }
        }
        return false;
    } else {
        int j = 1;
        for (int i = 1;i <= m;i++) {
            if (abs(ls[j] - rs[i]) <= maxs) {
                j++;
            }
            if (j == n + 1) {
                return true;
            }
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gloves.in", "r", stdin);
    freopen("gloves.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> ls[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> rs[i];
    }
    sort(ls + 1, ls + 1 + n);
    sort(rs + 1, rs + 1 + m);
    ll l = 0, r = 1e9 + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}