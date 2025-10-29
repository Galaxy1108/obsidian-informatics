#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll aa, bb;

ll maxk, k;
long double p;
ll nums[1000];

bool dfs(ll a, ll b, ll le) {
    if (k == maxk) {
        return (a == 0);
    }
    if (b >= a * 1000000000) {
        return false;
    }
    for (ll e = max(le + 1, (ll)((b + a - 1) / a));k * b + a * e <= maxk * b;e++) {
        ll newc = a * e - b, newd = b * e;
        ll g = __gcd(newc, newd);
        newc /= g, newd /= g;
        nums[++k] = e;
        if (dfs(newc, newd, e)) {
            return true;
        }
        nums[k--] = 0;
    }
    return false;
}

int main() {
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    cin >> aa >> bb;
    if (aa == 0) {
        cout << 0;
        return 0;
    }
    int g = __gcd(aa, bb);
    aa /= g, bb /= g;
    p = 1.0 * aa / bb;
    maxk = 1;
    while (!dfs(aa, bb, 0)) {
        maxk++;
    }
    cout << k << '\n';
    for (int i = 1;i <= k;i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
