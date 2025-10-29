#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
int n;
int a[mx];
void sub3()
{
    if(n%2==0) cout<<0;
    else cout<<n;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    return 0;
    
}
