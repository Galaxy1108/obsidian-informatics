#include <bits/stdc++.h>
using namespace std;

int nums[10000];
int n, x, y;

int numt[10000];

int lowbit(int n) {
    return (n & (-n));
}

void add(int idx) {
    for (int i = idx;i <= n * n;i+=lowbit(i)) {
        numt[i]++;
    }
}

int query(int idx) {
    int anss = 0;
    for (int i = idx;i > 0;i -= lowbit(i)) {
        anss += numt[i];
    }
    return anss;
}

int get_n1() {
    for (int i = 1;i <= n * n;i++) {
        numt[i] = 0;
    }
    int anss = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            int idx = (i - 1) * n + j;
            anss += (idx - 1) - query(nums[idx]);
            add(nums[idx]);
        }
    }
    return anss;
}

int get_n2() {
    for (int i = 1;i <= n * n;i++) {
        numt[i] = 0;
    }
    int anss = 0;
    for (int j = 1;j <= n;j++) {
        for (int i = 1;i <= n;i++) {
            int idx = (i - 1) * n + j;
            anss += (idx - 1) - query(nums[idx]);
            add(nums[idx]);
        }
    }
    return anss;
}

int main() {
    freopen("matrixcascade.in", "r", stdin);
    freopen("matrixcascade.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        for (int i = 1;i <= n * n;i++) {
            nums[i] = i;
        }
        bool flag = true;
        do {
            if (get_n1() == x && get_n2() == y) {
                cout << "Yes\n";
                for (int i = 1;i <= n;i++) {
                    for (int j = 1;j <= n;j++) {
                        cout << nums[(i - 1) * n + j] << ' ';
                    }
                    cout << '\n';
                }
                flag = false;
                break;
            }
            // cout << get_n1() << ' ' << get_n2() << '\n';
        } while (next_permutation(nums + 1, nums + 1 + n * n));
        if (flag) {
            cout << "No\n";
        }
    }
}
