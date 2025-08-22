#include <cstdio>
#include <cstring>
#include <random>
#include <algorithm>
using namespace std;

const int MAXN=5010;
int a[MAXN][MAXN],n,seed;
bool e[MAXN];

struct number
{
    int love,id;
} nbr[MAXN][MAXN];

bool cmp(number x,number y)
{
    return x.love<y.love;
}

void gen(int n,int seed)
{
    mt19937 rng(seed);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            a[i][j]=j;
            swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}

void work(int x)
{
    for (int i=1;i<=n+1;i++)
        if (!e[nbr[x][i].id])
        {
            e[nbr[x][i].id]=1;
            return;
        }
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int cur,cnt;
    scanf("%d%d",&n,&seed);
    if (!seed)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n+1;j++)
                scanf("%d",&a[i][j]);
    }
    else
        gen(n,seed);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n+1;j++)
            nbr[i][j].id=j,nbr[i][j].love=a[i][j];
        sort(nbr[i]+1,nbr[i]+n+2,cmp);
    }
    for (int i=1;i<=n;i++)
    {
        cur=i,cnt=0;
        while (true)
        {
            work(cur);
            cur++,cnt++;
            if (cnt==n)
                break;
            if (cur==n+1)
                cur=1;
        }
        for (int i=1;i<=n+1;i++)
            if (!e[i])
            {
                printf("%d ",i);
                break;
            }
        memset(e,0,sizeof e);
    }
    return 0;
}