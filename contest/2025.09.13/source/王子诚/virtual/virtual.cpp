#include <bits/stdc++.h>
using namespace std;

int fat[2000005];
int numa[2000005];
int anum[2000005];
int acnt[2000005];
int attt[2000005];

int get_fat(int a) {
    return fat[a] == a ? a : fat[a] = get_fat(fat[a]);
}

int main() {
    freopen("virtual.in", "r", stdin);
    freopen("virtual.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, lk, rk;
    cin >> n >> lk >> rk;
    string str;
    cin >> str;
    str = " " + str;
    if (lk == rk) {
        int cnt = 0, cnta = 0;
        for (int i = 1;i <= n;i++) {
            if (str[i - 1] != 'b' || str[i] != 'b') {
                cnt++;
            }
            numa[i] = cnt;
            anum[cnt] = i;
            if (str[i] == 'a') {
                cnta++;
                attt[cnta] = cnt;
            }
            acnt[cnt] = cnta;
        }
        cnt = numa[n];
        for (int i = 1;i <= cnt;i++) {
            fat[i] = i;
        }
        for (int i = 1;i <= cnt;i++) {
            if (str[anum[i]] == 'a') {
                if (cnta >= acnt[i] + lk - 1) {
                    int its = attt[acnt[i] + lk - 1];
                    int fu = get_fat(i), fv = get_fat(its);
                    if (fu != fv) {
                        fat[fu] = fv;
                    }
                }
                if (cnta >= acnt[i] + lk - 1) {
                    int its = attt[acnt[i] + lk - 1] + 1;
                    if (cnt >= its && str[anum[its]] == 'b') {
                        int fu = get_fat(i), fv = get_fat(its);
                        if (fu != fv) {
                            fat[fu] = fv;
                        }
                    }
                }
            } else {
                if (cnta >= acnt[i - 1] + lk) {
                    int its = attt[acnt[i - 1] + lk];
                    int fu = get_fat(i), fv = get_fat(its);
                    if (fu != fv) {
                        fat[fu] = fv;
                    }
                }
                if (cnta >= acnt[i - 1] + lk) {
                    int its = attt[acnt[i - 1] + lk] + 1;
                    if (cnt >= its && str[anum[its]] == 'b') {
                        int fu = get_fat(i), fv = get_fat(its);
                        if (fu != fv) {
                            fat[fu] = fv;
                        }
                    }
                }
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << (get_fat(numa[x]) == get_fat(numa[y]) ? "Yes\n" : "No\n");
        }
        return 0;
    }
    int cntl = 0, rr = n + 1;
    for (int i = 1;i <= n;i++) {
        if (str[i] == 'a') {
            cntl++;
        }
        if (cntl == lk) {
            rr = i;
            break;
        }
    }
    int cntr = 0, ll = 0;
    for (int i = n;i >= 1;i--) {
        if (str[i] == 'a') {
            cntr++;
        }
        if (cntr == lk) {
            ll = i;
            break;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (((x != y) && ((ll<x && rr>x) || (ll<y && rr>y))) ? "No\n" : "Yes\n");
    }
}
