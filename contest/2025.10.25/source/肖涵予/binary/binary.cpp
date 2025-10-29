#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;

int n, m, a[N];

inline bool check(int b, int cnt) {
    int L = max(0, cnt - (b / 2)), R = min((b + 1) / 2, cnt), C = cnt * 2 % 3;
    if (L > R) return false;
    for (int x = L, num = 1; x <= R && num <= 3; ++x, ++num)
        if (x % 3 == C)
            return true;
    return false;
}

int main() {
	freopen("binary.in", "r", stdin), freopen("binary.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 1, opt, x, l, r; i <= m; ++i) {
        cin >> opt;
        if (opt == 1) cin >> x, a[x] ^= 1;
        else {
            cin >> l >> r;
            ll ans = 0;
            for (int i = l; i <= r; ++i) {
                int b = 0, cnt = 0;
                for (int j = i; j <= r; ++j) {
                    ++b, cnt += a[j];
                    if (check(b, cnt)) ++ans;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}