#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int maxa;

unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    bool flag1 = true;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] != 1) {
            flag1 = false;
        }
    }
    if (flag1) {
        cout << (n % 2 ? n : 0);
        return 0;
    }
    for (int i = 1;i <= n;i++) {
        mp[a[i]]++;
        maxa = max(maxa, a[i]);
    }
    if (!(mp[maxa] % 2)) {
        cout << 0 << '\n';
        return 0;
    }
    int p = maxa / 2 + 1;
    int anss = 0;
    for (int i = p;i <= maxa;i++) {
        for (auto its : mp) {
            if (its.first < i) {
                continue;
            }
            anss += its.second;
        }
    }
    cout << anss;
    return 0;
}
