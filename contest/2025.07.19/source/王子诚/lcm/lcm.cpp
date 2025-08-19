#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
int n, k;
long long nums[100];

long long lcmm(long long a,long long b){
    return (a * b) / __gcd(a, b);
}

long long dfs(int s){
    if(s==k+1){
        int lcms = 1;
        for (int i = 1; i <= k;i++){
            lcms = lcmm(lcms, nums[i]);
        }
        return lcms;
    }
    long long anss = 1;
    for (int i = 1; i <= n;i++){
        nums[s] = i;
        anss *= dfs(s + 1);
        anss %= mod;
    }
    return anss;
}

int main(){
    freopen("lcm.in", "r", stdin);
    freopen("lcm.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        cout << dfs(1) << '\n';
    }
}