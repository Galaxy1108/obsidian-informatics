#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 12;
const int SIZE = 1<<21;
const double EPS = 1e-7;
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
int n;
long long x[MAXN],p[MAXN],c[MAXN],s[MAXN],t[MAXN];
long long f[MAXN],ans=2e18;
int q[MAXN],l=1,r=1;
bool tubao(int i,int j,int k)
{
    double b1 = f[i] + t[i],k1 = s[i];
    double b2 = f[j] + t[j],k2 = s[j];
    double b3 = f[k] + t[k],k3 = s[k];
    double x = (b2-b1)/(k2-k1);
    double y = b1 - x*k1;
    return b3 - k3*x > y + EPS;
}
int main()
{
    freopen("storage.in","r",stdin);
    freopen("storage.out","w",stdout);
    n = read();
    for (int i=1;i<=n;i++)
    {
        x[i] = read(),p[i] = read(),c[i] = read();
        s[i] = s[i-1] + p[i],t[i] = t[i-1] + p[i]*x[i];
    }
    for (int i=1;i<=n;i++)
    {
        while (r-l>=1&&f[q[l]]+t[q[l]]-s[q[l]]*x[i]>=f[q[l+1]]+t[q[l+1]]-s[q[l+1]]*x[i]) l++;
        f[i] = f[q[l]]+t[q[l]]-s[q[l]]*x[i] + c[i] - t[i] + s[i]*x[i];
        while (r-l>=1&&!tubao(q[r-1],q[r],i)) r--;
        q[++r] = i;
    }
    printf("%lld",f[n]);
    return 0;
}