#include <cstdio>
using namespace std;
const int MAXN = 3e3 + 12;
__int128 pre;
int p;
int n,m;
inline void upd(int&x,int y)
{
    x += y;
    if (x>=p) x -= p;
    else if (x<0) x += p;
}
long long mod(long long x)
{
    long long y = (x*pre)>>64;
    return (x - y*p);
}
int S[MAXN<<2],f[MAXN<<1],ans;
int C[MAXN<<1][MAXN<<1];
int main()
{
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    pre = 1;
    pre<<=64;
    pre = pre/p;
    for (int i=0;i<=2*m;i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j=1;j<i;j++)
        {
            C[i][j] = C[i-1][j-1];
            upd(C[i][j],C[i-1][j]);
        }
    }
    S[0] = 1;
    for (int i=1;i<=2*m;i++) 
        S[i] = (S[i-1] + C[2*m][i])%p;
    for (int i=2*m+1;i<=12006;i++)
        S[i] = S[i-1];
    //printf("%d\n",C[4][2]);
    for (int len=1;len<=2*n;len++)
    {
        for (int i=0;i<=len;i++)
        {
            if (i%2==1) continue ;
            int l = (2*m-i+1)/2,r = (2*m + len - i)/2;
            if (l==0) upd(f[len],S[r]);
            else upd(f[len],S[r]-S[l-1]);
            //if(len==2&&i==1) printf("%d %d %d\n",l,r,f[len]);
            l = (2*m+2+i+1)/2,r = (2*m+len+2+i)/2;
            upd(f[len],S[l-1]-S[r]);
            //if(len==2&&i==1) printf("%d\n",f[len]);
            l = (2*m+2+len-i+1)/2,r = (2*m+len+2+len-i)/2;
            upd(f[len],S[l-1]-S[r]);
            //if(len==2&&i==1) printf("%d\n",f[len]);
            l = (2*m+len+2+2+i+1)/2,r = (2*m+2*len+2+2+i)/2;
            upd(f[len],S[r]-S[l-1]);
            //if(len==2&&i==1) printf("%d\n",f[len]);
        }
        for (int i=1;i<len;i++)
        {
            upd(f[len],-mod(1ll*f[i]*((len-i)/2+1)));
            //else upd(f[len],-1ll*f[i]*(len-i+1)%p);
        }
        //printf("%d ",f[len]);
        upd(ans,f[len]);
    }
    printf("%d",ans);
    return 0;
}