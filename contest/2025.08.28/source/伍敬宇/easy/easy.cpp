#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 2e5 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline long long read()
{
    long long x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
int n,m;
long long a[MAXN];
int main()
{
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    n = read(),m = read();
    for (int i=1;i<=n;i++) a[i] = read();
    for (int i=1;i<=m;i++)
    {
        int op = read();
        long long v;
        int l,r;
        if (op==1)
        {
            v = read();
            for (int i=1;i<=n;i++) a[i] = min(a[i],v);
        }
        else if (op==2)
        {
            for (int i=1;i<=n;i++) a[i] += i;
        }
        else 
        {
            l = read(),r = read();
            long long ans = 0;
            for (int i=l;i<=r;i++) ans += a[i];
            printf("%lld\n",ans);
        }
    }
    return 0;
}