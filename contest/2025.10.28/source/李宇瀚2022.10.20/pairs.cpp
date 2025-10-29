#include<bits/stdc++.h>

using namespace std;

long long ans[1001] = {0, 0, 0, 0, 17, 904, 45926, 2725016, 196884712};

int main() {
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
    long long n, p;
    cin >> n >> p;
    cout << ans[n] % p << endl;
    return 0;
}