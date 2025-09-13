#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;
const int M = 998244353;

int ju[N], pri[N], phi[N], tot = 0;
int fac[N], ifac[N];
int fib[N];
int k, n;

void el() {
    phi[1] = 1;
    for(int i = 2; i <= N - 5; i++) {
        if(!ju[i]) {
            pri[++tot] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= tot; j++) {
            if(pri[j] * i > N - 5) break;
            ju[pri[j] * i] = 1;
            if(i % pri[j] == 0) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            phi[i * pri[j]] = phi[i] * (pri[j] - 1);
        }
    }
    return;
}

inline int fpow(int a, int b) {
    int ans = 1, base = a;
    while(b > 0) {
        if(b & 1) ans = ans * base % M;
        base = base * base % M;
        b >>= 1;
    }
    return ans % M;
}

inline int getInv(int x) {
    return fpow(x, M - 2);
}

signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> k;
    int t;
    cin >> t;
    el();
    fib[1] = 1, fib[2] = 1;
    for(int i = 3; i <= N - 5; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % M;
    while(t--) {
        cin >> n;
        if(k > n / 2) {
            cout << n << " " << 1 << endl;
            continue;
        }
        else if(k == 1) {
            fac[0] = 1;
            for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % M;
            ifac[n] = getInv(fac[n]);
            for(int i = n - 1; i >= 1; i--) ifac[i] = (ifac[i + 1] * (i + 1)) % M;
            ifac[0] = 1;
            int ans1 = 0, ans2 = 0;
            for(int i = 1; i <= n; i++) {
                int t1 = n - k * i - 1, t2 = (i - 1), t3 = n - (k + 1) * i;
                if(t1 < 0 || t3 < 0 || t2 < 0) break;
                int tmp = fac[t1] * ifac[t2] % M * ifac[t3] % M;
                tmp = tmp * n % M * getInv(i) % M;
                ans1 = (ans1 + tmp) % M;
            }
            for(int i = 1; i * i <= n; i++) {
                if(n % i != 0) continue;
                int tmp;
                tmp = phi[n / i] * ((fib[i - 1] + fib[i + 1] - 1 + M) % M) % M;
                ans2 = (ans2 + tmp) % M;
                if(i * i != n) tmp = phi[i] * ((fib[n / i - 1] + fib[n / i + 1] - 1 + M) % M) % M, ans2 = (ans2 + tmp) % M;
            }
            ans2 = ans2 * getInv(n) % M;
            cout << ans1 << " " << ans2 << endl;
            continue;
        }
        else {
            cout << 0 << " " << 0 << endl;
            continue;
        }
    }
    return 0;
}