#include <cstdio>

int n,m,q;
bool a1=1,a0=1;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    while (n--)
    {
        scanf("%d",&m);
        if (m%2==0)
            a1=0;
        else
            a0=0;
    }
    while (q--)
        puts((a1 || a0)?"0":"1");
    return 0;
}