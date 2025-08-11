#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a[605];
bool vis[605];
ll num[605];
ll num_s[605];
bool is_s[605];

int main(){
    freopen("ruin.in", "r", stdin);
    freopen("ruin.out", "w", stdout);
    ll n;
    cin >> n;
    ll div = 1;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        num[i] = i - 1;
        is_s[a[i]] = true;
        div *= 2;
    }
    for (int i = n + 1; i <= 2 * n;i++){
        num[i] = i - 1;
    }
    ll anss = 0;
    do{
        for (int i = 1; i <= 2*n;i++){
            num_s[i] = num[i] / 2 + 1;
        }
        for (int i = 1; i <= 2*n;i++){
            for (int j = 1; j <= 2*n;j++){
                vis[j] = false;
            }
            for (int j = 2*n; j >= 1;j--){
                if(vis[num_s[j]] && num_s[j]!=0){
                    vis[num_s[j]] = true;
                    num_s[j]--;
                }else{
                    vis[num_s[j]] = true;
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= 2*n;i++){
            if((num_s[i] && !is_s[i]) || (!num_s[i] && is_s[i])){
                flag = false;
                break;
            }
        }
        anss += flag;
    } while (next_permutation(num + 1, num + 1 + 2*n));
    cout << anss / div;
    return 0;
}