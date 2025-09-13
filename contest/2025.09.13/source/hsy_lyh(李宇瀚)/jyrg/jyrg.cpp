#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 11;

int lim, n;
int a[N];
int minans = 1e17;

bool chk(int *A) {
    for(int i = 2; i <= n; i++) {
        if(a[i - 1] < a[i]) return false;
    }
    return true;
}

void dfs(int cnt, int tot) {
    if(cnt == lim + 1) {
        if(chk(a)) minans = min(minans, tot);
        return;
    }
    for(int i = 1; i < n; i++) {
        int t1 = a[i], t2 = a[i + 1];
        a[i] = t2 - 1, a[i + 1] = t1 + 1;
        dfs(cnt + 1, max(tot, t1 + t2));
        a[i] = t1, a[i + 1] = t2;
    }
    return;
}

signed main() {
    freopen("jyrg.in", "r", stdin);
    freopen("jyrg.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        minans = 1e17;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(chk(a)) {
            cout << 0 << endl;
            continue;
        }
        for(int i = 1; i <= n; i++) {
            lim = i;
            dfs(1, 0);
        }
        if(minans == 1e17) cout << -1 << endl;
        else cout << minans << endl;
    }
    return 0;
}