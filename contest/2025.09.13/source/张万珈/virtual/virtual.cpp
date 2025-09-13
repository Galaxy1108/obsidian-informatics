#include <bits/stdc++.h>
using namespace std;

int id[4000010],tot,fa[4000010],sz[4000010];
int n,lk,rk;
bool vis[4000010];
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    freopen("virtual.in","r",stdin);
    freopen("virtual.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> lk >> rk;
    string s;
    cin >> s;
    tot = 1;
    for(int i=1;i<=n;i++)
    {
        id[i] = tot;
        if(s[i-1] == 'a') {id[i] = ++tot;tot++;}
        sz[id[i]]++;
    }
    for(int i=1;i<=tot;i++)
    {
        fa[i] = i;
    }
    for(int i=2;i<=tot;i+=2)
    {
        if(!vis[i-2])
        for(int j=lk*2-2;j<rk*2;j++) 
        {
            if(i-j >= 1 && sz[i-j])
            {
                int u=find(i),v = find(i-j);
                if(u != v)
                {
                    fa[u] = v;
                }
            }
            if(i+j <= tot && sz[i+j])
            {
                int u=find(i),v = find(i+j);
                if(u!=v)
                {
                    fa[u] = v;
                }
            }
        }
        else
        {
            for(int j=lk*2-2;j<lk*2;j++) 
            {
                if(i-j >= 1 && sz[i-j])
                {
                    int u=find(i),v = find(i-j);
                    if(u != v)
                    {
                        fa[u] = v;
                    }
                }
                // if(i+j <= tot && sz[i+j])
                // {
                //     int u=find(i),v = find(i+j);
                //     if(u!=v)
                //     {
                //         fa[u] = v;
                //     }
                // }
            }
            for(int j=rk*2-2;j<rk*2;j++) 
            {
                // if(i-j >= 1 && sz[i-j])
                // {
                //     int u=find(i),v = find(i-j);
                //     if(u != v)
                //     {
                //         fa[u] = v;
                //     }
                // }
                if(i+j <= tot && sz[i+j])
                {
                    int u=find(i),v = find(i+j);
                    if(u!=v)
                    {
                        fa[u] = v;
                    }
                }
            }
        }
        vis[i] = 1;
    }
    int q;
    cin >> q;
    for(int i=1,x,y;i<=q;i++)
    {
        cin >> x >> y;
        if(find(id[x]) == find(id[y]))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}