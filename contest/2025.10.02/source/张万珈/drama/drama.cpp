#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[2000010],lmn[2000010],rmn[2000010],mx[2000010];
int stk[2000010],top;
int read()
{
    int ret=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){ret = (ret<<3) + (ret<<1) + (c-'0');c=getchar();}
    return ret;
}
void init()
{
    stk[++top] = 1;
    for(int i=2;i<=n;i++)
    {
        mx[i] = max(mx[i],a[stk[top]]);
        while(top && a[stk[top]] > a[i]) 
        {
            mx[i] = max(mx[i],mx[stk[top]]);
            top--;
        }
        lmn[i] = stk[top];
        stk[++top] = i; 
    }
    top = 0;
    stk[0] = n+1;
    stk[++top] = n;
    for(int i=n-1;i>=1;i--)
    {
        mx[i] = max(mx[i],a[stk[top]]);
        while(top && a[stk[top]] > a[i]) 
        {
            mx[i] = max(mx[i],mx[stk[top]]);
            top--;
        }
        rmn[i] = stk[top];
        stk[++top] = i;
    }
}
int main()
{
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++)
    {
        a[i] = read();
        mx[i] = a[i];
    }
    init();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,1LL*(rmn[i]-lmn[i]-1)*(mx[i])*a[i]);
    }
    printf("%lld",ans);
}