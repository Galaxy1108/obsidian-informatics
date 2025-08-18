#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 2000 + 12;
int n,a[MAXN],b[MAXN];
int f[MAXN][3],ans;
inline void upd(int&x,int y)
{
    if (x<y) x = y;
}
int main()
{
    freopen("base.in","r",stdin);
    freopen("base.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    for (int i=1;i<=n;i++) scanf("%d",b+i);
    ans = -1e9;
    memset(f,0xc0c0c0c0,sizeof(f));
    for (int i=1;i<=n;i++)
        upd(f[i][0],max(f[i-1][0],0)+a[i]+b[i]),
        upd(f[i][1],max(f[i-1][0],f[i-1][1])+b[i]),
        upd(f[i][2],max(f[i-1][2],f[i-1][1])+a[i]+b[i]),
        upd(ans,f[i][2]);
    printf("%d",ans);
    return 0;
}