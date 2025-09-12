#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#define abs(x) ((x)>=0?(x):(-(x)))

int n,in[200010];
std::vector<int> vec[200010];

int read()
{
    int x=0;
    char ch=getchar();
    while (!isdigit(ch))
        ch=getchar();
    while (isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

void write(int x)
{
    if (x>=10)
        write(x/10);
    putchar(x%10+'0');
}

void dfs(int u,int f)
{
    for (int v:vec[u])
        dfs(v,u);
}

int main()
{
    freopen("labyrinth.in","r",stdin);
    freopen("labyrinth.out","w",stdout);
    int T,u,v;
    bool chain;
    T=read();
    while (T--)
    {
        chain=1;
        for (int i=1;i<=n;i++)
            vec[i].clear(),in[i]=0;
        n=read();
        for (int i=0;i<n-1;i++)
        {
            u=read(),v=read();
            vec[u].push_back(v);
            vec[v].push_back(u);
            in[u]++,in[v]++;
        }
        for (int i=1;i<=n;i++)
            if (in[i]>2)
            {
                chain=0;
                break;
            }
        if (chain)
        {
            write((int)ceil(log2(n)));
            putchar('\n');
            continue;
        }
        dfs(1,0);
    }
    return 0;
}
