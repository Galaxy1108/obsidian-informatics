#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

const int N=10000010;
int n;
ull s1,s2,t[N],ans;

ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}

void get_query(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}

void add(int x,ull k)
{
    int i=0;
    while (x<=n)
    {
        t[x]+=k*(++i);
        x+=(x & -x);
    }
}

ull query(int x)
{
    ull sum=0;
    while (x)
    {
        sum+=t[x];
        x-=(x & -x);
    }
    return sum;
}

int Q;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    int op;
    ull x,y;
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for (int i=1;i<=Q;i++)
    {
        get_query(op, x, y);
        if (op==1)
            add(x,y);
        else if (op==2)
            ans^=i*(query(y)-query(x-1));
    }
    printf("%llu\n",ans);
    return 0;
}
