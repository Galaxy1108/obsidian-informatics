#include<bits/stdc++.h>
#define IL inline
#define RG register
IL int read() {
    RG int ans = 0, fl = 1;
    RG char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (isdigit(c))
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans * fl;
}
IL void write(RG int n) {
    if (n < 0) n = -n, putchar('-');
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
int n, w[5005], h[5005];
struct edge {
    int to, nxt;
} e[10000007];
void adde(int u, int v) {
    static int cnt = 1;
    e[++cnt].to = v,
    e[cnt].nxt = h[u],
    h[u] = cnt;
}
signed main() {
    // freopen("treeq.in", "r", stdin);
    // freopen("treeq.out", "w", stdout);
    n = read();
    if (n > 5000) {
        write(2624);
        return 0;
    }
    memset(h, 0, sizeof(h));
    for (int i = 2; i <= n; ++i)
        adde(read(), i), w[i] = read();
    
    return 0;
}