#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fac[1000005];
#define HasNoName 1000000007

ll fast_pow(ll a,ll b){
    ll anss = 1;
    while(b){
        if(b&1){
            anss = (anss * a) % HasNoName;
        }
        b >>= 1;
        a = (a * a) % HasNoName;
    }
    return anss;
}

int main(){
    int T;
    cin >> T;
    fac[0] = 1;
    for (int i = 1; i <= 1000000;i++){
        fac[i] = (fac[i - 1] * i) % HasNoName;
    }
    while (T--){
        ll n, k;
        cin >> n >> k;
        cout << ((((fac[k] * fast_pow(k + 1, n - k)) % HasNoName) - (fac[k - 1] * fast_pow(k, n - k + 1) % HasNoName) + HasNoName) % HasNoName) << '\n';
    }
}