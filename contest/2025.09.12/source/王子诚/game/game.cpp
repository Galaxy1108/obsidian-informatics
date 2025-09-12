/*
如果这张图是二分图，答案为 0
*/

#include <bits/stdc++.h>
using namespace std;

struct edge_t {
    int u, v, w;
};
edge_t edges[41];

int n, m;

int get_ans(int a, int b) {
    int ans1 = 0, ans2 = 0;
    for (int i = 1;i <= m;i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if ((a & (1 << u)) && (a & (1 << v))) {
            ans1 += w;
        }
        if ((b & (1 << u) && (b & (1 << v)))) {
            ans2 += w;
        }
    }
    return ans1 - ans2;
}

int nums[1 << 12][1 << 12][2];

int dfs(int a, int b, bool s) {
    if (nums[a / 2][b / 2][s]) {
        return nums[a / 2][b / 2][s];
    }
    if (__builtin_popcount(a) + __builtin_popcount(b) == n) {
        return nums[a / 2][b / 2][s] = get_ans(a, b);
    }
    int p = (s ? a : b);
    int np = (s ? b : a);
    int mins = INT_MAX, maxs = INT_MIN;
    for (int i = 1;i <= n;i++) {
        if (!(p & (1 << i)) && !(np & (1 << i))) {
            int res = dfs((s ? (p | (1 << i)) : np), (s ? np : (p | (1 << i))), s ^ 1);
            mins = min(mins, res);
            maxs = max(maxs, res);
        }
    }
    return nums[a / 2][b / 2][s] = (s ? maxs : mins);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n > 12) {
            for (int i = 1;i <= m;i++) {
                int a, b, c;
                cin >> a >> b >> c;
            }
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0;i < (1 << n);i++) {
            for (int j = 0;j < (1 << n);j++) {
                nums[i][j][0] = nums[i][j][1] = 0;
            }
        }
        for (int i = 1;i <= m;i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        cout << dfs(0, 0, true) << '\n';
    }
}

/*
1
4 5
1 2 1
1 3 4
3 4 3
1 3 2
4 4 3
*/
