#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7,p=739130440;
int q[2500010],hd=1,tl;
long long a[2500010],dp[2500010];
long long ans,now;
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
long long qmi(int a,int b)
{
    long long t = a,r = 1;
    while(b)
    {
        if(b & 1)
        {
            r = (r*t) % mod;
        }
        t = (t*t) % mod;
        b >>= 1;
    }
    return r;
}
signed main()
{
    freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
    int n,k;
    n = Qread(),k = Qread();
    now = qmi(23,n-1);
    for(int i=1;i<=n;i++)
    {
        a[i] = Qread();
    }
    for(int i=1,qwq;i<=n;i++)
    {
        while(hd <= tl && a[q[tl]] < a[i]) tl--;
        q[++tl] = i;
        qwq = max(i-k,0);
        dp[i] = dp[qwq] + a[q[hd]];
        for(int j=hd+1;j<=tl;j++)
        {
            dp[i] = min(dp[max(q[j-1],0)] + a[q[j]],dp[i]);
        }
        ans = ((ans + (now*dp[i]) % mod) + mod)% mod;
        now = ((now * p) % mod + mod) % mod;
        if(i - q[hd] + 1 >= k) hd++;
    }
    printf("%lld",ans);
}
