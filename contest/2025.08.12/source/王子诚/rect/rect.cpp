#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("rect.in", "r", stdin);
    freopen("rect.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char s;
            cin >> s;
            if(s=='C'){
                cout << ++cnt << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
}