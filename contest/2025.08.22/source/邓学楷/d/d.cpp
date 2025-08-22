#include <cstdio>

int n,x[100010],l,r;

bool check(int a,int b,int c)
{
    for (int i=l;i<=r;i++)
        if (x[i]!=((a*(i-l)+b)/c))
            return 0;
    return 1;
}

int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int T,q;
    bool f;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",x+i);
        scanf("%d",&q);
        while (q--)
        {
            scanf("%d%d",&l,&r);
            f=0;
            for (int c=1;c<=100;c++)
            {
                for (int a=0;a<=100;a++)
                {
                    for (int b=0;b<=100;b++)
                        if (check(a,b,c))
                        {
                            printf("%d %d %d\n",a,b,c);
                            f=1;
                            break;
                        }
                    if (f)
                        break;
                }
                if (f)
                    break;
            }
        }
    }
    return 0;
}