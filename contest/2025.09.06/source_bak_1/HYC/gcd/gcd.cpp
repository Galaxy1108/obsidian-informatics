#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int n, w;
int qpow(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) ans = ans * a % p;
    return ans;
}
signed main() {
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    cin >> n >> w;
    cout << qpow(n, p - 2) << '\n';
    return 0;
}