#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll nums[10000000];
ll n, k;

ll f(ll x){
    ll anss = 1;
    while(x){
        anss *= (x % 10);
        x /= 10;
    }
    return anss;
}

ll idx(ll x,ll y){
    if(x<1 || x>n || y<1 || y>n){
        return 0;
    }
    return ((x - 1) * n + y);
}

int main(){
    freopen("gold.in", "r", stdin);
    freopen("gold.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            nums[idx(f(i), f(j))]++;
        }
    }
    if(k==1){
        cout << nums[idx(0, 0)];
        return 0;
    }
    sort(nums + 1, nums + 1 + idx(n, n), [](ll a, ll b)
         { return a > b; });
    ll anss = 0;
    for (int i = 1; i <= k;i++){
        anss += nums[i];
    }
    cout << anss;
}
