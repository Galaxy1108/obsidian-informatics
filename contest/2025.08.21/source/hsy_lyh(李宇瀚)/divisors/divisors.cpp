#include<bits/stdc++.h>

using namespace std;

int n;

int gcd(int x, int y) {
    if(x % y == 0) return y;
    else return gcd(y, x % y);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

int main() {
    freopen("divisors.in", "r", stdin);
    freopen("divisors.out", "w", stdout);
    cin >> n;
    if(n <= 10) {
        int tmp = 1;
        for(int i = 2; i <= n; i++) tmp = lcm(tmp, i);
        cout << tmp << " ";
        for(int i = 2; i <= n; i++) cout << i << " ";
        cout << endl;
        for(int i = 2; i <= n; i++) cout << 1 << " " << i << endl;
    }
    else {

    }
    return 0;
}