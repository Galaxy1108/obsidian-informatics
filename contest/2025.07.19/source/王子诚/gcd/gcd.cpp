#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int anss = 0;
        for (int x = a; x <= b;x++){
            for (int y = c; y <= d;y++){
                anss += (__gcd(x, y) == 1);
            }
        }
        cout << anss << '\n';
    }
}