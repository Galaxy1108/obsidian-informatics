#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int Qread()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x;
}
char get_ch()
{
    char ch=getchar();
    while(ch!='A'&&ch!='B') ch=getchar();
    return ch;
}
int n,k;
char S[2000010];
int t[MAXN],lm[MAXN],fl=1;
int cnt[MAXN];
long long sum[MAXN];
long long f[MAXN],rem;
int stk[MAXN];int top,rea;
int stkk[MAXN];int topp,reaa;
long long minn[MAXN];int minncnt[MAXN];
long long Y(int ind){return f[ind]+sum[ind];}
long long X(int ind){return ind;}
void solve(long long T)
{
    top=0,rea=1;
    topp=1,reaa=1,stkk[1]=0;
    for(int i=1,fl=0;i<=n;i++)
    {
        f[i]=1e18;
        while(reaa<=topp&&stkk[reaa]<lm[i]) reaa++;
        if(reaa<=topp)
        {
            f[i]=f[stkk[reaa]]+T;
            cnt[i]=cnt[stkk[reaa]]+1;
        }
        while(fl<lm[i]&&fl<i)
        {
            while(rea<top&&(__int128)(Y(fl)-Y(stk[top]))*(X(stk[top])-X(stk[top-1]))<(__int128)(Y(stk[top])-Y(stk[top-1]))*(X(fl)-X(stk[top]))) top--;
            stk[++top]=fl;
            fl++;
        }
        while(rea<top&&Y(stk[rea])-X(stk[rea])*i>Y(stk[rea+1])-X(stk[rea+1])*i) rea++;
        if(rea<=top)
        {
            if(f[i]>(rem=Y(stk[rea])-X(stk[rea])*i+1ll*min(lm[i],i)*i-sum[min(lm[i],i)]+T)||(f[i]==rem&&cnt[i]>cnt[stk[rea]]+1))
            {
                f[i]=rem;
                cnt[i]=cnt[stk[rea]]+1;
            }
        }
        while(reaa<=topp&&f[stkk[topp]]>f[i]) topp--;
        stkk[++topp]=i;
    }
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	
    n=Qread(),k=Qread();
    for(int i=1,lim=2*n;i<=lim;i++)
        S[i]=get_ch();
    for(int i=1;i<=2*n;i++)
    {
        if(S[i]=='A') lm[++t[fl]]=fl-1;
        else t[fl+1]=t[fl],fl++;
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+t[i];
    long long L=-1e12,R=1e12,mid,ans=0;
    while(L<=R)
    {
        mid=(L+R)>>1;
        solve(mid);
        if(cnt[n]<=k) R=mid-1,ans=f[n]-mid*k;
        else L=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}