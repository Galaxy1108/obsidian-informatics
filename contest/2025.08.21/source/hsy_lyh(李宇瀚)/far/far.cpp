#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int M = 998244353;

int n, m;
int l[N], r[N];
int f[21][(1 << 20) + 1];

bool chk(int a) {
    int l = 0, r = m - 1;
    while(l <= r) {
        if(((a >> l) & 1) != ((a >> r) & 1)) return false;
        l++, r--;
    }
    return true;
}

signed main() {
    freopen("far.in", "r", stdin);
    freopen("far.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    if(m <= 20) {
        f[0][0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = 0;
            for(int s1 = 0; s1 <= (1 << m) - 1; s1++) {
                for(int j = l[i + 1]; j <= r[i + 1]; j++) {
                    int t = (j & ((1 << m) - 1));
                    // cout << t << endl;  
                    int nt = s1 ^ t;
                    // cout << nt << endl;
                    f[i + 1][nt] = (f[i + 1][nt] + f[i][s1]) % M;
                    if(chk(nt)) ans = (ans + f[i][s1]) % M;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}