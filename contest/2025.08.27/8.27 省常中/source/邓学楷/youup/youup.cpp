#include <cstdio>

const int M=998244353;
long long pre[8010][8010],n;

void work()
{
	pre[0][0]=1;
	for (int i=1;i<=(n+1<=8005?n+1:8005);i++)
		for (int j=1;j<=i;j++)
			pre[i][j]=pre[i-1][j]+pre[i-1][j-1],pre[i][j]%=M;
}

long long getc(int x,int y)
{
    if (x<=8000)
        return pre[x+1][y+1];
    else
    {
        long long ans=1;
        for (int i=1;i<=y;i++)
            ans*=(x-i+1),ans%=M;
        for (int i=1;i<=y;i++)
            ans/=i,ans%=M;
        return ans%M;
    }
}

int main()
{
    freopen("youup.in","r",stdin);
    freopen("youup.out","w",stdout);
    long long _,x;
    scanf("%lld%lld%lld",&_,&n,&x);
    if (_==1)
    {
        printf("%lld ",n);
        for (int i=1;i<n;i++)
            printf("0 ");
    }
    else if (_==4)
    {
        if (x==0)
        {
            printf("%lld ",n);
            for (int i=1;i<n;i++)
                printf("0 ");
        }
        else if (x==1)
        {
            printf("%lld %lld ",n,n-1);
            for (int i=2;i<n;i++)
                printf("0 ");
        }
        else
        {
            work();
            for (int i=1;i<=n;i++)
                printf("%lld ",getc(n,i)%M);
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
            printf("%lld ",n);
    }
    return 0;
}