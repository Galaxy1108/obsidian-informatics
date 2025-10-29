#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define ll long long 

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

struct segment_tree {
    vector<int> t;

    segment_tree(int n) {
        t.assign(4 * n, INF);
    }

    void mod(int v, int vl, int vr, int id, int val) {
        if (vr - vl == 1) {
            t[v] = min(t[v], val);
            return;
        }
        int vm = (vl + vr) / 2;
        if (id < vm) mod(2 * v + 1, vl, vm, id, val);
        else mod(2 * v + 2, vm, vr, id, val);
        t[v] = min(t[v], val);
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (vl >= l && vr <= r) return t[v];
        if (r <= vl || l >= vr) return INF;
        int vm = (vl + vr) / 2;
        return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
    }
};

bool cmp(const pii &a, const pii &b) {
    return a.se - a.fi < b.se - b.fi;
}

int main(int argc, char **argv)
{
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &c : a) cin >> c;
    sort(all(a));
    vector<pii> seg1(m);
    vector<int> dl;
    for (auto &c : seg1) {
        cin >> c.fi >> c.se;
        dl.pb(c.fi);
    }
    sort(all(dl));
    dl.resize(unique(all(dl)) - dl.begin());
    sort(all(seg1), cmp);
    map<int, int> ma;
    for (int i = 0; i < (int)dl.size(); i++) ma[dl[i]] = i;
    segment_tree tr((int)dl.size());
    vector<pii> seg;
    for (auto &c : seg1) {
        int id = lower_bound(all(a), c.fi) - a.begin();
        if (id < (int)a.size() && a[id] <= c.se) continue;
        if (tr.get(0, 0, dl.size(), ma[c.fi], dl.size()) <= c.se) continue;
        tr.mod(0, 0, dl.size(), ma[c.fi], c.se);
        seg.pb(c.fi, c.se);
    }
    m = seg.size();
    sort(all(seg));
    vector<vector<pii>> g(n + 1);
    int L = -1, R = m;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (seg[M].se < a[0]) L = M;
        else R = M;
    }
    for (int i = 0; i <= L; i++) g[0].pb(seg[i]);
    for (int i = 0; i < n; i++) {
        int RIGHT = INF;
        if (i + 1 < n) RIGHT = a[i + 1];
        int id = upper_bound(all(seg), make_pair((int)a[i], (int)a[i])) - seg.begin();
        if (id == m) continue;
        int L = id - 1, R = m;
        while (R - L > 1) {
            int M = (L + R) / 2;
            if (seg[M].se < RIGHT) L = M;
            else R = M;
        }
        for (int j = id; j <= L; j++) g[i + 1].pb(seg[j]);
    }
    vector<vector<ll>> dp(n), pr(n), suff(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(g[i + 1].size() + 1, INFLL);
        pr[i].resize(g[i + 1].size() + 1, INFLL);
        suff[i].resize(g[i + 1].size() + 1, INFLL);
    }
    for (int j = 0; j <= (int)g[1].size(); j++) {
        ll x = 0;
        if (g[0].size()) x = a[0] - g[0][0].se;
        ll y = 0;
        if (j) y = g[1][j - 1].fi - a[0];
        dp[0][j] = 2 * min(x, y) + max(x, y);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= (int)g[i].size(); j++) {
            if (j > 0) pr[i - 1][j] = pr[i - 1][j - 1];
            pr[i - 1][j] = min(pr[i - 1][j], dp[i - 1][j] - (j == (int)g[i].size() ? a[i] : g[i][j].se));
        }
        for (int j = (int)g[i].size(); j >= 0; j--) {
            if (j + 1 <= (int)g[i].size()) suff[i - 1][j] = suff[i - 1][j + 1];
            suff[i - 1][j] = min(suff[i - 1][j], dp[i - 1][j] - 2 * (j == (int)g[i].size() ? a[i] : g[i][j].se));
        }
        int L = (int)g[i].size();
        for (int j = 0; j <= (int)g[i + 1].size(); j++) {
            ll y = 0;
            if (j) y = g[i + 1][j - 1].fi - a[i];
            while (L > 0 && a[i] - g[i][L - 1].se <= y) L--;
            if (L > 0) dp[i][j] = min(dp[i][j], 2 * y + a[i] + pr[i - 1][L - 1]);
            dp[i][j] = min(dp[i][j], y + 2 * a[i] + suff[i - 1][L]);
        }
    }
    cout << dp[n - 1].back() << "\n";
    return 0;
}