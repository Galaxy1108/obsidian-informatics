#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
signed main(){
    freopen("youup.in","r",stdin);
    freopen("youup.out","w",stdout);
    int num=0;
    cin >> num;
    int n,k;
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
    }
    if(k==0){
        cout << n << ' ';
        for(int i=2;i<=n;i++){
            cout << 0 << ' ';
        }
    }
    else if(num==4){
        int lst=n;
        cout << n << ' ';
        for(int i=2;i<=n;i++){
            if(i<=k+1){
                cout << ((lst*(n-i+1)%Mod)%Mod) << ' ';
                lst*=(n-i+1)%Mod;
                lst%=Mod;
            }
            else{
                cout << "0 ";
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(i<=k+1)cout << n-i+1 << " ";
            else cout << 0 << " ";
        }
    }
    return 0;
}