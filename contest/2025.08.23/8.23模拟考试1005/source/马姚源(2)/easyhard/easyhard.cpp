#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p;
int qpow(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1)res*=a;
        res%=p;
        a*=a;
        a%=p;
        b>>=1;
    }
    return res;
}
signed main(){
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    cin >> n >> m >> p;
    if(n<=m)
    cout << qpow(2,n+m,p);
    else cout << qpow(2,m*2,p);
    return 0;
}
