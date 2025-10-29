#include <cstdio>
#include <cmath>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 1e6 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return (*iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10+ch-'0',ch = mget();
    return x;
}
int n,q;
int ans[MAXN][22];
void init()
{
    for (int m=2;m<=20;m++)
    {
        ans[1][m] = 1;
        for (int i=2;i<=n;i++)
        {
            int pre = i - ((i-1)/m+1);
            int id = pre + 1 - ans[pre][m];
            int x = (id-1)/(m-1),y = (id-1)%(m-1) + 1;
            ans[i][m] = x*m + 1 + y;
            //printf("%d %d %d\n",i,m,ans[i][m]);
        }
    }
}
int bas[MAXN<<1],a[MAXN],vis[22],sum;
int lg;
inline int lowbit(int x) {return x&(-x);}
void add(int id,int val)
{
    for (;id<=n*2;id+=lowbit(id))
        bas[id] += val;
}
int find(int lm)
{
    int id = 0;
    for (int k=lg;k>=0;k--)
    {
        //printf("%d\n",bas[8]);
        if (bas[id+(1<<k)]<lm)
        {
            lm -= bas[id+(1<<k)];
            id += (1<<k);
        }
        //printf("%d %d\n",id,lm);
    }
        
    return id+1;
}
int main()
{
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    n = read(),q = read();
    init();
    for (int i=1;i<=n;i++) a[i] = 1,add(i,1);
    sum = n;
    lg = log2(n);
    for (int i=1;i<=q;i++)
    {
        int tp=read(),m=read();
        if (tp==1)
        {
            if (vis[m]) continue ;
            vis[m] = 1;
            for (int i=1;i<=n;i+=m)
            {
                if (a[i]==0) continue ;
                a[i] = 0,sum --;
                add(i,-1);
            }
        }
        else if (tp==2)
        {
            for (int i=1;i<=sum;i+=m-1)
            {
                int id = find(i);
                a[id] = 0,sum--;
                add(id,-1);
            }
        }
        else
        {
            if (sum==0) printf("-1\n");
            else printf("%d\n",find(ans[sum][m]));
        }
    }
    return 0;
}