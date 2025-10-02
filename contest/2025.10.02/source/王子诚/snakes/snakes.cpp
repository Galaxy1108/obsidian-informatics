#include <bits/stdc++.h>
using namespace std;

int sn[50005];

struct s {
    int num, idx;
    friend bool operator>(s a, s b) {
        return (a.num == b.num ? a.idx > b.idx : a.num > b.num);
    }
    friend bool operator<(s a, s b) {
        return (a.num == b.num ? a.idx < b.idx : a.num < b.num);
    }
    friend bool operator==(s a, s b) {
        return (a.num == b.num && a.idx == b.idx);
    }
};

set<s> p;
// set<int> ps;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    // ps.insert(1);
    // ps.insert(2);
    // ps.insert(3);
    // ps.erase(ps.begin());
    // cout << *(ps.begin());
    int T;
    cin >> T;
    T--;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> sn[i];
        p.insert({ sn[i],i });
    }
    if (n == 3) {
        if (sn[3] - sn[1] >= sn[2]) {
            cout << 1 << '\n';
        } else {
            cout << 3 << '\n';
        }
    } else {
        int die_cnt = 0;
        while (1) {
            auto maxs = prev(p.end());
            auto mins = p.begin();
            auto l_mins = next(p.begin());
            if ((*l_mins) == (*maxs)) {
                die_cnt++;
                break;
            }
            if ((s) { (*maxs).num - (*mins).num, (*maxs).idx } < (*l_mins)) {
                break;
            }
            die_cnt++;
            s maxs_s = *maxs, mins_s = *mins;
            p.erase(prev(p.end()));
            p.insert({ maxs_s.num - mins_s.num, maxs_s.idx });
            p.erase(p.begin());
        }
        cout << (n - die_cnt - 1) / 2 * 2 + 1 << '\n';
    }
    while (T--) {
        p.clear();
        int k;
        cin >> k;
        for (int i = 1;i <= k;i++) {
            int x, y;
            cin >> x >> y;
            sn[x] = y;
        }
        for (int i = 1;i <= n;i++) {
            p.insert({ sn[i],i });
            // cout << sn[i] << ' ';
        }
        if (n == 3) {
            if (sn[3] - sn[1] >= sn[2]) {
                cout << 1 << '\n';
            } else {
                cout << 3 << '\n';
            }
        } else {
            int die_cnt = 0;
            while (1) {
                auto maxs = prev(p.end());
                auto mins = p.begin();
                auto l_mins = next(p.begin());
                if ((*l_mins) == (*maxs)) {
                    die_cnt++;
                    break;
                }
                if ((s) { (*maxs).num - (*mins).num, (*maxs).idx } < (*l_mins)) {
                    break;
                }
                die_cnt++;
                s maxs_s = *maxs, mins_s = *mins;
                p.erase(prev(p.end()));
                p.insert({ maxs_s.num - mins_s.num, maxs_s.idx });
                p.erase(p.begin());
            }
            cout << (n - die_cnt - 1) / 2 * 2 + 1 << '\n';
        }
    }
}