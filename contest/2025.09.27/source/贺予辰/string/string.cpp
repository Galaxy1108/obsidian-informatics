#include<bits/stdc++.h>
using namespace std;
char s[405];
int a[405], cnt[3], n, ans = 0;
bool ck(int n) {
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1]) return 0;
    return 1;
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        a[i] = s[i] - '0', ++cnt[a[i]];
    if (max(max(cnt[0], cnt[1]), cnt[2])
    > ((n + 1) >> 1)) {
        cout << -1 << '\n';
        return 0;
    }
    while (!ck(n)) {
        ++ans;
        bool fl = 0, f = 0;
        int p;
        for (int i = 1; i < n; ++i)
            if (a[i] == a[i - 1]) fl = 1;
            else if (fl) {p = i, f = 1; break;}
        if (!f) {
            for (int i = 0; i < (n >> 1); ++i)
                swap(a[i], a[n - i - 1]);
            fl = 0;
            for (int i = 1; i < n; ++i)
                if (a[i] == a[i - 1]) fl = 1;
                else if (fl) {p = i; break;}
            swap(a[p], a[p - 1]);
            for (int i = 0; i < (n >> 1); ++i)
                swap(a[i], a[n - i - 1]);
        } else swap(a[p], a[p - 1]);
    }
    cout << ans << '\n';
    return 0;
}