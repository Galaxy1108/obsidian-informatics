#include <bits/stdc++.h>
#define N 205
#define int long long
using namespace std;
int n,P;

namespace bl
{
    struct TA
    {
        int c[N<<1];
        void clear(int lim){for(int i=1;i<=lim;i++)c[i]=0;}
        int lb(int x){return x&(-x);}
        void update(int x,int lim,int k)
        {
            while(x<=lim)
                c[x]+=k,x+=lb(x);
        }
        int query(int x)
        {
            int res=0;
            while(x)
                res+=c[x],x-=lb(x);
            return res;
        }
    }a,b;//a为求某排列的临时的，b为存结果计算的,因为存在0个逆序对，所以对b整体+1
    int pl[N];
    void solve()
    {
        int ans=0;
        for(int i=1;i<=n;i++)pl[i]=n-i+1;
        do
        {
            a.clear(n);
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                // cout<<pl[i]<<" ";
                sum=sum+a.query(n)-a.query(pl[i]);
                a.update(pl[i],n,1);
            }
            // cout<<"\n";
            // sum%=P;
            sum++;
            if(sum!=1)ans=(ans+b.query(sum-1))%P;
            b.update(sum,n*n+1,1);
        }while(prev_permutation(pl+1,pl+1+n));
        cout<<ans<<"\n";
    }
}


signed main()
{
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>P;
    bl::solve();
    return 0;
}