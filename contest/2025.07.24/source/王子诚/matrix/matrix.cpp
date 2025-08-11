#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool mat[2005][2005];
ll anss_i[2000005], anss_j[2000005], tops;

int main(){
     freopen("matrix.in", "r", stdin);
     freopen("matrix.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i <= n;i++){
        for (int j = i; j <= n;j++){
            mat[i][j] = true;
        }
    }
    for (int i = 0; i <= n;i++){
        for (int j = i + 2; j <= n;j++){
            if(mat[i][j]==1){
                anss_i[++tops] = i, anss_j[tops] = j;
            }
        }
    }
    cout << tops << '\n';
    for (int i = 1; i <= tops;i++){
        cout << anss_i[i] << ' ' << anss_j[i] << '\n';
    }
//cout<<"1\n0 2"; 
    return 0;
}
