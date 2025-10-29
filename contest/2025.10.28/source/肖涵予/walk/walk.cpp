#include <bits/stdc++.h>
#define bit(S, i) (S / pw[i] % 15)
#define p(x) (x - 1)
#define nxt(x) (x + 1)
using namespace std;

const int N = 6, Mu = 760000;
const int pw[N] = {1, 15, 225, 3375, 50625, 1265625};

int n, a[N];
bool f[Mu][N];

void assign(int S, int i) {
    if (i && bit(S, p(i))) f[S][i] |= f[S - pw[p(i)]][p(i)];
    if (i < n && bit(S, i)) f[S][i] |= f[S - pw[i]][nxt(i)];
    return ;
}

bool check(int S) {
    for (int i = 0; i <= n; ++i)
        if (f[S][i])
            return true;
    return false;
}

int main() {
    freopen("walk.in", "r", stdin), freopen("walk.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= n; ++i)
        f[0][i] = true;
    int U = p(pow(15, n));
    for (int S = 1; S <= U; ++S)
        for (int i = 0; i <= n; ++i)
            assign(S, i);
    int ans = INT_MAX;
    for (int S = 0; S <= U; ++S) {
        if (!check(S)) continue;
        int res = 0;
        for (int i = 0; i < n; ++i)
            res += abs(a[nxt(i)] - bit(S, i));
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}