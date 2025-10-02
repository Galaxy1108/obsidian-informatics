#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int N = 2e6 + 6;
int h[N], l[N], r[N], lst, t[N << 2], tmp;
signed n;
stack<pair<signed, int>> st;
pair<signed, int> p[N];
int max(int a, int b) {
	return a > b ? a : b;
}
void build(signed o, signed L, signed R) {
    if (L ^ R) {
        signed M = (L + R) >> 1;
        build(o << 1, L, M);
        build((o << 1) | 1, M + 1, R);
        t[o] = max(t[o << 1], t[(o << 1) | 1]);
    } else t[o] = h[L];
}
int query(signed l, signed r,
signed o, signed L, signed R) {
    if (l > L || R > r) {
        signed M = (L + R) >> 1;
		int ans = 0;
        if (l <= M) ans = max(ans,
            query(l, r, o << 1, L, M));
        if (r > M) ans = max(ans,
            query(l, r, (o << 1) | 1, M + 1, R));
        return ans;
    }
    return t[o];
}
int read() {
	int ans = 0, fl = 1;
	char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (isdigit(c))
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans;
}
void write(int n) {
    if (n < 0) n = -n, putchar('-');
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
signed main() {
	freopen("drama.in", "r", stdin);
	freopen("drama.out", "w", stdout);
    n = read();
    for (signed i = 1; i <= n; ++i)
        h[i] = read(),
        p[i] = make_pair(i, h[i]);
    st.push(make_pair(0, 0));
    for (signed i = 1; i <= n; ++i) {
        while (st.top().second > h[i])
            r[st.top().first] = i - 1,
            st.pop();
        st.push(p[i]);
    }
    while (!st.empty())
        r[st.top().first] = n,
        st.pop();
    st.push(make_pair(0, 0));
    for (signed i = n; i; --i) {
        while (st.top().second > h[i])
            l[st.top().first] = i + 1,
            st.pop();
        st.push(p[i]);
    }
    while (!st.empty())
        l[st.top().first] = 1,
        st.pop();
    build(1, 1, n);
    int ans = 0;
    for (signed i = 1; i <= n; ++i)
        ans = max(ans,
        h[i] * (r[i] - l[i] + 1) *
        query(l[i], r[i], 1, 1, n));
    write(ans), putchar('\n');
    return 0;
}
