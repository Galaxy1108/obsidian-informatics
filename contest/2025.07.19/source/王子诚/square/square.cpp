#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int a[100005];
ll ns[100005];

int pri[100], tops;
int cnt_pri[100];
bool is_npri[100];
int nums[100][100005];
int b[100005];

#define mod 1000000007

void get_prim(){
    for (int i = 2; i <= 70;i++){
        if(is_npri[i]){
            continue;
        }
        pri[++tops] = i;
        cnt_pri[i] = tops;
        for (int k = 2; i * k <= 70;k++){
            is_npri[i * k] = true;
        }
    }
}

long long fast_pow(long long a,long long b){
    long long anss = 1;
    while(b){
        if(b&1){
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

ll inv(ll num){
    return fast_pow(num, mod - 2);
}

ll C(ll a,ll b){
    return (ns[a] * inv(ns[b] * ns[a - b] % mod) % mod);
}

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n;
    cin >> n;
    ns[0] = 1;
    for (int i = 1; i <= n;i++){
        ns[i] = ns[i - 1] * i;
    }
    get_prim();
    int cnts = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]==1 || ((int)sqrt(a[i]))*((int)(sqrt(a[i])))==a[i]){
            cnts++;
        }
        for (int j = 2; j <= a[i];j++){
            while(!(a[i]%j)){
                nums[cnt_pri[j]][i]++;
                nums[cnt_pri[j]][i] %= 2;
                a[i] /= j;
            }
        }
    }
    for (int i = 1; i <= tops;i++){
        for (int j = 1; j <= n;j++){
            b[i] += nums[i][j];
        }
    }
    long long anss = 1;
    for (int i = 1; i <= tops;i++){
        long long res = 1;
        for (int j = 0; 2 * j <= b[i];j++){
            res *= C(b[i], 2 * j);
            // cout << b[i] << ' ' << 2 * j << ' ' << C(b[i], 2 * j) << endl;
            res %= mod;
        }
        anss = (anss * res) % mod;
    }
    cout << (anss * fast_pow(2, cnts)) - 1 % mod;
    return 0;
}