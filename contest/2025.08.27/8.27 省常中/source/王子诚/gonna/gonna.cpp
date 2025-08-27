#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
ull f[20];

ull c(ull n, ull m) {
    return f[n] / (f[m] * f[n - m]);
}

int main() {
    freopen("gonna.in", "r", stdin);
    freopen("gonna.out", "w", stdout);
    ull n, p;
    cin >> n >> p;
    f[0] = 1;
    for (int i = 1;i <= n;i++) {
        f[i] = i * f[i - 1];
    }
    ull g = 0;
    for (int i = 1;i <= n;i++) {
        ull anss = 1;
        for (int j = 0;j <= i;j++) {
            anss *= c(i, j);
        }
        for (ull i = 1;i * i <= anss;i++) {
            if (!(anss % i)) {
                g += i;
                if (anss / i == i) {
                    continue;
                }
                g += anss / i;
            }
        }
        g %= p;
    }
    cout << g;
}
