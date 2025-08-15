#include <bits/stdc++.h>
#define int unsigned long long
#define ull unsigned long long

using namespace std;

const int N = 1e7 + 5;

int n;
ull s1, s2;

ull my_rand() {
    ull s3 = s1, s4 = s2;
    s1 = s2 ^ 774527;
    s3 ^= (s3 << 47) ^ (s3 >> 13);
    s2 ^= s3 ^ (s4 << 31) ^ (s4 >> 17);
    return s2 + s4;
}

void get_query(int &op, ull &num1, ull &num2) {
    op = my_rand() % 2 + 1;
    if(op == 1) {
        num1 = my_rand() % n + 1;
        num2 = my_rand() % n + 1;
    }
    else {
        num1 = my_rand() % n + 1;
        num2 = my_rand() % n + 1;
        if(num1 > num2) swap(num1,num2);
    }
}

int Q;
ull BIT[N];

inline int lowbit(int x) {
    return x & (-x);
}

inline void update(int x, ull k) {
    ull cnt = 1;
    for(int i = x; i <= n; i += lowbit(i)) BIT[i] += cnt * k, cnt++;
    return;
}

inline ull query(int x) {
    ull Ansn = 0;
    for(int i = x; i >= 1; i -= lowbit(i)) Ansn += BIT[i];
    return Ansn;
}

signed main() {
    freopen("fenwick.in", "r", stdin);
    freopen("fenwick.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> Q >> s1 >> s2;
    int Ansn = 0;
    for(ull i = 1; i <= Q; ++i) {
        int opt; ull l, r;
        get_query(opt, l, r);
        if(opt == 1) update(l, r);
        else Ansn ^= (i * (query(r) - query(l - 1)));
    } 
    cout << Ansn << '\n';
    return 0;
}