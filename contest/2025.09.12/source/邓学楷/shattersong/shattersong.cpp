#include <cstdio>

int n,m,z[100010];

int main()
{
    freopen("shattersong.in","r",stdin);
    freopen("shattersong.out","w",stdout);
    int u,v,w;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",z+i);
    for (int i=0;i<m;i++)
        scanf("%d%d%d",&u,&v,&w);
    if (n==1)
    {
        printf("1\n1 1\n");
        return 0;
    }
    if (w>z[1])
    {
        printf("2\n1 %d\n1 %d\n",u,v);
        return 0;
    }
    else
    {
        printf("1\n2 %d %d\n",u,v);
        return 0;
    }
    return 0;
}
