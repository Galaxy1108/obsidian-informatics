#include <bits/stdc++.h>
using namespace std;

#define lch(a) a*2
#define rch(a) a*2+1
#define mod 998244353

using ll = long long;
ll a[250005], b[250005], c[250005];

struct smt {
    struct node {
        ll l, r;
        ll nums[3];
        ll tags[3][3] = { {-1,1,0},{-1,1,0},{-1,1,0} };
    };
    node trr[1000005];
    inline void add_tag(ll num_idx, ll idx, ll tag1, ll tag2, ll tag3) {
        trr[idx].tags[num_idx][0] = tag1;
        trr[idx].tags[num_idx][1] *= tag2;
        trr[idx].tags[num_idx][1] %= mod;
        trr[idx].tags[num_idx][2] += tag3;
        trr[idx].tags[num_idx][2] %= mod;
        ll len = (trr[idx].r - trr[idx].l + 1);
        if (trr[idx].tags[num_idx][0] != -1) {
            trr[idx].nums[num_idx] = tag1;
        }
        trr[idx].nums[num_idx] *= tag2, trr[idx].nums[num_idx] %= mod;
        trr[idx].nums[num_idx] += (tag3 * len) % mod, trr[idx].nums[num_idx] %= mod;
    }
    inline void push_up(ll num_idx, ll idx) {
        trr[idx].nums[num_idx] = (trr[lch(idx)].nums[num_idx] + trr[rch(idx)].nums[num_idx]) % mod;
    }
    void push_down(ll num_idx, ll idx) {
        add_tag(num_idx, lch(idx), trr[idx].tags[num_idx][0], trr[idx].tags[num_idx][1], trr[idx].tags[num_idx][2]);
        add_tag(num_idx, rch(idx), trr[idx].tags[num_idx][0], trr[idx].tags[num_idx][1], trr[idx].tags[num_idx][2]);
        trr[idx].tags[num_idx][0] = -1, trr[idx].tags[num_idx][1] = 1, trr[idx].tags[num_idx][2] = 0;
    }
    void build(ll idx, ll l, ll r, ll& sa, ll& sb, ll& sc) {
        if (l == r) {
            trr[idx].nums[0] = a[l];
            trr[idx].nums[1] = b[l];
            trr[idx].nums[2] = c[l];
            sa += a[l], sb += b[l], sc += c[l];
            sa %= mod, sb %= mod, sc %= mod;
            trr[idx].l = l, trr[idx].r = r;
            return;
        }
        ll mid = (l + r) / 2;
        build(lch(idx), l, mid, sa, sb, sc);
        build(rch(idx), mid + 1, r, sa, sb, sc);
        trr[idx].nums[0] = sa, trr[idx].nums[1] = sb, trr[idx].nums[2] = sc;
        trr[idx].l = l, trr[idx].r = r;
    }
    void add_v(ll idx, ll l, ll r, ll num) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        ll len = (r - l + 1);
        if (trr[idx].l >= l && trr[idx].r <= r) {
            trr[idx].nums[0] = (trr[idx].nums[0] + (num * len) % mod) % mod;
            trr[idx].tags[0][2] += num;
            trr[idx].tags[0][2] %= mod;
            return;
        }
        push_down(0, idx);
        ll mid = (l + r) / 2;
        add_v(lch(idx), l, r, num);
        add_v(rch(idx), l, r, num);
        push_up(0, idx);
    }
    void mul_v(ll idx, ll l, ll r, ll num) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        ll len = (r - l + 1);
        if (trr[idx].l >= l && trr[idx].r <= r) {
            trr[idx].nums[1] = (trr[idx].nums[0] * num) % mod;
            trr[idx].tags[1][1] *= num, trr[idx].tags[1][1] %= mod;
            trr[idx].nums[1] = (trr[idx].nums[1] + (trr[idx].tags[1][2] * len) % mod) % mod;
            trr[idx].tags[1][2] = (trr[idx].tags[1][2] * num) % mod;
            return;
        }
        push_down(1, idx);
        ll mid = (l + r) / 2;
        mul_v(lch(idx), l, r, num);
        mul_v(rch(idx), l, r, num);
        push_up(1, idx);
    }
    void set_v(ll idx, ll l, ll r, ll num) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        ll len = (r - l + 1);
        if (trr[idx].l >= l && trr[idx].r <= r) {
            trr[idx].nums[2] = (num * len) % mod;
            trr[idx].tags[2][0] = num;
            trr[idx].tags[2][1] = 1;
            trr[idx].tags[2][2] = 0;
            return;
        }
        push_down(2, idx);
        ll mid = (l + r) / 2;
        set_v(lch(idx), l, r, num);
        set_v(rch(idx), l, r, num);
        push_up(2, idx);
    }
    void query(ll idx, ll l, ll r, ll& sa, ll& sb, ll& sc) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        if (trr[idx].l >= l && trr[idx].r <= r) {
            sa = (sa + trr[idx].nums[0]) % mod;
            sb = (sb + trr[idx].nums[1]) % mod;
            sc = (sc + trr[idx].nums[2]) % mod;
            return;
        }
        push_down(0, idx), push_down(1, idx), push_down(2, idx);
        ll mid = (l + r) / 2;
        query(lch(idx), l, r, sa, sb, sc);
        query(rch(idx), l, r, sa, sb, sc);
        push_up(0, idx), push_up(1, idx), push_up(2, idx);
    }
};

