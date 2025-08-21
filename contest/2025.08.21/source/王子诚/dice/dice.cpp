#include <bits/stdc++.h>
using namespace std;

int a[5005];
#define mod 1000000007
long long ans[5005];

long long fast_pow(long long a,long long b){
    long long anss = 1;
    while(b){
        if(b&1){
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

int f[5005];
long long g[5005];

int main(){
    freopen("dice.in", "r", stdin);
//    freopen("dice.out", "w", stdout);
    int n;
    cin >> n;
    int max_i = 0;
    g[0] = 1;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        max_i = max(max_i, a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++){
//    	cout<<i<<endl;
        g[i] = (g[i - 1] * a[i]) % mod;
    }
    long long anss = 0, idx = 0;
    for (int i = 1; i <= max_i;i++){
    	cout<<i<<'\n';
        ans[i] = 1;
        while(i==a[idx+1]){
            idx++;
            cout<<idx<<'\n';
        }cout<<i<<'\n'; 
        ans[i] = (g[idx] * fast_pow(i, n - idx)) % mod;
        anss = (anss + ((((ans[i] - ans[i - 1] + mod) % mod) * i) % mod)) % mod;
    }
    cout << anss * fast_pow(ans[max_i], mod - 2) % mod;
}
