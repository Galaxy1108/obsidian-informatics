#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 2000 + 12;
const int lmt = 10*10*10*10;
int n,a[MAXN],b[MAXN];
int f[lmt+12][10],g[lmt+12][10];
int sta[lmt+12],num[lmt+12],idx;
int ts1[lmt+12][10],ts2[lmt+12][10];
int c1[lmt+12][10],c2[lmt+12][10];
int cst;
inline bool check(int s)
{
    static int stk[6],top=0;
    top = 0;
    while (s)
    {
        stk[++top] = s%10;
        s = s/10;
    }
    for (int i=1;i<top;i++)
        if (stk[i+1]>stk[i])
            return 0;
    return 1;
}
inline int rm(int s,int x)
{
    static int stk[6],top=0;
    int res = 0;
    while (s)
    {
        stk[++top] = s%10;
        s = s/10;
    }
    while (top) 
    {
        if (stk[top]!=x) res = res*10 + stk[top];
        else cst ++;
        top--;
    }
    return res;
}
inline int ap(int s,int x)
{
    cst++;
    static int stk[6],top=0;
    int res = 0;
    int flag = 0;
    while (s)
    {
        stk[++top] = s%10;
        s = s/10;
    }
    while (top)
    {
        if (stk[top]>x&&!flag) flag = 1,res = res*10 + x;
        res = res*10 + stk[top];
        top--;
    }
    if (flag==0) res = res*10 + x,flag = 1;
    return res;
}
inline void upd(int&x,int y)
{
    if (x>y) x = y;
}
int main()
{
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",a+i,b+i);
    for (int i=0;i<lmt;i++)
    {
        if (check(i)==0) continue ;
        sta[++idx] = i;
        num[i] = idx; 
    }
    for (int s=1;s<=idx;s++)
    {
        for (int p=1;p<=9;p++)
        {
            cst = 0;
            ts1[s][p] = num[rm(sta[s],p)];
            c1[s][p] = cst;
            if (ap(sta[s],p)>=lmt) ts2[s][p] = -1;
            else
            {
                cst = 0;
                ts2[s][p] = num[ap(sta[s],p)];
                c2[s][p] = cst;
            } 
        }
    }
    memset(f,0x3f3f3f3f,sizeof(f));
    f[1][1] = 0;
    for (int i=1;i<=n;i++)
    {
        memset(g,0x3f3f3f3f,sizeof(g));
        for (int s=1;s<=idx;s++)
        {
            cst = 0;
            int t = ts1[s][a[i]];
            cst += c1[s][a[i]];
            cst += c2[t][b[i]];
            t = ts2[t][b[i]];
            if (t<0) continue ;
            for (int p=1;p<=9;p++)
                upd(g[t][a[i]],f[s][p]+abs(p-a[i])+cst);
        }
        for (int s=idx;s>=1;s--)
        {
            for (int q=1;q<=9;q++)
            {
                cst = 0;
                int t = ts1[s][q];
                cst = c1[s][q];
                if (t==s) continue ;
                for (int p=1;p<=9;p++)
                    upd(g[t][q],g[s][p]+abs(p-q)+cst);
            }
        }
        memcpy(f,g,sizeof(f));
    }
    int ans = 0x3f3f3f3f;
    for (int p=1;p<=9;p++)
        upd(ans,f[1][p]);
    printf("%d",ans);
    return 0;
}