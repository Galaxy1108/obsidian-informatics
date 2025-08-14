#include <bits/stdc++.h>
using namespace std;

long long mu[1000005], p[1000005];
bool flag[1000005];

void getMu(){
    long long tot = 0;
    mu[1] = 1;
    for (int i = 2; i <= 1000000; ++i){
        if (!flag[i]){
            p[++tot] = i, mu[i] = -1;
        }
        for (int j = 1; j <= tot && i * p[j] <= 1000000; ++j){
            flag[i * p[j]] = 1;
            if (i % p[j] == 0){
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
}

long long f[1000005];


int main(){
    int T;
    cin >> T;
    getMu();
    while(T--){
        long long n, p;
        cin >> n >> p;
        long long ans = 1, anss = 0;
        f[1] = 1;
        for (int i = 1; i <= n;i++){
            long long res = 1;
            for (int k = 1; k * k <= i;k++){
                if(!(i%k)){
                    res *= (pow(f[k],mu[i / k]) % p);
                    res %= p;
                    if(i/k != k){
                        res *= (pow(f[i / k],mu[i / (i / k)]) % p);
                        res %= p;
                    }
                }
            }
            f[i + 1] = 2 * f[i] + f[i - 1];
            ans *= res;
            ans %= p;
            anss += (i * ans) % p;
            anss %= p;
        }
        cout << anss << '\n';
    }
}