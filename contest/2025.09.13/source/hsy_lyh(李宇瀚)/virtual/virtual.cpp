#include<bits/stdc++.h>
// #define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

using namespace std;

const int N = 2e6 + 5;

char s[N];
int n, lk, rk, q;
int su1[N], su2[N];
int l[N], r[N];
int fa[N], siz[N];

char buf[1<<21],*p1=buf,*p2=buf;
/*
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
*/

inline int read() {
    int x = 0;
    char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

void init() {
    for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    return;
}

int fin(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = fin(fa[x]);
}

void merge(int x, int y) {
    int fx = fin(x), fy = fin(y);
    if(siz[fx] < siz[fy]) {
        fa[fx] = fy, siz[fy] += siz[fx];
        siz[fx] = 0;
    }
    else {
        fa[fy] = fx, siz[fx] += siz[fy];
        siz[fy] = 0;
    }
    return;
}

int chk1(int t) {
    int l = t, r = n;
    int midn, ans = 0;
    while(l <= r) {
        midn = (l + r) >> 1;
        if(su1[midn] - su1[t - 1] < lk) l = midn + 1;
        else ans = midn, r = midn - 1;
    }
    return ans;
}

int chk2(int t) {
    int l = t, r = n;
    int midn, ans = 0;
    while(l <= r) {
        midn = (l + r) >> 1;
        if(su1[midn] - su1[t - 1] > rk) r = midn - 1;
        else ans = midn, l = midn + 1;
    }
    return ans;
}

int chk3(int x, int t1, int t2) {
    int ll = t1, rr = t2;
    int midn, ans = 0;
    while(ll <= rr) {
        midn = (ll + rr) >> 1;
        if(fin(midn) != x) ans = midn, rr = midn - 1;
        else ll = midn + 1;
    }
    return ans;
}

int main() {
    freopen("virtual.in", "r", stdin);
    freopen("virtual.out", "w", stdout);
    // double st = clock();
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    n = read(), lk = read(), rk = read();
    scanf("%s", s + 1);
    // for(int i = 1; i <= n; i++) cout << s[i];
    // cout << endl;
    for(int i = 1; i <= n; i++) {
        su1[i] = su1[i - 1], su2[i] = su2[i - 1];
        if(s[i] == 'a') su1[i]++;
        else su2[i]++;
    }
    int ll = 1, rr = 1;
    for(int i = 1; i <= n; i++) {
        while(ll <= n && su1[ll] - su1[i - 1] < lk) ll++;
        while(rr <= n && su1[rr] - su1[i - 1] <= rk) rr++;
        rr--;
        l[i] = ll, r[i] = rr;
        // cout << ll << " " << rr << endl;
    }
    // double ed = clock();
    // cout << ed - st << endl;
    // return 0;
    init();
    int nl = 1;
    for(int i = 1; i <= n; i++) {
        if(l[i] == n + 1 || r[i] == n + 1 || (l[i] > r[i])) continue;
        for(int j = max(nl, l[i]); j < r[i]; j++) merge(fin(j), fin(j + 1));
        nl = r[i];
        merge(fin(i), fin(l[i]));
    }
    q = read();
    while(q--) {
        int s, t;
        s = read(), t = read();
        if(fin(s) != fin(t)) puts("No");
        else puts("Yes");
    }
    // double ed = clock();
    // cout << ed - st << endl;
    // return 0;
    return 0;
}