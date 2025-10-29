#include <bits/stdc++.h>
#define P 998244353
#define N 505
#define int long long
using namespace std;
int n,x;

namespace solve
{
    int jc[N],f[N][N],c[N][N];
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
    
    void solve()
    {
        jc[0]=1;
		for(int i=0;i<=n;i++)c[i][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
        for(int j=1;j<=x;j++)f[1][j]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i;j<=x;j++)
            {
                for(int k=1;k<=i;k++)
                {
                    f[i][j]+=(f[k][j-i+1]*c[i][k]%P)*qp(i-1,i-k)%P;
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
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>x;
    solve::solve();
    return 0;
}
