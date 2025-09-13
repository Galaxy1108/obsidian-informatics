#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    freopen("jyrg.in", "r", stdin);
    freopen("jyrg.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        bool flag = true;
        a[0] = INT_MAX;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (a[i] > a[i - 1]) {
                flag = false;
            }
        }
        cout << (flag ? 0 : -1) << '\n';
    }
}