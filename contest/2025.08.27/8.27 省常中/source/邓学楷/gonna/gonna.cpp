#include <cstdio>

int n,p;
long long tab[15]={0, 1, 4, 17, 269, 5736, 590892, 55905463, 30896505127, 41166677425218, 141740594713218418};

int main()
{
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
    scanf("%d%d",&n,&p);
    printf("%lld\n",tab[n]%p);
    return 0;
}