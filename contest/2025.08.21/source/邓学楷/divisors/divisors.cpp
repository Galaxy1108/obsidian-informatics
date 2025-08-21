#include <cstdio>

int n;

int gcd(int p,int q)
{
	return q?gcd(q,p%q):p;
}

int lcm(int p,int q)
{
    return p*q/gcd(p,q);
}

int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    scanf("%d",&n);
    int l=1;
    for (int i=1;i<=n;i++)
        l=lcm(l,i);
    for (int i=1;i<=n;i++)
        printf("%d ",i==1?l:i);
    putchar('\n');
    for (int i=2;i<=n;i++)
        printf("1 %d\n",i);
    return 0;
}
