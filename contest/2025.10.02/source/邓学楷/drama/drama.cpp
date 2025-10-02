#include <cstdio>
#include <cctype>
#define i128 __int128
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define N 2000010

int n,h[N],minn,maxn;
i128 ans=-1;

inline void read(int& x)
{
    bool m=0;
    x=0;
    char ch=getchar();
    while (!isdigit(ch))
    {
        if (ch=='-') m=1;
        ch=getchar();
    }
    while (isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=(m?-1:1);
}

inline void write(i128 x)
{
    if (x>=10)
        write(x/10);
    putchar(x%10+'0');
}

int main()
{
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    read(n);
    for (int i=1;i<=n;i++)
        read(h[i]);
    for (int i=1;i<=n;i++)
    {   
        maxn=-1,minn=1e9+10;
        for (int j=i;j<=n;j++)
        {
            maxn=max(maxn,h[j]);
            minn=min(minn,h[j]);
            ans=max(ans,(i128)maxn*minn*(j-i+1));
        }
    }
    write(ans);
    return 0;
}
