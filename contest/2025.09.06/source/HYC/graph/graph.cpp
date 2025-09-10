#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if (m <= (n >> 1))
        cout << 0 << '\n';
    else
        cout <<
        ((m - (int)log10(n)) >> 1) << '\n';
    return 0;
}
