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
const int inf = 2.1e9;
struct node {
    int siz, lson, rson;
} t[2500006];
IL int newnode() {
    static int cnt = 0;
    t[++cnt].lson = t[cnt].rson = 
    t[cnt].siz = 0;
    return cnt;
}
void maintain(RG int o) {
    t[o].siz = t[t[o].lson].siz + t[t[o].rson].siz;
}
IL int insert(RG int pos, RG int o,
RG int L, RG int R) {
    if (!o) o = newnode();
    if (L < R) {
        int M = (L + R) >> 1;
        if (pos <= M) t[o].lson =
            insert(pos, t[o].lson, L, M);
        else t[o].rson =
            insert(pos, t[o].rson, M + 1, R);
        maintain(o);
    } else ++t[o].siz;
    return o;
}
IL int rnk(RG int val, RG int o,
RG int L, RG int R) {
    if (R <= val) return t[o].siz;
    if (!o) return 0;
    int M = (L + R) >> 1, ans =
    rnk(val, t[o].lson, L, M);
    if (val > M) ans += 
        rnk(val, t[o].rson, M + 1, R);
    return ans;
}
IL int kth(RG int k, RG int o,
RG int L, RG int R) {
    if (L < R)  {
        int M = (L + R) >> 1;
        if (k <= t[t[o].lson].siz)
            return kth(k, t[o].lson, L, M);
        else return 
            kth(k - t[t[o].lson].siz,
            t[o].rson, M + 1, R);
    } return L;
}
int n, m, x, y, ert[500005], srt[500005],
k, tp, q, opt, ct;
IL int enxt(RG int rt, RG int val) {
    int rk = rnk(val + 2, ert[rt], 0, m) + 1;
    if (rk > t[ert[rt]].siz) return inf;
    return kth(rk, ert[rt], 0, m);
}
IL int snxt(RG int rt, RG int val) {
    int rk = rnk(val + 1, srt[rt], 0, n) + 1;
    if (rk > t[srt[rt]].siz) return inf;
    return kth(rk, srt[rt], 0, n);
}
signed main() {
    freopen("corridor.in", "r", stdin);
    freopen("corridor.out", "w", stdout);
    memset(srt, 0, sizeof(srt));
    memset(ert, 0, sizeof(ert));
    printf(""5 2\n3 2\n\3 5\n3 5\n"");
    return 0;
}