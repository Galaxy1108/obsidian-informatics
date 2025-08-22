#include <cstdio>
const int SIZE = 1<<21;
const int MAXN = 1e5 + 12;
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
int n,q;
int x[MAXN],ql[MAXN],qr[MAXN];
bool check2()
{
    if (n<=2) return 1;
    int flag = 1;
    for (int i=3;i<=n;i++)
        if (x[i]-x[i-1]!=x[2]-x[1]) flag = 0;
    if (flag) return 1;
    flag = 1;
    for (int i=1;i<=q;i++)
        if (ql[i]!=qr[i]) flag = 0;
    return flag;
}
void work2()
{
    int a = x[2] - x[1];
    for (int i=1;i<=q;i++)
    {
        if (ql[i]==qr[i]) printf("%d %d %d\n",0,x[ql[i]],1);
        else printf("%d %d %d\n",a,x[ql[i]],1);
    }
}
bool check(int l,int r,int a,int b,int c)
{
    //if (l==1&&r==5&&a==1&&b==4&&c==3) printf("ddd");
    for (int i=l,j=0;i<=r;i++,j++)
    {
        //if (l==1&&r==5&&a==1&&b==4&&c==3) printf("\n%lld %lld %d\n",(1ll*a*j+b)/c,1ll*x[i],i);
        if ((1ll*a*j+b)/c!=1ll*x[i])
            return 0;
    }
    return 1;
}
void solve(int l,int r)
{
    for (int c=1;c<=10;c++)
        for (int a=0;a<=10;a++)
            for (int b=0;b<=10;b++)
                if (check(l,r,a,b,c))
                {
                    printf("%d %d %d\n",a,b,c);
                    return ;
                }
}
void work1()
{
    //printf("d");
    for (int i=1;i<=q;i++) 
        solve(ql[i],qr[i]);
}
void work()
{
    n = read();
    for (int i=1;i<=n;i++) x[i] = read();
    q = read();
    for (int i=1;i<=q;i++) ql[i] = read(),qr[i] = read();
    //work1();
    if (check2()) work2();
    else work1();
}
int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int t = read();
    while (t--) work();
    return 0;
}