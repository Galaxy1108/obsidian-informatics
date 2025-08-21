#include<bits/stdc++.h>
using namespace std;
const int mx=50;
int n,h[mx],H[mx],cnt[mx],p[mx],ans;
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i],H[i]=h[i];
    sort(H+1,H+1+n);
    for(int i=1;i<=n;i++)
    {
        h[i]=lower_bound(H+1,H+1+n,h[i])-H;
        cnt[h[i]]++;
        h[i]+=cnt[h[i]]-1;
        p[i]=i;
    }
    ans=0;
    for(int i=1;i<=n;i++) ans+=abs(h[i]-p[i]);
    cout<<ans;
    return 0;
}
