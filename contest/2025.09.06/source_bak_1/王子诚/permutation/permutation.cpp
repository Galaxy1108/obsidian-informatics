#include <bits/stdc++.h>
using namespace std;

#define N 100005
int n;

struct s {
    int p[N];
    friend istream& operator>>(istream& in, s& a) {
        for (int i = 1;i <= n;i++) {
            in >> a.p[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, s a) {
        for (int i = 1;i <= n;i++) {
            out << a.p[i] << ' ';
        }
        return out;
    }
    friend s operator*(s p, s q) {
        s h;
        for (int i = 1;i <= n;i++) {
            h.p[i] = q.p[p.p[i]];
        }
        return h;
    }
    friend bool operator==(s p, s q) {
        for (int i = 1;i <= n;i++) {
            if (p.p[i] != q.p[i]) {
                return false;
            }
        }
        return true;
    }
    s inv() {
        s ans;
        for (int i = 1;i <= n;i++) {
            ans.p[p[i]] = i;
        }
        return ans;
    }
    inline bool next_permutation() {
        return std::next_permutation(p + 1, p + 1 + n);
    }
    void init() {
        for (int i = 1;i <= n;i++) {
            p[i] = i;
        }
    }
    void clear() {
        for (int i = 1;i <= n;i++) {
            p[i] = 0;
        }
    }
};

s p, q, h;
bool vis[N];

int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    cin >> n;
    cin >> p >> q;
    if (n > 10) {
        h.clear();
        h.p[1] = 1;
        bool flag = true;
        int cnts = 0;
        for (int j = 1;!vis[j];j = q.p[j]) {
            int l_num = p.p[h.p[j]];
            if (h.p[q.p[j]] != 0 && h.p[q.p[j]] != l_num) {
                flag = false;
                break;
            }
            if (!h.p[q.p[j]]) {
                h.p[q.p[j]] = l_num;
            }
            vis[j] = true;
            cnts++;
        }
        if (flag && cnts == n) {
            cout << "YES\n";
            cout << h;
            return 0;
        }
        cout << "NO";
        return 0;
    }
    h.init();
    do {
        if (q * h == h * p) {
            cout << "YES\n";
            cout << h;
            return 0;
        }
    } while (h.next_permutation());
    cout << "NO";
    return 0;
}