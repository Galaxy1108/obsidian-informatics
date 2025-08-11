#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fl[5005], fr[5005];
ll fat[5005][10], dep[5005];
ll fat_cost[5005];
ll t_fat[5005];
ll u[5005], v[5005], w[5005];
ll fatt[5005];

#define mod 998244353

vector<ll> t[5005];

ll get_fat(ll a){
    return (a == fatt[a] ? a : get_fat(fatt[a]));
}

void build(ll a,ll fath){
    dep[a] = dep[fath] + 1;
    fat[a][0] = fath;
    for (ll i = 1; i < 10;i++){
        fat[a][i] = fat[fat[a][i - 1]][i - 1];
    }
    for(auto sons:t[a]){
        if(sons==fath){
            continue;
        }
        build(sons, a);
    }
}

ll lca(ll a,ll b){
    if(dep[a]>dep[b]){
        swap(a, b);
    }
    for (ll i=0,cnts=dep[b]-dep[a];cnts;cnts>>=1,i++){
        if(cnts&1){
            b = fat[b][i];
        }
    }
    if(a==b){
        return a;
    }
    for (ll i = 9; i >= 0;i--){
        if(fat[a][i]!=fat[b][i]){
            a = fat[a][i], b = fat[b][i];
        }
    }
    return fat[a][0];
}

ll n, m;
long long cntt;

void build_tree(ll I){
    if(I==n+1){
        cntt++;
        for (ll i = 1; i <= n;i++){
            t[i].clear();
        }
        for (ll i = 2; i <= n; i++){
            t[t_fat[i]].push_back(i);
            t[i].push_back(t_fat[i]);
        }
        dep[0] = 0;
        build(1, 0);
        for (ll i = 1; i <= m;i++){
            ll lc = lca(u[i], v[i]);
            ll idxs = u[i];
            while(idxs!=lc){
                fat_cost[idxs] = (fat_cost[idxs] + w[i]) % mod;
                idxs = fat[idxs][0];
            }
            idxs = v[i];
            while(idxs!=lc){
                fat_cost[idxs] = (fat_cost[idxs] + w[i]) % mod;
                idxs = fat[idxs][0];
            }
        }
        return;
    }
    for (ll i = fl[I]; i <= fr[I];i++){
        ll fat_i = get_fat(i), fat_I = get_fat(I);
        if(fat_i == fat_I){
            continue;
        }
        ll fat_fat_i = fatt[fat_i];
        fatt[fat_i] = fat_I;
        t_fat[I] = i;
        build_tree(I + 1);
        fatt[fat_i] = fat_fat_i;
    }
}

ll fast_pow(ll a,ll b){
    ll anss = 1;
    while(b){
        if(b&1){
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

ll inv(ll a){
    return fast_pow(a, mod - 2);
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 0; i <= n;i++){
        fatt[i] = i;
    }
    for (ll i = 2; i <= n;i++){
        cin >> fl[i] >> fr[i];
    }
    cin >> m;
    for (int i = 1; i <= m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    build_tree(2);
    for (int i = 2; i <= n;i++){
        cout << (fat_cost[i] * inv(cntt)) % mod << ' ';
    }
    return 0;
}