#include <bits/stdc++.h>
#define LIM (1<<19|5)
#define tot 19
#define Mod 1000000007
using namespace std;
int Qread()
{
    int x=0;char ch=getchar();
    while(ch<='0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x;
}
int qpow(int a,int p)
{
    int ret=1;
    for(;p;p>>=1,a=1ll*a*a%Mod)
        if(p&1) ret=1ll*ret*a%Mod;
    return ret;
}
int prim[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n,num,p,s=1<<19,ans;
int f[LIM];
int chk(int a){return a>=Mod?a-Mod:a;}
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	
    n=Qread();
    for(int i=1;i<=n;i++)
    {
        num=Qread();p=0;
        for(int i=0;i<tot;i++)
        {
            p<<=1;
            while(num%prim[i]==0)
                p^=1,num/=prim[i];
        }
        f[p]++;
    }
    for(int i=1;i<s;i<<=1)
    for(int j=0;j<s;j+=(i<<1))
    for(int k=0;k<i;k++)
    {
        int x=f[j+k],y=f[j+i+k];
        f[j+k]=chk(x+y);
        f[j+i+k]=chk(x+Mod-y);
    }
    for(int i=0;i<=s;i++)
        ans+=(f[i]==n);
    ans=1ll*ans*qpow(2,n)%Mod*qpow(qpow(2,tot),Mod-2)%Mod;
    ans=chk(ans-1);
    printf("%d\n",ans);
    return 0;
}