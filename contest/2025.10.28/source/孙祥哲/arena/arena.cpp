#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;

ll qp(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1) r = r * a % mod;
        b >>= 1, a = a * a % mod;
    }
    return r;
}

int n, x, res;
ll C[505][505], a[505], b[505];

void init()
{
    for (int i = 0; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}
bool check()
{
    for (int i = 1; i <= n; i++) b[i] = a[i];
    while (1)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (b[i]>0);
        if (cnt == 1) return 0;
        if (!cnt) return 1;
        for (int i = 1; i <= n; i++) b[i] -= cnt-1;
    }
}
void dfs(int y)
{
    if (y > n)
    {
        if (n == 3)
        {
            int a1 = max(a[1],max(a[2],a[3])), a3 = min(a[1],min(a[2],a[3]));
            int a2 = a[1]+a[2]+a[3]-a1-a3;
            a1--,a2--,a3--;
            if (a1/2 == a2/2 && a2/2 == a3/2) res++;
            else if (a1 == a2)  res++;
            return;
        }
        if (check())
        {
            // for (int i = 1; i <= n; i++) cout << a[i] << "|"; cout << '\n';
            res++;
        }
        return;
    }
    for (int i = 1; i <= x; i++)
        a[y] = i, dfs(y+1);
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> x;
    init();
    if (x < n) { cout << qp(x, n); return 0; }
    dfs(1); cout << res << '\n';
    // int sum = 0;
    // for (int i = 1; i <= x; i += n-1)
    // {
    //     int t1 = min(n-1, x-i+1), t2 = i-1;
    //     for (int j = 2; j <= n; j++)
    //     {
    //         sum = (sum + 1ll * qp(t1, j) * C[n][j] % mod * qp(t2, n-j) % mod) % mod;
    //     }
    // }
    // cout << sum;
    return 0;
}