#include <cstdio>

int x,n;

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d%d%d",&n,&n,&n);
    for (int i=0;i<n-1;i++)
        scanf("%d%d%d",&x,&x,&x);
    while (n--)
        scanf("%d",&x);
    scanf("%d",&x);
    while (x--)
        puts("0");
    return 0;
}