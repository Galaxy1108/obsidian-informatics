#include <bits/stdc++.h>
using namespace std;

int sn[1000005];

struct s {
    int num, idx;
    friend bool operator>(s a, s b) {
        return (a.num == b.num ? a.idx > b.idx : a.num > b.num);
    }
    friend bool operator<(s a, s b) {
        return (a.num == b.num ? a.idx < b.idx : a.num < b.num);
    }
};

deque<s> min_max, max_min;

s query_max(bool is_pop) {
    s max1 = (min_max.empty() ? (s) { -1, -1 } : min_max.back());
    s max2 = (max_min.empty() ? (s) { -1, -1 } : max_min.front());
    if (is_pop) {
        (max1 > max2 ? min_max.pop_back() : max_min.pop_front());
    }
    return max(max1, max2);
}

s query_min(bool is_pop) {
    s min1 = (min_max.empty() ? (s) { INT_MAX, -1 } : min_max.front());
    s min2 = (max_min.empty() ? (s) { INT_MAX, -1 } : max_min.back());
    if (is_pop) {
        (min1 < min2 ? min_max.pop_front() : max_min.pop_back());
    }
    return min(min1, min2);
}

bool is_can_eat() {
    if (min_max.size() + max_min.size() == 2) {
        return true;
    }
    s maxs = query_max(true);
    s mins = query_min(true);
    s l_mins = query_min(false);
    if (!((s) { maxs.num - mins.num, maxs.idx } < l_mins)) {
        return true;
    }
    max_min.push_back({ maxs.num - mins.num, maxs.idx });
    return !is_can_eat();
}


int main() {
    int T;
    cin >> T;
    int n;
    cin >> n;
    for (int TT = 1;TT <= T;TT++) {
        min_max.clear(), max_min.clear();
        if (TT == 1) {
            for (int i = 1;i <= n;i++) {
                cin >> sn[i];
            }
        } else {
            int k;
            cin >> k;
            for (int i = 1;i <= k;i++) {
                int x, y;
                cin >> x >> y;
                sn[x] = y;
            }
        }
        for (int i = 1;i <= n;i++) {
            min_max.push_back({ sn[i],i });
        }
        int die_cnt = 0;
        while (1) {
            s maxs = query_max(true);
            s mins = query_min(true);
            s l_mins = query_min(false);
            max_min.push_back({ maxs.num - mins.num, maxs.idx });
            if ((s) { maxs.num - mins.num, maxs.idx } < l_mins) {
                break;
            }
            die_cnt++;
        }
        cout << n - die_cnt - !is_can_eat() << '\n';
    }
}