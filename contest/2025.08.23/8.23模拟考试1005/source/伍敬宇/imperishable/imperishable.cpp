#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2e5 + 12;
const int SIZE = 1<<21;
const int mod = 998244353;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS == iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
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
int n,q,b[MAXN],len;
int pw[MAXN];
int num[MAXN];
int cnt[16][13],a[MAXN];
int cal(int k)
{
    int res = 0;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++)
            cnt[i][j] = 0;
    for (int i=1;i<=len;i++)
        cnt[num[i]][a[i]] ++;
    for (int i=1;i<=k;i++)
    {
        int cur = 1;
        for (int j=2;j<=n;j++)
            if (cnt[i][j]>cnt[i][cur]) cur = j;
        res += pw[cur];
    }
    return res;
}
int solve(int id,int k)
{
    if (id>len) return cal(k);
    int res = 1e9;
    for (int i=1;i<=k;i++)
    {
        num[id] = i;
        res = min(res,solve(id+1,k));
    }
    num[id] = k+1;
    res = min(res,solve(id+1,k+1));
    return res;
}
void mpush()
{
    len = 0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=b[i];j++)
            a[++len] = i; 
}
void work1()
{
    mpush();
    printf("%d\n",solve(1,0));
    for (int i=1;i<=q;i++)
    {
        int x = read(),y = read();
        b[x] = y;
        mpush();
        printf("%d\n",solve(1,0));
    }
}
int main()
{
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    int tp = read();
    n = read();
    for (int i=1;i<=n;i++) b[i] = read();
    q = read();
    pw[0] = 1;
    for (int i=1;i<=n;i++) pw[i] = pw[i-1]*2%mod;
    work1();
    //else work2();
    return 0;
}