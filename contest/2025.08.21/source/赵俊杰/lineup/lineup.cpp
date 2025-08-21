#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,a[N];
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int t=0;
        for(int j=1;j<=n-i+1;j++)
            if(a[j]>=a[t])t=j;
        ans+=2*(n-i+1-t);
        while(t!=n-i+1)
        {
            int mn=n;
            for(int j=t+1;j<=n-i+1;j++)
                if(a[j]<a[mn])mn=j;
            swap(a[t],a[mn]);
            t=mn;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
