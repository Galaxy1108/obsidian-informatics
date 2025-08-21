#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=2505;
int n,a[N],vis[N];
vector<int>e[N];
il void init()
{
    for(int i=2;i<=n+1;i++){
        for(int j=2;j<=n+1;j++)
        {
            if(__gcd(i,j)==1&&i!=j)
            {
                e[i].push_back(j);
            }
        }
    }
}vector<int>now;
il int solve()
{
    for(int i=1;i<=n;i++)vis[i]=0,a[i]=i+1;
    vis[n+1]=0;
    for(int i=1;i<=3;i++)random_shuffle(a+1,a+n+1);
    vis[a[1]]=1,vis[a[2]]=1;
    for(int i=3,x;i<=n;i++)
    {
        now.clear();
        // cout<<a[i-2]<<':';
        for(int j=0;j<e[a[i-2]].size();j++)
        {
            int k=e[a[i-2]][j];
            if(!vis[k])now.push_back(k);
            // if(!vis[k])cout<<k<<' ';
        }
        // cout<<'\n';
        if(now.size()==0)return 0;
        x=now.size();
        a[i]=now[rand()%x];
        vis[a[i]]=1;
    }
    return 1;
}
int main()
{
    srand(time(0));
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    cin>>n;n--;
    a[0]=1,a[n+1]=1;
    int flag=0;init();
    // cout<<solve();
    for(int i=1,e=50000000/n/n;i<=e;i++)if(solve()){flag=1;break;}
    for(int i=0;i<=n+1;i++)cout<<a[i]<<' ';
    cout<<'\n';
    for(int i=0;i<=n;i++)cout<<a[i]*a[i+1]<<' ';
    cout<<'\n';
    for(int i=1;i<n;i++)cout<<i<<' '<<i+1<<'\n';
    return 0;
}