#include <bits/stdc++.h>
using namespace std;

int w[100][100];
int f[100];
int fat[100];

int root, anss, n;
int get_fat(int a) {
    return (a == fat[a] ? a : get_fat(fat[a]));
}

void dfs(int I) {
    // cout << I << endl;
    if (I == root) {
        f[I] = 0;
        dfs(I + 1);
        return;
    }
    if (I == n + 1) {
        int sums = 0;
        for (int i = 1;i <= n;i++) {
            if (i == root) {
                continue;
            }
            int res = INT_MAX;
            int its = i;
            while (its != root) {
                res = min(res, w[its][f[its]]);
                its = f[its];
            }
            sums += res;
        }
        anss = min(anss, sums);
        return;
    }
    for (int i = 1;i <= n;i++) {
        int fat_u = get_fat(I), fat_v = get_fat(i);
        if (fat_u == fat_v) {
            continue;
        }
        fat[fat_u] = fat_v;
        f[I] = i;
        dfs(I + 1);
        fat[fat_u] = fat_u;
    }
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> n;
    for (int i = 1;i < n;i++) {
        for (int j = 1;j <= n - i;j++) {
            cin >> w[i][i + j];
            w[i + j][i] = w[i][i + j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            fat[j] = j;
        }
        anss = INT_MAX, root = i;
        dfs(1);
        cout << anss << '\n';
    }
}
