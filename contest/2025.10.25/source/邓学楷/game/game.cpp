#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a;
    if (n % 2 == 0) cout << 0 << endl;
    else cout << n << endl;
    return 0;
}