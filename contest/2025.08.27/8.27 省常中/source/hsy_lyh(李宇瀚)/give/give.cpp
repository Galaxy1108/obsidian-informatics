#include<bits/stdc++.h>

using namespace std;

int f[2001][5001];
int n, m, s;
int a[201];

int main() {
    freopen("give.in", "r", stdin);
    freopen("give.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> s >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(m <= 2000 && s <= 5000) {
            memset(f, 0, sizeof(f));
            f[0][0] = 1;
            for(int i = 1; i <= m; i++) {
                for(int j = 0; j <= s; j++) {
                    for(int k = 1; k <= n; k++) {
                        if(j - a[k] < 0) continue;
                        f[i][j] = (f[i - 1][j - a[k]] + f[i][j]) & 1;
                    }
                }
            }
            cout << f[m][s] << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}