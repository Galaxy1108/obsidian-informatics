#include <bits/stdc++.h>
using namespace std;

int l[45], r[45];
int num[45];
int maxI, n, m;

int get_ans(int I){
    if(I==maxI+1){
        int ans = 0;
        for (int i = 1; i <= maxI;i++){
            ans ^= num[i];
        }
        bool flag = true;
        for (int i = 1; i <= m / 2;i++){
            if(m-i+1==i){
                continue;
            }
            int s = i - 1, rs = m - i;
            if(!!(ans&(1<<s)) != !!(ans&(1<<rs))){
                flag = false;
                break;
            }
        }
        return flag;
    }
    int sums = 0;
    for (int i = l[I]; i <= r[I];i++){
        num[I] = i;
        sums += get_ans(I + 1);
    }
    return sums;
}

int main(){
    freopen("far.in", "r", stdin);
    freopen("far.out", "w", stdout);
    // freopen("CON", "r", stdin);
    // freopen("CON", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= n;i++){
        maxI = i;
        cout << get_ans(1) << '\n';
    }
}