#include <bits/stdc++.h>
using namespace std;
vector<int> e1[120010],s[120010],t[120010],e[120010];
int n,m;
int fa[120010],dfn[120010],tot,dep[120010],id[120010],st[120010][20],lg[120010],in[120010],s1[120010],t1[120010];
void dfs(int now,int f)
{
    fa[now] = f;
    dfn[now] = ++tot;
    dep[now] = dep[fa[now]] + 1;
    id[tot] = now;
    for(int v:e1[now])
    {
        if(v!=f)
        {
            dfs(v,now);
        }
    }
}
void build()
{
    for(int i=1;i<=n;i++)
    {
        st[i][0] = fa[i];
    }
    queue<int> q;
    q.push(1);
    for(int i=1;i<=n;i++)
    {
        int now = id[i];
        for(int l=1;l<=lg[n];l++)
        {
            st[now][l] = st[st[now][l-1]][l-1];
        }
    }
}
int lca(int x,int y)
{
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=lg[n];i>=0;i--)
    {
        if(dep[st[x][i]] >= dep[y]) x = st[x][i];
    }
    if(x==y)return x;
    for(int i=lg[n];i>=0;i--)
    {
        if(st[x][i] != st[y][i])
        {
            x = st[x][i];
            y = st[y][i];
        }
    }
    return fa[x];
}
void graph(int x,int y,int now)
{
    int lc=lca(x,y);
    while(x != lc)
    {
        for(int i:s[x])
        {
            if(i==now) continue;
            e[i].push_back(now);
            in[now]++;
        }
        for(int i:t[x])
        {
            if(i==now) continue;
            e[now].push_back(i);
            in[i]++;
        }
        x = fa[x];
    }
//      << x << ">.<\n"; 
    for(int i:s[x])
    {
        if(i==now) continue;
//       	  << "s" << i << endl;
        e[i].push_back(now);
        in[now]++;
    }
    for(int i:t[x])
    {
        if(i==now) continue;
//          << "t" << i << endl; 
        e[now].push_back(i);
        in[i]++;
    }
    x = fa[x];
    while(y != lc)
    {
//    	  << y << ">.<\n";
        for(int i:s[y])
        {
//        	  << "s" << i << endl;
            if(i != now)
            {
                e[i].push_back(now);
                in[now]++;
			}
        }
        for(int i:t[y])
        {
//        	  << "t" << i << endl;
            if(i != now)
            {
            	e[now].push_back(i);
            	in[i]++;
            }
        }
        y = fa[y];
    }
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        e1[i].clear();
        s[i].clear();
        t[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
    	e[i].clear();
    }
    memset(in,0,sizeof(in));
    memset(fa,0,sizeof(fa));
    memset(dfn,0,sizeof(dfn));
	tot = 0; 
}
bool check()
{
    queue<int> q;
    for(int i=1;i<=m;i++)
    {
        if(in[i]==0) q.push(i);
    }
    int cnt = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        cnt++;
        for(int i:e[now])
        {
            in[i]--;
            if(in[i] == 0) q.push(i);
        }
    }
    return cnt == m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
    int T;
    cin >> T;
    for(int i=1;i<=120000;i++)
    {
        lg[i] = lg[i-1] + (i-1==(1<<(lg[i-1])));
    }
    while(T--){
    cin >> n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        e1[u].push_back(v);
        e1[v].push_back(u);
    }
    dfs(1,0);
    build();
    cin >> m;
    for(int i=1,u,v;i<=m;i++)
    {
        cin >> s1[i] >> t1[i];
        s[s1[i]].push_back(i);
        t[t1[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        graph(s1[i],t1[i],i);
    }
    if(check())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    init();
}}
