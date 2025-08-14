#include <cstdio>
typedef __int128 i128;

int n,p;
i128 pre[110][110],f[110],g[110],ans;

void write(i128 x)
{
    if (x<0)
    {
        putchar('-');
        x=-x;
    }
	if (x>=10)
	{
		write(x/10);
		putchar(x%10+'0');
	}
	else
		putchar(x+'0');
}

i128 gcd(i128 a,i128 b)
{
    return b?gcd(b,a%b):a;
}

i128 lcm(i128 a,i128 b)
{
    return a*b/gcd(a,b);
}

void calc()
{
    pre[0][1]=1;
    g[0]=1;
    for (int i=1;i<=100;i++)
    {
        for (int j=1;j<=i+1;j++)
        {
            pre[i][j]=pre[i-1][j]+pre[i-1][j-1];
            if (j%2==0)
                f[i]+=pre[i][j]*(1<<(j/2-1));
        }
        g[i]=lcm(f[i],g[i-1]);
    }
}

int main()
{
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
    int T;
    scanf("%d",&T);
    calc();
    while (T--)
    {
        scanf("%d%d",&n,&p);
        for (int i=1;i<=n;i++)
            ans+=i*g[i]%p,ans%=p;
        write(ans);
        putchar('\n');
        ans=0;
    }
    return 0;
}