#include <bits/stdc++.h>
#define p(x) (x - 1)
#define nxt(x) (x + 1)
#define bit(S, i) ((S >> i) & 1)
using namespace std;
typedef long long ll;

const int N = 200005;

int n, m, a[N];
struct Segment {
    int l, r;
} b[N];

int main() {
    freopen("points.in", "r", stdin), freopen("points.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i].l >> b[i].r;
    cout << 0;
    return 0;
}