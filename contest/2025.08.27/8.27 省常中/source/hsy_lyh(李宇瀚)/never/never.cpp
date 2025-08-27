#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, s, tt, x, y;
int vis[1000001];
int tj[1000001];

signed main() {
    freopen("never.in", "r", stdin);
    freopen("never.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s >> tt >> x >> y;
        if(n <= 1e6) {
            int cur = s;
            for(int i = 1; i <= n; i++) {
                if(cur < tt) cur += y;
                else cur -= x;
            }
            cout << cur << endl;
        }
        else if(x <= 100 && y <= 100) {
            memset(tj, 0, sizeof(tj));
            memset(vis, 0, sizeof(vis));
            int cur = s;
            int cnt = 1; bool flag = 0;
            vis[cur + 1000] = 1;
            tj[1] = cur;
            for(int i = 1; i <= n; i++) {
                if(cur < tt) cur += y;
                else cur -= x;
                cnt++;
                if(vis[cur + 1000]) {
                    int lop = cnt - vis[cur + 1000];
                    int tt = (n - vis[cur + 1000] + 1) % lop;
                    cout << tj[vis[cur + 1000] + tt] << endl;
                    flag = 1;
                    break;
                }
                vis[cur + 1000] = cnt;
                tj[cnt] = cur;
            }
            if(!flag) cout << cur << endl;
        }
        else if(x == y) {
            if(s < tt) {
                int tmp = (tt - s) / y;
                if(tmp >= n) {
                    cout << s + n * y << endl;
                    continue;
                }
                int cur = s + tmp * y;
                int cur2 = cur + y;
                int tt = (n - tmp) % 2;
                if(tt == 1) cout << cur2 << endl;
                else cout << cur << endl;
            }
            if(s >= tt) {
                int tmp = (s - tt) / x;
                if(tmp >= n) {
                    cout << s - n * x << endl;
                    continue;
                }
                int cur = s - tmp * x;
                int cur2 = cur - x;
                int tt = (n - tmp) % 2;
                if(tt == 1) cout << cur2 << endl;
                else cout << cur << endl;
            }
        }
    }
    return 0;
}