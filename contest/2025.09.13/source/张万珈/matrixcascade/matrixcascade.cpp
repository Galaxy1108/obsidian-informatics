#include <bits/stdc++.h>
using namespace std;

int a[310][310];
long long n,x,y;
int tot,qwq[90010],qaq[90010];
bool fl = 0,vis[101];
bool check()
{
    tot = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            qwq[++tot] = a[i][j];
            qaq[tot] = a[j][i];
        }
    }
    int cntx=0,cnty=0;
    for(int i=1;i<=n*n;i++)
    {
        for(int j=i+1;j<=n*n;j++)
        {
            if(qwq[j] < qwq[i])cntx++;
            if(qaq[j] < qaq[i])cnty++;
        }
    }
    return cntx == x && cnty == y;
}
void dfs(int nx,int ny)
{
    if(nx > n)
    {
        if(check())
        {
            fl = 1;
            return;
        }
    }
    if(fl) return;
    for(int i=1;i<=n*n;i++)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        a[nx][ny] = i;
        dfs(nx+(ny/n),(ny%n) + 1);
        if(fl) return;
        vis[i] = 0;
        a[nx][ny] = 0;
    }
}

int main()
{
    freopen("matrixcascade.in","r",stdin);
    freopen("matrixcascade.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        
        cin >> n >> x >> y;
        if(x == 0 || y == 0)
        {
            if(x==0)
            {
                if(y != (n*n*(n-1)*(n-1)/4))
                {
                    cout << "NO\n";
                    continue;
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        a[i][j] = j+(i-1)*n;
                    }
                }
            }
            else if(y == 0)
            {
                if(x != (n*n*(n-1)*(n-1)/4))
                {
                    cout << "NO\n";
                    continue;
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        a[j][i] = j+(i-1)*n;
                    }
                }
            }
            cout << "YES\n";
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }
        else if(n <= 3)
        {
            fl = 0;
            dfs(1,1);
            if(fl)
            {
                cout << "YES\n";
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        cout << a[i][j] << ' ';
                    }
                    cout << endl;
                }
            }
            else cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    cout << (i-1)*n+j << ' ';
                }
                cout << endl;
            }
        }
    }
}