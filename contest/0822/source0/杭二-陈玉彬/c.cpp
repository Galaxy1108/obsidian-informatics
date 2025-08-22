/**
 * @author : cyb1010
 * @date   : 2024-09-03 10:56:22
 * @file   : c.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define fo(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) int(v.size())
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
void ckmx(int &x, int y) { x < y && (x = y); }
void ckmn(int &x, int y) { x > y && (x = y); }
const int N = 5010;
int __, n, a[N][N], b[N][N], id[N], p[N];
void gen() {
    int seed;
    cin >> n >> seed;
    if (!seed) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n + 1; j++) cin >> a[i][j];
        return;
    }
    mt19937 rng(seed);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            a[i][j] = j, swap(a[i][j], a[i][rng() % j + 1]);
}
int main() {
    fo("c");
    cin.tie(0)->sync_with_stdio(0);
    gen();
    for (int i = n; i; i--) {
        for (int j = 1; j <= n + 1; j++) b[i][a[i][j]] = j;
        for (int j = 1;; j++)
            if (!id[b[i][j]]) {
                id[b[i][j]] = i, p[i] = j;
                break;
            }
    }
    for (int i = 1; i <= n + 1; i++)
        if (!id[i]) cout << i << ' ';
    for (int i = 1, x; i < n; i++) {
        id[b[i][p[i]]] = 0, p[i] = 1, x = id[b[i][1]], id[b[i][1]] = i;
        auto fir = [&](int x, int y) {
            return (max(x, y) <= i || min(x, y) > i) ? x > y : x < y;
        };
        while (x) {
            int pos = p[x], tmp = x;
            while (id[b[x][pos]] && fir(id[b[x][pos]], x)) pos++;
            swap(tmp, id[b[x][pos]]), p[x] = pos, x = tmp;
        }
        for (int i = 1; i <= n + 1; i++)
            if (!id[i]) cout << i << ' ';
    }
    return 0 ^ __ ^ 0;
}