#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n;
int x[500005];
bool chk(int a, int b, int c, int l, int r){
    for(int i = l; i <= r; i++){
        if((a * (i - l) + b) / c != x[i])return 0;
    }
    return 1;
}
signed main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> T;
    while(T--){
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &x[i]);
        }
        int q;
        scanf("%lld", &q);
        int op = 0;
        if(n <= 20 && q <= 20)op = 1;
        while(q--){
            int l, r;
            scanf("%lld%lld", &l, &r);
            int ok = 0;
            if(op){
                for(int c = 1; c <= 10; c++){
                    for(int a = 0; a <= 10; a++){
                        for(int b = 0; b <= 10; b++){
                            if(chk(a, b, c, l, r)){
                                printf("%lld %lld %lld\n", a, b, c);
                                ok = 1;
                                break;
                            }
                        }
                        if(ok)break;
                    }
                    if(ok)break;
                }
            }
            if(!ok){
                int a, b, c = 1;
                if(l == r)a = 0, b = x[l];
                else{
                    a = x[l + 1] - x[l];
                    b = x[l];
                }
                printf("%lld %lld %lld\n", a, b, c);
            }
        }
    }
    return 0;
}