#include <cstdio>
using namespace std;
int n;
long long x,y,sum,tsum;
void work()
{
    scanf("%d%lld%lld",&n,&x,&y);
    sum = tsum = 0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            sum += (n-i)*(j-1),tsum += i*j-1;
    long long t = (x+y-sum);
    if (t%2==1) return printf("NO\n"),void();
    if (t<0) return printf("NO\n"),void();
    if (t/2>tsum) return printf("NO\n"),void();
    printf("YES\n");
    int cnt = 0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            printf("%d ",++cnt);
        printf("\n");
    }
}
int main()
{
    freopen("matrixcascade.in","r",stdin);
    freopen("matrixcascade.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--) work();
    return 0;
}