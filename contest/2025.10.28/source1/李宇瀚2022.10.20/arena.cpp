#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505;
const int M = 998244353;

int n, x;
int f[N][N];
int fpow[N][N];
int zh[N][N];

void getans() {
    zh[1][0] = zh[1][1] = 1;
    for(int i = 2; i <= 500; i++) {
        zh[i][0] = zh[i][i] = 1;
        for(int j = 1; j < i; j++) zh[i][j] = (zh[i - 1][j - 1] + zh[i - 1][j]) % M;
    }
    return;
}

signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> x;
    getans();
    f[n][0] = 1;
    for(int i = n; i >= 2; i--) {
        for(int j = 0; j < x; j++) {
            int ppow = 1;
            int newn = min(x, j + i - 1);
            for(int k = i; k >= 0; k--) {
                f[k][newn] = (f[k][newn] + f[i][j] * zh[i][i - k] % M * ppow % M) % M;
                ppow = (ppow * (newn - j)) % M;
            }
        }
    }
    int total = 0;
    for(int i = 0; i <= x; i++) total = (total + f[0][i]) % M;
    cout << total << endl;
    return 0;
}