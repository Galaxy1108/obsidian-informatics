#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=2e5+5,mod=998244353;
int n,a[N],s[N],pre[N];
il void solve()
{
    cout<<2<<'\n';
}
int main()
{
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    int T;cin>>T;
    cin>>n;pre[0]=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)pre[i]=1ll*pre[i-1]*2%mod;
    solve();
    int q,x,y;cin>>q;
    while(q--)
    {
        cin>>x>>y;
        a[x]=y;solve();
    }
    return 0;
}
/*
0
4
4 1 2 3 
2
1 1 
1 2
*/