#include <bits/stdc++.h>
#define P 998244353
#define N 505
#define int long long
using namespace std;
int n,x;

namespace solve
{
    int jc[N],f[N][N];
    int qp(int a,int b)
    {
        int res=1;
        while(b)
        {
            if(b&1)res=res*a%P;
            a=a*a%P;
            b>>=1;
        }return res;
    }
    int c(int i,int j)
    {
        return (jc[j]*qp(jc[i],P-2)%P)*qp(jc[j-i],P-2)%P;
    }
    
    void solve()
    {
        jc[0]=1;
        for(int i=1;i<=500;i++)jc[i]=jc[i-1]*i%P;
        for(int j=1;j<=x;j++)f[1][j]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i;j<=x;j++)
            {
                // if(j<i)continue;
                for(int k=1;k<=i;k++)
                {
                    f[i][j]+=(f[k][j-i+1]*c(k,i)%P)*qp(i-1,i-k)%P;
                    f[i][j]%=P;
                }
            }
        }
        int ans=0;
        for(int j=1;j<=x;j++)ans=(ans+f[n][j])%P;
        cout<<(qp(x,n)-ans+P)%P<<"\n";
    }
}


signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>x;
    solve::solve();
    return 0;
}