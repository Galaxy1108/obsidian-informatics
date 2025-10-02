/*
Why?
我放弃了
*/


#include <bits/stdc++.h>
using namespace std;

int cnts[2];
int unmoved_cnt[2];
bool res[1000005];
bool is_unmoved[1000005];
int empty_len11, empty_len00, empty_len01;
int elen11s[1000005], elen00s[1000005], elen01s[1000005];
int top_elen11, top_elen00, top_elen01;

int dp[105][105][2];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1;i <= n;i++) {
        int num;
        cin >> num;
        cnts[num % 2]++;
    }
    while (m--) {
        int p, b;
        cin >> p >> b;
        res[p] = b % 2;
        is_unmoved[p] = true;
        unmoved_cnt[b % 2]++;
    }
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int p;
            cin >> p;
            unmoved_cnt[res[p]]--;
            is_unmoved[p] = false;
            res[p] = false;
        } else {
            int p, x;
            cin >> p >> x;
            res[p] = x % 2;
            is_unmoved[p] = true;
            unmoved_cnt[x % 2]++;
        }
        bool is_empty = false;
        int this_elen = 0;
        bool l_node; 
        empty_len00 = empty_len11 = empty_len01 = 0;
        top_elen00 = top_elen01 = top_elen11 = 0;
        for (int i = 1;i <= n;i++) {
            if (i == 1 && !is_unmoved[i]) {
                is_empty = true;
            }
            if (is_empty && is_unmoved[i]) {
                is_empty = false;
                if ((l_node == res[i] || i - this_elen == 0) && res[i] == 1) {
                    empty_len11 += this_elen;
                    elen11s[++top_elen11] = this_elen;
                } else if (l_node == res[i] && res[i] == 0) {
                    empty_len00 += this_elen;
                    elen00s[++top_elen00] = this_elen;
                } else {
                    empty_len01 += this_elen;
                    elen01s[++top_elen01] = this_elen;
                }
                this_elen = 0;
            } else if (!is_empty && is_unmoved[i]) {
                is_empty = true;
                l_node = res;
            }
            this_elen += is_empty;
        }
    }
}