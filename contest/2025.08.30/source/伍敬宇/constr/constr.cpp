#include <cstdio>
using namespace std;
int a[6],b[6],n;
int visa[6],visb[6];
void dfsb(int id)
{
    if (id>n)
    {
        for (int i=1;i<=n;i++)
            printf("%d %d ",a[i]*2-1,b[i]*2);
        printf("\n");
        return ;
    }
    for (int x=1;x<=5;x++)
    {
        if (visb[x]) continue ;
        visb[x] = 1;
        b[id] = x;
        dfsb(id+1);
        visb[x] = 0;
        b[id] = 0;
    }
}
void dfsa(int id)
{
    if (id>n)
    {
        dfsb(1);
        return ;
    }
    for (int x=1;x<=5;x++)
    {
        if (visa[x]) continue ;
        visa[x] = 1;
        a[id] = x;
        dfsa(id+1);
        visa[x] = 0;
        a[id] = 0;
    }
}
int main()
{
    freopen("constr.in","r",stdin);
    freopen("constr.out","w",stdout);
    scanf("%d",&n);
    n/=2;
    printf("14400\n");
    dfsa(1);
    return 0;
}