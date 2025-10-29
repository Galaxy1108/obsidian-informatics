#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 12;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
long long ans;
int n,a[MAXN],s[MAXN];
int spe[MAXN],cnt;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n = read();
    for (int i=1;i<=n;i++)
    {
        int x = read();
        a[x] ++;
    }
    n = 1e6;
    for (int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    for (int x=1;x<=n;x++)
    {
        cnt = 0;
        for (int l=x;l<=n;l+=x)
            if ((s[min(n,l+x-1)]-s[l-1])%2==1)
                spe[++cnt] = l;
        if (cnt==1)
        {
            if (spe[1]==x) ans += s[min(n,x+x-1)]-s[x-1];
        }
        if (cnt==2)
        {
            if (spe[1]==spe[2]-x) ans += s[min(n,spe[2]+x-1)]-s[spe[2]-1];
        }
    }
    printf("%lld",ans);
    return 0;
}