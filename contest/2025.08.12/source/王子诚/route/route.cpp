#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct road_t {
    ll u, w, c;
};
struct ptick_t {
    ll u, w;
    friend bool operator<(ptick_t a, ptick_t b) {
        return a.w > b.w;
    }
};
vector<road_t> road[4050];
ll anss[100];
priority_queue<ptick_t> pq;

int main() {
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, s, q;
    cin >> n >> m >> s >> q;
    for (int i = 1;i <= m;i++) {
        ll a, b, l, c;
        cin >> a >> b >> l >> c;
        road[a].emplace_back((road_t) { b, l, c });
        road[b].emplace_back((road_t) { a, l, c });
    }
    while (q--) {
        ll u, v, t;
        cin >> u >> v >> t;
        for (int i = 0;i <= n;i++) {
            anss[i] = LLONG_MAX;
        }
        pq.push({ u,0 });
        anss[u] = 0;
        while (!pq.empty()) {
            ptick_t u = pq.top();
            pq.pop();
            if (u.w > anss[u.u]) {
                continue;
            }
            for (auto v : road[u.u]) {
                ll p = (u.w + t) % s, uw = u.w + v.w + (p > (v.c - v.w)) * (s - p);
                if (uw >= anss[v.u]) {
                    continue;
                }
                anss[v.u] = uw;
                pq.push({ v.u,uw });
            }
        }
        cout << anss[v] << '\n';
    }
}