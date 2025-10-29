#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool a[100005];
ll sofp1[100005], sofp2[100005], g[100005], s[100005];
ll n;

int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sofp2[0] = true;
    for (int i = 1;i <= n;i++) {
        s[i] = s[i - 1] + a[i];
        sofp1[i] = sofp1[i - 1] + s[i] % 2;
        sofp2[i] = sofp2[i - 1] + !(s[i] % 2);
        g[i] = g[i - 1] + (s[i] % 2 ? sofp1[i - 1] : sofp2[i - 1]);
    }
    bool is_build = true;
    int min_change = INT_MAX;
    int m;
    cin >> m;
    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int i;
            cin >> i;
            a[i] ^= 1;
            min_change = min(min_change, i);
            is_build = false;
        } else {
            if (!is_build) {
                is_build = true;
                for (int i = min_change;i <= n;i++) {
                    s[i] = s[i - 1] + a[i];
                    sofp1[i] = sofp1[i - 1] + s[i] % 2;
                    sofp2[i] = sofp2[i - 1] + !(s[i] % 2);
                    g[i] = g[i - 1] + (s[i] % 2 ? sofp1[i - 1] : sofp2[i - 1]);
                }
            }
            int l, r;
            cin >> l >> r;
            cout << g[r] - g[l - 1] - (sofp1[r] - sofp1[l - 1]) * (l == 1 ? 0 : sofp1[l - 2]) - (sofp2[r] - sofp2[l - 1]) * (l == 1 ? 0 : sofp2[l - 2]) << '\n';
        }
    }
}
