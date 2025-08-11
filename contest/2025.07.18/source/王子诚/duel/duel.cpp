#include <bits/stdc++.h>
using namespace std;

int p[200005];
int tp[200005];
int st[200005][20];

int n, q;

void build(){
    for (int i = 1; i <= n;i++){
        st[i][0] = p[i];
    }
    for (int k = 1; (1 << k) <= n;k++){
        for (int i = 1; i + (1 << k) - 1 <= n;i++){
            st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]) - min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        cin >> p[i];
    }
    build();
    bool is_st = true;
    while(q--){
        int opt;
        cin >> opt;
        int i, r, l, k;
        if(opt==1){
            cin >> i >> r;
            p[i] = r;
            is_st = false;
            continue;
        }
        cin >> l >> k;
        if(n==(1<<k)){
            build();
            is_st = true;
        }
        if(is_st){
            cout << st[l][k] << '\n';
            continue;
        }
        for (int i = 1; i <= (1 << k);i++){
            tp[i] = p[l + i - 1];
        }
        while(k){
            int tops = 0;
            for (int i = 1; i <= (1 << k);i+=2){
                tp[++tops] = max(tp[i], tp[i + 1]) - min(tp[i], tp[i + 1]);
            }
            k--;
        }
        cout << tp[1] << '\n';
    }
}