#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
using ll = long long;

struct mat{
    long long num[20][20];
    int n, m;
    mat(int _n,int _m){
        n = _n, m = _m;
        for (int i = 1; i <= _n;i++){
            for (int j = 1; j <= _m;j++){
                num[i][j] = 0;
            }
        }
    }
    friend mat operator*(mat a,mat b){
        mat anss(a.n, b.m);
        for (int i = 1; i <= a.n;i++){
            for (int j = 1; j <= b.m;j++){
                for (int k = 1; k <= a.m;k++){
                    anss.num[i][j] = (anss.num[i][j] + a.num[i][k] * b.num[k][j]) % mod;
                }
            }
        }
        return anss;
    }
    friend mat operator^(mat a,long long b){
        mat anss(a.n, a.m);
        for (int i = 1; i <= anss.n;i++){
            for (int j = 1; j <= anss.m;j++){
                anss.num[i][j] = (i == j);
            }
        }
        while(b){
            if(b&1){
                anss = (anss * a);
            }
            a = (a * a);
            b >>= 1;
        }
        return anss;
    }
};

int main(){
    freopen("sam.in", "r", stdin);
    freopen("sam.out", "w", stdout);
    ll k;
    cin >> k;
    mat A(10, 10), b(10, 1);
    for (int num = 1; num <= 10;num++){
        for (int last_num = 1; last_num <= 10;last_num++){
            if(abs(num-last_num)>2){
                continue;
            }
            A.num[num][last_num] = 1;
        }
        b.num[num][1] = 1;
    }
    A = (A ^ (k - 1));
    b = (A * b);
    ll anss = 0;
    for (int i = 2; i <= 10;i++){
        anss = (anss + b.num[i][1]) % mod;
    }
    cout << anss;
}
