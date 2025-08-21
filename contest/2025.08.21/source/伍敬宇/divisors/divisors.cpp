#include <cstdio>
using namespace std;
const int MAXN = 2500 + 12;
int n;
int a[MAXN];
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    scanf("%d",&n);
    int cur = 2;
    for (int i=1;i<n;i+=2)
    {
        a[i] = cur;
        cur++;
    }
    cur = n;
    for (int i=2;i<n;i+=2)
    {
        a[i] = cur;
        cur--;
    }
    a[0] = a[n] = 1;
    for (int i=1;i<=n;i++) printf("%d ",a[i-1]*a[i]);
    printf("\n");
    for (int i=1;i<n;i++)
        printf("%d %d\n",i,i+1);
    return 0;
}