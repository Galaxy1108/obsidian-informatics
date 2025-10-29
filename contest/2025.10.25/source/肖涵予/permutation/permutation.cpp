#include <bits/stdc++.h>
#define nxt(i) (i + 1)
#define ls ((i << 1) - 1)
#define rs (i << 1)
using namespace std;

const int N = 605;

int n, a[N], ar[N];
bool vis[N];
map <vector <int>, bool> mp;

inline void check() {
    for (int i = 1; i <= n * 2; ++i)
        if (~a[i] && a[i] != ar[i])
            return ;
    vector <int> b;
    for (int i = 1; i < n * 2; i += 2)
        b.push_back(min(ar[i], ar[nxt(i)]));
    if (!mp.count(b)) mp[b] = true;
    return ;
}
void dfs(int step) {
    if (step > (n << 1)) return (check(), void());
    for (int i = 1; i <= n * 2; ++i) {
        if (vis[i]) continue;
        vis[i] = true, ar[step] = i, dfs(step + 1), vis[i] = false;
    }
    return ;
}

inline void Brute() {
    int ans = 0;
    dfs(1);
    cout << mp.size();
    return ;
}

int main() {
    freopen("permutation.in", "r", stdin), freopen("permutation.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n * 2; ++i)
        cin >> a[i];
    if (n <= 6) Brute();
    return 0;
}
