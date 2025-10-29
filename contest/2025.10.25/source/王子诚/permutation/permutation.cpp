#include <bits/stdc++.h>
using namespace std;

int a[305], p[305], q[305], b[305], g[305], s;
bool vis[305];

char f[100];
set<string> st;

int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= 2 * n;i++) {
        cin >> a[i];
        if (a[i] == -1) {
            continue;
        }
        vis[a[i]] = true;
    }
    for (int i = 1;i <= 2 * n;i++) {
        if (!vis[a[i]]) {
            p[++s] = i;
        }
    }
    for (int i = 1;i <= s;i++) {
        q[i] = i;
    }
    do {
        int c = 0;
        for (int i = 1;i <= 2 * n;i++) {
            b[i] = (a[i] == -1 ? p[q[++c]] : a[i]);
            g[i / 2] = INT_MAX;
        }
        string str;
        for (int i = 1;i <= n;i++) {
            g[i] = min(b[2 * i - 1], b[2 * i]);
            itoa(g[i], f, 10);
            str += f;
            str += " ";
        }
        st.insert(str);
    } while (next_permutation(q + 1, q + 1 + s));
    cout << st.size() << '\n';
}
