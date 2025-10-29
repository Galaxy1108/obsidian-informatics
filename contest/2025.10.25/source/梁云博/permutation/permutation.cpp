#include <bits/stdc++.h>
#define N 305
#define P 1000000007
using namespace std;
int n;
int a[N<<1];
bool isallf1()
{
    for(int i=1;i<=n;i++)if(a[i]!=-1)return 0;
    return 1;
}

namespace solve1
{
    int ans=0;
    map<vector<int>,int>ma;
    int path[N<<1],vis[N<<1];
    void Mobius(int p)
    {
        if(p==n+1)
        {
            cerr<<1<<'\n';
            vector<int>b;
            b.resize(n/2+1);
            for(int i=1;i<=n/2;i++)b[i]=min(path[2*i-1],path[2*i]);
            if(!ma[b])ans++,ma[b]=1;
            return;
        }
        if(a[p]!=-1)path[p]=a[p],Mobius(p+1);
        else for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            vis[i]=1;
            path[p]=i;
            Mobius(p+1);
            vis[i]=0;
        }
    }
    void solve()
    {
        for(int i=1;i<=n;i++)if(a[i]!=-1)vis[i]=1;
        Mobius(1);
        cout<<ans<<"\n";
    }
}

namespace solve2
{
    void solve()
    {
        int jc=1;
        for(int i=1;i<=n;i++)
        {
            jc=jc*i%P;
        }cout<<jc;
    }
}

int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    n<<=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(isallf1())solve2::solve();
    else solve1::solve();
    return 0;
}