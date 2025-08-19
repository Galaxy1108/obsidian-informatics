#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll p, a[1005], m, n;
ll ns[100005], c[1005][1005];

ll fast_pow(ll a,ll b){
    ll anss = 1;
    while(b){
        if(b&1){
            anss = (anss * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return anss;
}

ll inv(ll num){
    return fast_pow(num, p - 2);
}

ll C(ll a,ll b){
    return (n <= 1000 ? c[a][b] : (ns[a] * inv(ns[b] * ns[a - b] % p)) % p);
}

ll f(int x){
    ll anss = 0;
    for (int i = 0; i <= m;i++){
        anss += (a[i] * fast_pow(x, i)) % p;
        anss %= p;
    }
    return anss;
}

int main(){
    freopen("combination.in", "r", stdin);
    freopen("combination.out", "w", stdout);
    ll x;
    cin >> n >> x >> p >> m;
    if(n<=1000){
        c[0][0] = 1;
        for (int i = 1; i <= n;i++){
            for (int j = 0; j <= n;j++){
                if(j==0){
                    c[i][j] = 1;
                    continue;
                }
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
            }
        }
    }else{
        ns[0] = 1;
        for (int i = 1; i <= n;i++){
            ns[i] = ns[i - 1] * i;
        }
    }
    for (int i = 0; i <= m;i++){
        cin >> a[i];
    }
    ll anss = 0;
    for (int k = 0; k <= n;k++){
        anss += (((f(k) * fast_pow(x, k)) % p) * C(n, k)) % p;
        anss %= p;
    }
    cout << anss;
}