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
        ll tagss[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
        ll tags[3][3] = { {-1,1,0},{-1,1,0},{-1,1,0} };
    };
    node trr[250005];
    inline void add_tag(int num_idx, int idx, ll tag1, ll tag2, ll tag3) {
        if (tag1 != -1) {
            trr[idx].tags[num_idx][0] = tag1;
            trr[idx].tags[num_idx][1] = 1;
            trr[idx].tags[num_idx][2] = 0;
            trr[idx].tags[num_idx][0] = trr[idx].tags[num_idx][1] = trr[idx].tags[num_idx][2] = 0;
            trr[idx].tags[num_idx][num_idx] = 1;
        }
        trr[idx].tags[num_idx][1] *= tag2;
        trr[idx].tags[num_idx][2] += tag3;
        int len = (trr[idx].r - trr[idx].l + 1);
        if (trr[idx].tags[num_idx][0] != -1) {
            trr[idx].nums[num_idx] = trr[idx].tags[num_idx][0];
        }
        trr[idx].nums[num_idx] *= trr[idx].tags[num_idx][1], trr[idx].nums[num_idx] %= mod;
        trr[idx].nums[num_idx] += trr[idx].tags[num_idx][2] * len, trr[idx].nums[num_idx] %= mod;
    }   
    inline void push_up(int num_idx, int idx) {
        trr[idx].nums[num_idx] = (trr[lch(idx)].nums[num_idx] + trr[rch(idx)].nums[num_idx]) % mod;
    }
    void push_down(int num_idx, int idx) {
        add_tag(num_idx, lch(idx), trr[idx].tags[num_idx][0], trr[idx].tags[num_idx][1], trr[idx].tags[num_idx][2]);
        add_tag(num_idx, rch(idx), trr[idx].tags[num_idx][0], trr[idx].tags[num_idx][1], trr[idx].tags[num_idx][2]);
        trr[idx].tags[num_idx][0] = -1, trr[idx].tags[num_idx][1] = 1, trr[idx].tags[num_idx][2] = 0;
    }
    void build(ll idx, int l, int r, ll& sa, ll& sb, ll& sc) {
        if (l == r) {
            trr[idx].nums[0] = a[idx];
            trr[idx].nums[1] = b[idx];
            trr[idx].nums[2] = c[idx];
            sa += a[idx], sb += b[idx], sc += c[idx];
            sa %= mod, sb %= mod, sc %= mod;
            trr[idx].l = l, trr[idx].r = r;
            return;
        }
        int mid = (l + r) / 2;
        build(lch(idx), l, mid, sa, sb, sc);
        build(rch(idx), mid + 1, r, sa, sb, sc);
        trr[idx].nums[0] = sa, trr[idx].nums[1] = sb, trr[idx].nums[2] = sc;
        trr[idx].l = l, trr[idx].r = r;
    }
    void add_n(ll idx, int l, int r, int num_idx) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        int nidx = (num_idx + 1) % 3, nnidx = (num_idx + 1) % 3;
        if (trr[idx].l >= l && trr[idx].r <= r) {
            trr[idx].tags[num_idx][2] += trr[idx].nums[nidx];
            return;
        }
        push_down(nidx, idx);
        push_down(nnidx, idx);
        int mid = (l + r) / 2;
        add_n(lch(idx), l, mid, num_idx);
        add_n(rch(idx), mid + 1, r, num_idx);
        push_up(nidx, idx);
    }
    void add_v(ll idx, int l, int r, ll num) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        if (trr[idx].l >= l && trr[idx].r <= r) {
            trr[idx].nums += 
        }
    }
    void query(ll idx, int l, int r, ll& sa, ll& sb, ll& sc) {
        if (trr[idx].l > r || trr[idx].r < l) {
            return;
        }
        push_down(0, idx), push_down(1, idx), push_down(2, idx);
        
    }
}

