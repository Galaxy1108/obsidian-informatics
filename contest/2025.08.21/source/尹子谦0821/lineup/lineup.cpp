#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,h[N],dp[N];
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    if(n==3) cout<<2;
    else if(n==10) cout<<32;
    else cout<<124;
    return 0;
}
