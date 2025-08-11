#include <bits/stdc++.h>
using namespace std;

int s[1000005], pl[1000005], pr[1000005];
int a[1000005], b[1000005];

int main() {
    freopen("gene.in", "r", stdin);
    freopen("gene.out", "w", stdout);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        b[a[s[i]]] = i;
        a[s[i]] = i;
    }
    for (int i = 1;i <= n;i++) {
        if (b[i] == 0) {
            b[i] = n + 1;
        }
    }
    for (int i = 1;i < l;i++) {
        pl[s[i]]++;
    }
    for (int i = l;i <= n;i++) {
        pr[s[i]]++;
    }
    int min_j = r + 1;
    for (int i = l - 1;i >= 1;i--) {
        pr[s[i]]++;
        if (pl[s[i]] == 1) {
            int max_r = b[i];
            if (max_r <= min_j) {
                continue;
            }
            for (int j = min_j;j < max_r;j++) {
                if (pr[s[j]] == 1) {
                    cout << j - i + 1;
                    return 0;
                }
            }
            min_j = max_r;
        }
        pl[s[i]]--;
    }
    cout << -1;
    return 0;
}