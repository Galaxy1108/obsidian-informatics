#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 5;
const int M = 1e9 + 7;

int n;
int a[N];
int suf[N];

inline int fpow(int a, int b) {
    int ans = 1, base = a;
    while(b > 0) {
        if(b & 1) ans = ans * base % M;
        base = base * base % M;
        b >>= 1;
    }
    return ans;
}

inline int getInv(int x) {
    return fpow(x, M - 2);
}

signed main() {
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    suf[n + 1] = 1;
    for(int i = n; i >= 1; i--) suf[i] = (suf[i + 1] * a[i] % M);
    int indx = 1;
    int total = 0;
    for(int i = 1; i <= a[n]; i++) {
        while(indx <= n && i > a[indx]) indx++;
        int tt = ((fpow(i, n - indx + 1) - fpow(i - 1, n - indx + 1)) % M + M) % M * getInv(suf[indx]) % M;
        total = (total + tt * i) % M;
    }
    cout << total << endl;
    return 0;
}