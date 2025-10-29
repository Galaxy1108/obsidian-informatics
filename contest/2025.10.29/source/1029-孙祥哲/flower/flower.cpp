#include <bits/stdc++.h>
using namespace std;

int n, vis[45], a[90], _;
string s[100];
clock_t st;

void dfs(int x)
{
    if (_) return;
    if (x > 2*n)
    {
        for (int i = 1; i <= 2*n; i++) cout << s[a[i]] << '\n';
        _ = 1;
    }
    if (a[x]) { dfs(x+1); return; }
    for (int i = n; i >= 1; i--)
    {
        if (x+i+1 > 2*n || a[x+i+1] || vis[i]) continue;
        a[x] = a[x+i+1] = i, vis[i] = 1;
        dfs(x+1);
        a[x] = a[x+i+1] = 0, vis[i] = 0;
    }
}

int main()
{
     freopen("flower.in", "r", stdin);
     freopen("flower.out", "w", stdout);
//    n = 39;
     cin >> n;
     for (int i = 1; i <= n; i++) cin >> s[i];
    // st = clock();
    dfs(1);
    // cout << "No Solution!";
    // for (int i = 1; i <= 40; i++)
    // {
    //     n = i;
    //     // cin >> n;
    //     memset(vis, 0, sizeof(vis));
    //     memset(a, 0, sizeof(a));
    //     _ = 0;
    //     cout << n << ":";
    //     st = clock(), dfs(1);
    //     if (!_) cout << "No Answer!\n";
    //     else cout << '\n' << (double)(clock()-st)/CLOCKS_PER_SEC << '\n';
    // }
    return 0;
}
