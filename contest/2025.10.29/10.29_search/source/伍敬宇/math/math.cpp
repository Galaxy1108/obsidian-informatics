#include <cstdio>
#define int long long 
using namespace std;
int x[10000+12];
inline int gcd(int x,int y)
{
    int r;
    while (y)
    {
        r = x%y;
        x = y,y = r;
    }
    return x;
}
bool dfs(int n,int A,int B,int lb,int id)
{
    int d = gcd(A,B);
    A/=d,B/=d;
    if (n==1)
    {
        if (A!=1) return 0;
        x[id] = B;
        return 1;
    }
    int rb = (B*n+A-1)/A - 1;
    for (int i=lb;i<=rb;i++)
    {
        if (i*A-B<0) continue ;
        int nA = i*A - B,nB = i*B;
        x[id] = i;
        if (dfs(n-1,nA,nB,i+1,id+1))
            return 1;
        x[id] = 0;
    }
    return 0;
}
signed main()
{
    int A,B;
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    scanf("%lld%lld",&A,&B);
    for (int n=1;;n++)
        if (dfs(n,A,B,2,1))
        {
            printf("%lld\n",n);
            for (int i=1;i<=n;i++)
                printf("%lld ",x[i]);
            return 0;
        }
    return 0;
}