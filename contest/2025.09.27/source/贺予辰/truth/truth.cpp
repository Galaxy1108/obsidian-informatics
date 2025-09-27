#include<bits/stdc++.h>
using namespace std;
int nxt[50004][35], lst[35], a[50004],
n, m, op, v, p, k, lo = 0, la = 0;
int getans() {
    memset(nxt, 0x3f, sizeof(nxt));
    for (int i = 1; i <= k; ++i)
        lst[i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = lst[a[i]] + 1; j <= i; ++j)
            nxt[j][a[i]] = i;
        lst[a[i]] = i;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        int tmp = i;
        for (int j = 1; j <= k; ++j)
            tmp = max(nxt[i][j], tmp);
        ans = min(tmp - i + 1, ans);
    }
    if (ans <= n) return ans;
    return -1;
}
int main() {
    freopen("truth.in", "r", stdin);
    freopen("truth.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (m--) {
        cin >> op;
        if (op & 1) cin >> p >> v, a[p] = v;
        else {
        	if (lo ^ op) la = getans();
			cout << la << '\n';
		}
		lo = op;
    }
    return 0;
}
