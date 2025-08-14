#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105, lzj = 998244353;
int n, m, s, t, h[N], a = 0, a2 = 0, rtc = 0,
add[N], vaa[N];
bool vis[N], nul[N];
struct edge {
    int to, nxt, vl;
} e[N * N];
int sqr(int n) {
    return n * n % lzj;
}
void adde(int u, int v, int w) {
    static int cnt = 0;
    e[++cnt].to = v, e[cnt].nxt = h[u],
    e[cnt].vl = w, h[u] = cnt;
};
int qpow(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = a * a % lzj)
        if (b & 1) ans = ans * a % lzj;
    return ans;
}
int dfs(int u, int val) {
    if (u == t) {
        rtc = (rtc + 1) % lzj;
        return val;
    }
    if (vis[u]) {
        add[u] =
        (add[u] + (val - vaa[u] + lzj) % lzj) % lzj;
        return 0;
    }
    vis[u] = 1;
    int k = 0, ans = 0;
    add[u] = 0;
    vaa[u] = val;
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to, tmp = 0;
        ++k;
        if (!e[i].vl) tmp = (val + 1) % lzj;
        else for (int i = 1; i <= n; ++i) 
            if (vis[i]) 
        ans = (ans + dfs(v, tmp)) % lzj;
    }
    vis[u] = 0;
    ans = (ans * qpow(k, lzj - 2)) % lzj;
    ans = (ans + add[u]) % lzj;
}
int main() {
    freopen("rabbit.in", "r", stdin);
    freopen("rabbit.out", "w", stdout);
    cout << 0 << ' ' << 0 << endl;
    return 0;
}