#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m, k, d;
ll s[25][25];

ll f(int x,int y){
    ll mins = LLONG_MAX;
    for (int i = 1; i <= m;i++){
        mins = min(mins, s[x][i]);
    }
    for (int i = 1; i <= n;i++){
        mins = min(mins, s[i][y]);
    }
    return mins;
}

ll anss;

void get_s(int I){
    if(I==n*m){
        ll res = 1;
        for (int x = 1; x <= n;x++){
            for (int y = 1; y <= m;y++){
                res *= f(x, y);
                res %= d;
            }
        }
        anss += res;
        anss %= d;
        return;
    }
    for (int i = 1; i <= k;i++){
        int tx = (I / m) + 1, ty = (I % m) + 1;
        s[tx][ty] = i;
        get_s(I + 1);
    }
}

int main(){
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    cin >> n >> m >> k >> d;
    get_s(0);
    cout << anss;
}