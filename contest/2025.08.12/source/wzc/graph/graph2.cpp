#include <bits/stdc++.h>
using namespace std;

vector<int> a[2000005];
int fat[2000005];
int anss[2000005], cnt;
int us[2000005], vs[2000005];
int n, m;

int get_father(int a) {
    return (fat[a] == a ? a : fat[a] = get_father(fat[a]));
}
int idx(int s, int k) {
    return n * (k - 1) + s;
}
bool check(int k, int u, int v) {
    // cout << "A " << get_father(idx(u, k)) << ' ' << get_father(idx(v, k)) << ' ' << k << '\n';
    return (get_father(idx(u, k)) != get_father(idx(v, k)));
}

int a1, a2;
bool dfs(int u, int f) {
    anss[++cnt] = u;
    if (u == a2) {
        return true;
    }
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        if (dfs(v, u)) {
            return true;
        }
    }
    cnt--;
    return false;
}

int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int k = m / (n - 1) + !!(m % (n - 1));
        for (int i = 0;i <= n * k;i++) {
            fat[i] = i;
            a[i].clear();
        }
        int ansu = -1, ansv = -1;
        for (int i = 1;i <= m;i++) {
            cin >> us[i] >> vs[i];
        }
        for (int i = 1;i <= m;i++) {
            int u = us[i], v = vs[i];
            int l = 1, r = k, ans;
            while (l <= r) {
                int mid = (l + r) / 2;
//                 cout << '-' << l << ' ' << r << '\n';
                if (check(mid, u, v)) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            int fat_u = get_father(idx(u, ans)), fat_v = get_father(idx(v, ans));
            // assert(fat_u != fat_v);
            fat[fat_u] = fat_v;
            a[idx(u, ans)].push_back(idx(v, ans));
            a[idx(v, ans)].push_back(idx(u, ans));
            // if (ans == 1) {
            //     cout << u << '=' << v << endl;
            // }
            if (ans == k) {
                ansu = u, ansv = v;
                break;
            }
        }
        if (ansu == -1) {
            cout << -1 << '\n';
            continue;
        }
        cout << ansu << ' ' << ansv << '\n';
        for (int i = 1;i <= k;i++) {
            cnt = 0;
            a2 = idx(ansv, i);
            dfs(idx(ansu, i), 0);
            cout << cnt << ' ';
            for (int j = 1;j <= cnt;j++) {
                cout << anss[j] - n * (i - 1) << ' ';
            }
            cout << '\n';
        }
    }
}
