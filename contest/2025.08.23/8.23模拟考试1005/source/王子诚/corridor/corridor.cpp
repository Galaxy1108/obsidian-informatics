#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using ll = long long;
ll type, n, m, k;

__gnu_pbds::tree
<
    ll,
    __gnu_pbds::null_type,
    less<ll>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
> xs[50005], ys[50005];

// ll x_nxt[50005], x_pre[50005], y_nxt[50005], y_pre[50005];

void add(ll, ll);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("corridor.in", "r", stdin);
    freopen("corridor.out", "w", stdout);
    cin >> type >> n >> m >> k;
    for (int i = 1;i <= k;i++) {
        ll x, y;
        cin >> x >> y;
        add(x, y);
    }
    ll q;
    cin >> q;
    while (q--) {
        ll opt, x, y, d;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            add(x, y);
        } else {
            cin >> x >> y >> d;
            int its_x = x, its_y = y;
            bool is_x = (x == 0), flag = true;
            while (d--) {
                if (is_x) {
                    auto its = xs[its_y].upper_bound(its_x);
                    if (its == xs[its_y].end()) {
                        flag = false;
                        cout << n + 1 << ' ' << its_y << '\n';
                        break;
                    }
                    its_x = *(its);
                    is_x = false;
                } else {
                    auto its = ys[its_x].upper_bound(its_y);
                    if (its == ys[its_x].end()) {
                        flag = false;
                        cout << its_x << ' ' << m + 1 << '\n';
                        break;
                    }
                    its_y = *(its);
                    is_x = true;
                }
            }
            if (flag) {
                cout << its_x << ' ' << its_y << '\n';
            }
        }
    }
}

inline void add(ll x, ll y) {
    auto xits = xs[y].insert(x);
    auto yits = ys[x].insert(y);
}