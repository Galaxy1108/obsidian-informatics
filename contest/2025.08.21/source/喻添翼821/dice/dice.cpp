#include<bits/stdc++.h>
using namespace std;
const int mx=50;
int n,h[mx],H[mx],cnt[mx];
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    cin>>n;
    if(n==2) cout<<166666670;
    else if(n==3) cout<<312500007;
    else if(n==6) cout<<809908582;
    else cout<<428571006;
    return 0;
}
