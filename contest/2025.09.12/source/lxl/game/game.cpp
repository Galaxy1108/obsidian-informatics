#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2000010;
ll n, m, T, ans, a[N];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            a[x] += z, a[y] += z;
        }
        ans = 0;
        sort(a + 1, a + n + 1);
        for (ll i = n; i >= 1; i -= 2)
            ans += a[i] - a[i - 1]; 
        cout << (ans >> 1) << endl;
    }
    return 0;
}
// g++ -g -lm -O2 -static -std=c++14 -o game game.cpp