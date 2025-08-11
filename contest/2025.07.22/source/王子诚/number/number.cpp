#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll x[2500], idxs[2500], a[1000];
ll n, m;

ll dfs(ll I){
    if(I==m+1){
        for (ll i = 1; i <= n;i++){
            a[i] = 0;
        }
        for (ll i = 1; i <= m;i++){
            a[idxs[i]] = x[i] - a[idxs[i]];
        }
        ll sums = 0;
        for (ll i = 1; i <= n;i++){
            sums += a[i];
        }
        return sums;
    }
    ll maxs = LLONG_MIN;
    for (ll i = 1; i <= n;i++){
        idxs[I] = i;
        maxs = max(maxs, dfs(I + 1));
    }
    return maxs;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ll T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for (ll i = 1; i <= m;i++){
            cin >> x[i];
        }
        cout << dfs(1) << '\n';
    }
}