#include <bits/stdc++.h>
using namespace std;

int n,sz[200010],fa[200010];
vector<int> e[200010],s[200010];
int tot;
int vis[200010];

void dfs(int x,int f)
{
    sz[x] = 1;
    fa[x] = f;
    s[x].push_back(x);
    for(int v:e[x])
    {
        if(v == f) continue;
        dfs(v,x);
        sz[x] += sz[v];
        for(int qwq:s[v]) s[x].push_back(qwq);
    }
}
void dfs1(int x,int now,int vs)
{
    sz[x] = 1;
    s[x].clear();
    s[x].push_back(x);
    for(int v:e[x])
    {
        if(v == fa[x] || v == now || vis[v] != vs) continue;
        dfs1(v,now,vs);
        sz[x] += sz[v];
        for(int qwq:s[v]) s[x].push_back(qwq);
    }
}
int sieve(int rt,vector<int> c)
{
    tot++;
    int asdf = tot;
    for(int i:c) vis[i] = asdf;
    if(c.size() <= 1) return 0;
    if(c.size() <= 3) return 1;
    int now=0,mn=INT_MAX;
    for(int x:c)
    {
        int nowmx = 0;
        for(int v:e[x])
        {
            if(vis[v] != asdf || v == fa[x]) continue;
            nowmx = max(nowmx,sz[v]);
        }
        if(x != rt) nowmx = max(nowmx,sz[rt] - sz[x]);
        if(nowmx < mn){now = x,mn = nowmx;}
    }
    int fans = INT_MAX;
    int ans = 0;
    vector<int> qaq;
    int themax = 0;
    for(int i:e[now]) 
    {
        if(i != fa[now] && vis[i] == asdf) 
        {
            int _ = sieve(i,s[i]);
            if(ans < _)
            {
                ans = _;
                themax = i;
            }
        }
    }
    dfs1(rt,now,asdf);
    if(rt != now) ans = max(ans,sieve(rt,s[rt]));
    fans = ans;
    for(int i=themax;i<=themax;i++)
    {
        for(int i:c) vis[i] = asdf;
        now = themax;
        if(vis[i] != asdf) continue;
        int ans = 0;
        for(int i:e[now]) 
        {
            if(i != fa[now] && vis[i] == asdf) 
            {
                ans = max(ans,sieve(i,s[i]));
            }
        }
        dfs1(rt,now,asdf);
        if(rt != now) ans = max(ans,sieve(rt,s[rt]));
        fans = min(fans,ans);
    }
    return fans+1;
}
int solve1(int n)
{
    int ans = 0;
    while(n > 1)
    {
        ans++;
        n--;
        n = (n>>1) + (n&1);
    }
    return ans+1;
}
void solve()
{
    cin >> n;
    vector<int> c;
    for(int i=1,u,v;i<n;i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        c.push_back(i);
    }
    if(n > 20) {cout << solve1(n) << "\n";return;}
    c.push_back(n);
    dfs(1,0);
    cout << sieve(1,c)+1 << "\n";
}

void init()
{
    for(int i=1;i<=n;i++) {e[i].clear();vis[i] = 0;s[i].clear();}
    tot = 0;  
}

int main()
{
    freopen("labyrinth.in","r",stdin);
    freopen("labyrinth.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // T = 1;
    while(T--)
    {
        solve();
        init();
    }
}