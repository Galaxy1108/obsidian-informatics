#include<bits/stdc++.h>
using namespace std;
int n, q, l, r, x, y,
s[2000006], id[2000006], p[2000006];
char c;
int find(int u) {
    if (u ^ id[u])
        return id[u] = find(id[u]);
    return u;
}
void merge(int u, int v) {
    id[find(u)] = find(v);
}
int main() {
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> l >> r, p[0] = s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        id[i] = i, cin >> c, s[i] = s[i - 1];
        if (c == 'a')
            ++s[i], p[s[i]] = i;
        else if (s[i - 1] == s[i - 2])
			merge(i, i - 1);
        for (int k = l; k <= r; ++k) {
            if (k > s[i]) break;
            merge(i, p[s[i] - k] + 1);
            merge(i, p[s[i] - k + 1]);
        }
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        if (find(x) == find(y))
            cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
