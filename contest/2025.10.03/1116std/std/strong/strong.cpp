#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define FR first
#define SE second
using namespace std;
inline int read() {
    int x = 0;
    bool op = 0;
    char c = getchar();
    while (!isdigit(c)) op |= (c == '-'), c = getchar();
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return op ? -x : x;
}
const int N = 2e3 + 10;
const int INF = 1e9;
int n;
int a[N], f[N][N], p[N], pos[N], nxt[N], inc[N];
bool chkmin(int &a, int b) { return (b < a ? a = b, true : false); }
int main() {
    freopen("strong.in", "r", stdin);
    freopen("strong.out", "w", stdout);

    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) pos[i] = i;
    sort(pos + 1, pos + 1 + n, [&](int x, int y) { return a[x] > a[y]; });
    for (int i = 1; i <= n; i++) p[pos[i]] = i;
    memset(f, 0x3f, sizeof(f));
    p[n + 1] = n + 1;
    pos[n + 1] = n + 1;
    f[n + 1][n + 1] = 0;
    for (int i = n; i; i--) {
        int p1 = 1, p2 = 1;
        for (int j = 1; j < pos[i]; j++) p1 += (p[j] < i);
        for (int j = 1; j <= n + 1; j++) {
            p2 += (p[j] < i);
            chkmin(f[i][j], f[i + 1][j] + p1 + p2);
        }
        int sum = 0;
        for (int j = pos[i] + 1; j <= n + 1; j++) {
            if (chkmin(f[i][pos[i]], f[i + 1][j] + sum)) nxt[i] = j;
            sum += max(0, i - p[j]);
        }
    }
    int ans = INF, now = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (chkmin(ans, f[1][i])) now = i;
    }
    // dfs(1, now);
    printf("%d\n", ans);
    return 0;
}