smt trr;

int main() {
   freopen("magic.in", "r", stdin);
   freopen("magic.out", "w", stdout);
    ll n;
    cin >> n;
    for (ll i = 1;i <= n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll m;
    cin >> m;
     if (n <= 1000) {
         while (m--) {
             ll opt, l, r;
             cin >> opt >> l >> r;
             if (opt == 1) {
                 for (ll i = l;i <= r;i++) {
                     a[i] += b[i], a[i] %= mod;
                 }
             } else if (opt == 2) {
                 for (ll i = l;i <= r;i++) {
                     b[i] += c[i], b[i] %= mod;
                 }
             } else if (opt == 3) {
                 for (ll i = l;i <= r;i++) {
                     c[i] += a[i], c[i] %= mod;
                 }
             } else if (opt == 4) {
                 ll v;
                 cin >> v;
                 for (ll i = l;i <= r;i++) {
                     a[i] += v, a[i] %= mod;
                 }
             } else if (opt == 5) {
                 ll v;
                 cin >> v;
                 for (ll i = l;i <= r;i++) {
                     b[i] *= v, b[i] %= mod;
                 }
             } else if (opt == 6) {
                 ll v;
                 cin >> v;
                 for (ll i = l;i <= r;i++) {
                     c[i] = v, c[i] %= mod;
                 }
             } else if (opt == 7) {
                 ll suma = 0, sumb = 0, sumc = 0;
                 for (ll i = l;i <= r;i++) {
                     suma = (suma + a[i]) % mod;
                     sumb = (sumb + b[i]) % mod;
                     sumc = (sumc + c[i]) % mod;
                 }
                 cout << suma << ' ' << sumb << ' ' << sumc << '\n';
             }
         }
         return 0;
     } else {
        ll sa, sb, sc;
        sa = sb = sc = 0;
        trr.build(1, 1, n, sa, sb, sc);
        while (m--) {
            ll opt, l, r;
            cin >> opt >> l >> r;
            if (opt == 4) {
                ll v;
                cin >> v;
                trr.add_v(1, l, r, v);
                // cout << "AAA" << endl;
            } else if (opt == 5) {
                ll v;
                cin >> v;
                trr.mul_v(1, l, r, v);
                // cout << "BBB" << endl;
            } else if (opt == 6) {
                ll v;
                cin >> v;
                // cout << "CCC" << endl;
                trr.set_v(1, l, r, v);
            } else if (opt == 7) {
                sa = sb = sc = 0;
                trr.query(1, l, r, sa, sb, sc);
                cout << sa << ' ' << sb << ' ' << sc << '\n';
            }
        }
     }
}
/*
3
0 1 0 
0 1 0
0 1 0
10000
4 1 2 1
7 1 2
4 1 3 3
7 1 2
6 1 3 0
7 1 3
*/
