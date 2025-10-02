#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int h[N];
int maxn[N << 2], minn[N << 2];
int stk[N], tot;
int pre[N], suf[N];
void write(__int128 x){
    if(x < 0){
        x = -x;
        putchar('-');
    }
    if(x < 10){
        putchar(x + 48);
        return;
    }
    write(x / 10);
    putchar(x % 10 + 48);
}
__int128 Max(__int128 x, __int128 y){return (x > y) ? x : y;}
void build(int p, int l, int r){
    if(l == r){
        maxn[p] = minn[p] = h[l];
        return;
    }
    int lc = p << 1, rc = p << 1 | 1, mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    maxn[p] = max(maxn[lc], maxn[rc]);
    minn[p] = min(minn[lc], minn[rc]);
}
int querymax(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr)return maxn[p];
    int res = 0;
    int lc = p << 1, rc = p << 1 | 1, mid = l + r >> 1;
    if(ql <= mid)res = max(res, querymax(lc, l, mid, ql, qr));
    if(qr > mid)res = max(res, querymax(rc, mid + 1, r, ql, qr));
    return res;
}
int querymin(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr)return minn[p];
    int res = 2e9;
    int lc = p << 1, rc = p << 1 | 1, mid = l + r >> 1;
    if(ql <= mid)res = min(res, querymin(lc, l, mid, ql, qr));
    if(qr > mid)res = min(res, querymin(rc, mid + 1, r, ql, qr));
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("drama.in", "r", stdin);
    freopen("drama.out", "w", stdout);   
    // memset(minn, 0x3f, sizeof(minn));
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> h[i];
    build(1, 1, n);
    // for(int i = 1; i <= n; i++){
    //     for(int j = i; j <= n; j++){
    //         ans = max(ans, 1ll * querymax(1, 1, n, i, j) * querymin(1, 1, n, i, j) * (j - i + 1));
    //     }
    // }
    tot = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        while(tot && h[stk[tot]] > h[i]){
            cnt = stk[tot];
            tot--;
        }
        if(cnt)pre[i] = pre[cnt];
        else pre[i] = i;
        stk[++tot] = i;
    }
    for(int i = n; i >= 1; i--){
        int cnt = 0;
        while(tot && h[stk[tot]] > h[i]){
            cnt = stk[tot];
            tot--;
        }
        if(cnt)suf[i] = suf[cnt];
        else suf[i] = i;
        stk[++tot] = i;
    }
    __int128 ans = -1;
    // for(int i = 1; i <= n; i++)cout << pre[i] << ' ';
    // cout << endl;
    // for(int i = 1; i <= n; i++)cout << suf[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= n; i++){
        int l = pre[i], r = suf[i];
        // if(l > r)swap(l, r);
        ans = Max(ans, (__int128) querymax(1, 1, n, l, r) * (__int128)querymin(1, 1, n, l, r) * (__int128)(r - l + 1));
        // cout << l << " " << r << endl;
    }
    write(ans);
    return 0;
}
