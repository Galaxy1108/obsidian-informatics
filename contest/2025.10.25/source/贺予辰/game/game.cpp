#include<bits/stdc++.h>
using namespace std;
int a[1000006], n;
int check() {
    if (n & 1) {
        for (int i = 1; i <= n; ++i)
            if (a[i] ^ 1) return 0;
        return 1;
    }
    return 0;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << check() * n << '\n';
    return 0;
}