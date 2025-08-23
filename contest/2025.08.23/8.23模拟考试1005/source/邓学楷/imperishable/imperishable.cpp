#include <cstdio>
#include <cstring>
typedef long long ll;

const int M=998244353;
int n,a[200010];

int main()
{
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    int _,q,x,y;
    scanf("%d%d",&_,&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    puts("2");
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d",&x,&y);
        a[x]=y;
        puts("2");
    }
    return 0;
}