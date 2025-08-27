#include <cstdio>
using namespace std;
long long dfs(long long&n,long long x,long long y,long long s,long long t,long long a,long long b,int fst=0)
{
    // if (n/a<=10&&n/b<=10)
    // {
    //     while (1)
    //     {
    //         if (s<t)
    //         {
    //             if (n>=b) n-=b,s+=y;
    //             else return s;
    //         }
    //         else 
    //         {
    //             if (n>=a) n-=a,s-=x;
    //             else return s;
    //         }
    //     }
    // }
    if (y==0)
    {
        if (s<t) 
        {
            n %= b;
            return s;
        }
        long long cur = (s - t + 1 + x - 1)/x;
        if (cur<=n/a)
        {
            n -= cur*a;
            s -= cur*x;
            n = n%b;
            return s;
        }
        else 
        {
            s -= x*(n/a);
            n = n%a;
            return s;
        }
    }
    if (x==0)
    {
        if (s>=t) 
        {
            n %= a;
            return s;
        }
        long long cur = (t - s + y - 1)/y;
        if (cur<=n/b)
        {
            n -= cur*b;
            s += cur*y;
            n = n%a;
            return s;
        }
        else 
        {
            s += (n/b)*y;
            n = n%b;
            return s;
        }
    }
    if (y<=x)
    {
        long long q = x/y;
        long long nt = t - q*y;
        long long cur;
        if (s>=t)
        {
            cur = (s - t + 1 + x - 1)/x;
            if (cur<=n/a)
            {
                n -= cur*a;
                s -= cur*x;
            }
            else 
            {
                s -= x*(n/a);
                n = n%a;
                return s;
            }
        }
        if (s<t)
        {
            cur = (t - s + y - 1)/y;
            if (cur<=n/b)
            {
                n -= cur*b;
                s += cur*y;
            }
            else 
            {
                s += (n/b)*y;
                n = n%b;
                return s;
            }
        }
        if (n<a) return s;
        n -= a,s -= x;
        s = dfs(n,x%y,y,s,nt,a+b*q,b,(fst==1)?2:0);
        if (s<t)
        {
            cur = (t - s + y - 1)/y;
            if (cur<=n/b)
            {
                n -= cur*b;
                s += cur*y;
            }
            else 
            {
                s += (n/b)*y;
                n = n%b;
                return s;
            }
        }
        if (n<a) return s;
        n -= a,s -= x;
        s += (n/b)*y;
        n = n%b;
        return s;
    }
    else
    {
        long long q = y/x;
        long long nt = t + q*x;
        long long cur;
        if (s<t)
        {
            cur = (t - s + y - 1)/y;
            if (cur<=n/b)
            {
                n -= cur*b;
                s += cur*y;
            }
            else 
            {
                s += (n/b)*y;
                n = n%b;
                return s;
            }
        }
        if (s>=t)
        {
            cur = (s - t + 1 + x - 1)/x;
            if (cur<=n/a)
            {
                n -= cur*a;
                s -= cur*x;
            }
            else 
            {
                s -= x*(n/a);
                n = n%a;
                return s;
            }
        }
        if (n<b) return s;
        n -= b,s += y;
        s = dfs(n,x,y%x,s,nt,a,b+a*q,(fst==2)?3:0);
        if (s>=t)
        {
            cur = (s - t + 1 + x - 1)/x;
            if (cur<=n/a)
            {
                n -= cur*a;
                s -= cur*x;
            }
            else 
            {
                s -= x*(n/a);
                n = n%a;
                return s;
            }
        }
        if (n<b) return s;
        n -= b,s += x;
        s -= (n/a)*x;
        n = n%a;
        return s;
    }
}
int main()
{
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long n,x,y,s,t;
        scanf("%lld%lld%lld%lld%lld",&n,&s,&t,&x,&y);
        printf("%lld\n",dfs(n,x,y,s,t,1,1,1));
    }
    return 0;
}