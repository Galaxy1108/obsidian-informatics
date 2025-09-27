/*
O2优化的大手使我 n^2 过 36651

zto zto zto O2 orz orz orz

Very good O2, love from china.
*/
#include <bits/stdc++.h>
using namespace std;

int sn[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    // auto begin = chrono::high_resolution_clock().now();
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> sn[i];
    }
    int anss = 0;
    for (int i = 1;i <= n;i++) {
        int xors = 0, maxs = INT_MIN;
        for (int j = i;j <= n;j++) {
            xors = xors ^ sn[j];
            maxs = max(maxs, sn[j]);
            if (xors <= maxs) {
                anss++;
            }
            // if (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock().now() - begin).count() >= 900) {
            //     cout << anss;
            //     return 0;
            // }
        }
    }
    cout << anss;
}