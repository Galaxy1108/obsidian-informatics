#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000009

ll b[100005], bi[100005], n, m;

void add(ll idx, ll num) {
    for (ll i = idx;i <= n;i += (i & (-i))) {
        b[i] += num, bi[i] += num * idx;
        b[i] %= mod, b[i] %= mod;
    }
}

ll query(ll idx) {
    ll anss = 0;
    for (ll i = idx;i > 0;i -= (i & (-i))) {
        anss += (((b[i] * (idx + 1)) % mod) - bi[i] + mod) % mod;
        anss %= mod;
    }
    return anss;
}

ll L[100005], R[100005], x[100005];
ll u[100005], d[100005], l[100005], r[100005];
ll a[100006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("newfile.in", "r", stdin);
    freopen("newfile.out", "w", stdout);
    ll q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m;i++){
        cin >> L[i] >> R[i] >> x[i];
    }
    for (int i = 1; i <= q;i++){
        cin >> u[i] >> d[i] >> l[i] >> r[i];
    }
    for (int i = 1; i <= m;i++){
        add(L[i], x[i]), add(R[i] + 1, -x[i]);
        for (int j = 1; j <= q;j++){
            if(i >= u[j] && i <= d[j]){
                a[j] += (query(r[j]) - query(l[j] - 1) + mod) % mod;
                a[j] %= mod;
            }
        }
    }
    for (int i = 1; i <= q;i++){
        cout << a[i] << '\n';
    }
}