#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n,a[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    bool sub2=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)sub2=false;
    }
    if(sub2){
        cout<<(n&1);
    }
    return 0;
}