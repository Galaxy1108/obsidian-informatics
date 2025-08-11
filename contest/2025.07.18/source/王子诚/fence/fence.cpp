#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int h[100005], w[100005];
int n;

int solve_1(){
    int anss = 0;
    for (int i = 1; i <= n;i++){
        anss += ((1 + h[i]) * h[i]) / 2;
        int min_h = h[i];
        for (int j = i - 1; j >= 1;j--){
            min_h=min(min_h,h[j]);
            anss += ((1 + min_h) * min_h) / 2;
        }
    }
    return anss;
}

int solve_2(){
    long long anss = 0, sums = 0, sums_2 = 0;
    for (int i = 1; i <= n;i++){
        sums = (sums + w[i]) % mod;
        if(h[i]==2){
            sums_2 = (sums_2 + w[i]) % mod;
            continue;
        }
        anss = (anss + (1 + sums_2) * sums_2 % mod) % mod;
        sums_2 = 0;
    }
    anss = (anss + ((1 + sums) * sums / 2) % mod) % mod;
    anss = (anss + (1 + sums_2) * sums_2 % mod) % mod;
    return anss;
}

int main(){
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    cin >> n;
    bool bsolve_1 = true, bsolve_2 = true;
    for (int i = 1; i <= n;i++){
        cin >> h[i];
        if(h[i]>2){
            bsolve_2 = false;
        }
    }
    for (int i = 1; i <= n;i++){
        cin >> w[i];
        if(w[i]!=1){
            bsolve_1 = false;
        }
    }
    if(bsolve_1){
        cout << solve_1();
        return 0;
    }
    if(bsolve_2){
        cout << solve_2();
        return 0;
    }
    cout << "Do-something";
    return 0;
}