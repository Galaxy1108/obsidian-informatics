#include <bits/stdc++.h>
using namespace std;
inline int ls(int x) {return x<<1;}
inline int rs(int x) {return x<<1 | 1;}
int a[11],t[10010],maxtot,len[11],x[10010],y[11],vis[10010];
char ans[801][1601];
void build(int p,int m,int l,int r)
{
    maxtot = max(maxtot,p);
    if(l==r)
    {
        len[m] = 2;
        t[p] = 2;
        if(l==1) x[p] = 1;
        else if(l&1)
        {
            x[p] = x[p-1] + 2;
        }
        else
        {
            x[p] = x[p-1] + 4;
        }
        return;
    }
    int mid = (l+r)>>1;
    build(ls(p),m+1,l,mid);
    build(rs(p),m+1,mid+1,r);
    len[m] = t[ls(p)] + 1;
    t[p] = t[ls(p)] + len[m];
    x[p] = (x[ls(p)] + x[rs(p)]) >> 1;
}
void build1(int p,int m,int l,int r)
{
    if(l==r)
    {
        ans[y[m]][x[p]] = 'o';
        return;
    }
    ans[y[m]][x[p]] = 'o';
    int mid = (l+r)>>1;
    if(!vis[ls(p)])
    {
        for(int i=1;i<=len[m+1];i++)
        {
            ans[y[m]+i][x[p]-i] = '/';
        }
        build1(ls(p),m+1,l,mid);
    }
    if(!vis[rs(p)])
    {
        for(int i=1;i<=len[m+1];i++)
        {
            ans[y[m]+i][x[p]+i] = '\\';
        }
        build1(rs(p),m+1,mid+1,r);
    }
    return;
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i] = (1<<(x-1)) + y - 1;
        vis[a[i]] = 1;
    }
    build(1,1,1,(1<<(n-1)));
    y[1] = 1;
    for(int i=2;i<=n;i++)
    {
        y[i] = y[i-1] + len[i];
    }
    memset(ans,' ',sizeof(ans));
    build1(1,1,1,(1<<(n-1)));
    int nxty = 1;
    for(int i=y[1];i<=y[n];i++)
    {
        if(i == y[nxty])
        {
            for(int j=1;j<=x[maxtot];j++)
            {
                cout << ans[i][j];
            }
            cout << endl;
            nxty++;
            continue;
        }
        for(int j=1;j<=x[maxtot]+1;j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}