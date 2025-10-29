#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

int n;
int a[N];

namespace solve
{
    int f[N][5];
    void solve()
    {
        memset(f,63,sizeof(f));
        f[0][1]=f[0][2]=f[0][3]=f[0][4]=f[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            f[i][0]=f[i-1][0]+a[i];
            f[i][1]=min(f[i-1][0],f[i-1][1])+(a[i]&1)+2*(a[i]==0);
            f[i][2]=min({f[i-1][0],f[i-1][1],f[i-1][2]})+!(a[i]&1);
            f[i][3]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3]})+(a[i]&1)+2*(a[i]==0);
            f[i][4]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3],f[i-1][4]})+a[i];
        }
        cout<<min({f[n][0],f[n][1],f[n][2],f[n][3],f[n][4]})<<"\n";
    }
}

namespace O1
{
    int f[5];
    void solve()
    {
        for(int i=1;i<=n;i++) 
        {
            f[4]=min({f[0],f[1],f[2],f[3],f[4]})+a[i];
            f[3]=min({f[0],f[1],f[2],f[3]})+(a[i]&1)+2*(a[i]==0);
            f[2]=min({f[0],f[1],f[2]})+!(a[i]&1);
            f[1]=min({f[0],f[1]})+(a[i]&1)+2*(a[i]==0);
            f[0]=f[0]+a[i];
        }
        cout<<min({f[0],f[1],f[2],f[3],f[4]})<<"\n";
    }
}



signed main()
{
    // freopen("walk.in","r",stdin);
    // freopen("walk.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    O1::solve();
    return 0;
}