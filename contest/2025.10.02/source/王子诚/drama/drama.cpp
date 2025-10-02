// __int128

#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;

int sn[2000005];

int l[2000005], r[2000005];
int st[2000005][21];
int ls[2000005], rs[2000005];
int top_l, top_r, n;

void init() {
    for (int i = 1;i <= n;i++) {
        st[i][0] = sn[i];
    }
    // int f = log2(n);
    for (int i = 1;i <= 20;i++) {
        for (int j = 1;j + (1 << i) <= n + 1;j++) {
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int query(int l, int r) {
    int f = log2(r - l + 1);
    return max(st[l][f], st[r - (1 << f) + 1][f]);
}

void output(i128 data) {
    if (data < 0) {
        cout << '-';
        data = -data;
    }
    if (data == 0) {
        cout << '0';
    }
    int len = 0;
    char buf[50];
    while (data) {
        buf[len++] = data % 10 + '0';
        data /= 10;
    }
    while (len--) {
        cout << buf[len];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("drama.in", "r", stdin);
    freopen("drama.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> sn[i];
    }
    for (int i = 1;i <= n;i++) {
        while (top_l && sn[i] < sn[l[top_l]]) {
            rs[l[top_l]] = i;
            top_l--;
        }
        l[++top_l] = i;
    }
    while(top_l){
    	rs[l[top_l--]] = n + 1;
	}
    for (int i = n;i >= 1;i--) {
        while (top_r && sn[i] < sn[r[top_r]]) {
        	ls[r[top_r]] = i;
            top_r--;
        }
        r[++top_r] = i;
    }
    while(top_r){
    	ls[r[top_r--]] = 0;
    }
    init();
    i128 ans = 0;
    for (int i = 1;i <= n;i++) {
        int tl = ls[i] + 1;
        int tr = rs[i] - 1;
        ans = max(ans, (__int128)(tr - tl + 1) * query(tl, tr) * sn[i]);
    }
    output(ans);
}