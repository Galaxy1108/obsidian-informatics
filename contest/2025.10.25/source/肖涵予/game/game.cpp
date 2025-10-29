#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, a[N];

int main() {
    freopen("game.in", "r", stdin), freopen("game.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << (n % 2 ? n : 0);
    return 0;
}