#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
using namespace std;

int n, m, q;
int from[100005], to[100005], f[100005][25], dep[100005];
vector<int> G[100005];
vector<pii> W[100005];
int stk[100005], top;
bool vis[100005], flag, f1 = 1;
ll s, t, xx, yy, ans;
ll dis[100005];

void dfs(int x)
{
    if (flag) return;
    if (x == t)
    {
//    	cout << top << endl;
        if (top)
        {
            sort(stk+1, stk+1+top);
            for (int i = 1; i <= top; i++)
            {
                if (yy >= stk[i]) yy -= stk[i];
                else xx--;
            }
            flag = 1;
        }
        return;
    }
    vis[x] = 1;
    for (int y : G[x])
    {
        if (vis[y]) continue;
        int cnt = 0;
        for (pii t : W[x])
        {
            int to = t.second, w = t.first;
            if (to == y) stk[++top] = w, cnt++;
        }
        dfs(y);
        top -= cnt;
    }
}

void dfs1(int x, int fa)
{
    f[x][0] = fa, dep[x] = dep[fa] + 1;
    for (int i = 1; i <= 20; i++)
        f[x][i] = f[f[x][i-1]][i-1];
    for (int y : G[x])
    {
        if (y == fa) continue;
        int cnt = 0;
        for (pii t : W[x])
        {
            int to = t.second;
            if (to == y) cnt++;
        }
        dis[y] = dis[x] + cnt;
        dfs1(y, x);
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

void prin()
{
    for (int i = 1; i <= n; i++)
    	cout << dis[i] << " ";
    puts("");
    
    for (int i = 1; i <= n; i++)
    	cout << dep[i] << " ";
    puts("");
    
    for (int i = 1; i <= n; i++)
    	for (int j = i+1; j <= n; j++)
    		printf("LCA(%d, %d) = %d.\n", i, j, lca(i, j));
}

int main()
{
     freopen("currencies.in", "r", stdin);
     freopen("currencies.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        G[x].push_back(y), G[y].push_back(x);
        from[i] = x, to[i] = y;
    }
    ll last;
    for (int i = 1, p, c; i <= m; i++)
    {
        scanf("%d%d", &p, &c);
        W[from[p]].push_back({c, to[p]}), W[to[p]].push_back({c, from[p]});
        if (last != c && i > 1) f1 = 0;
        last = c;
    }
	if (f1) dfs1(1, 0);
//	prin();
    while (q--)
    {
        scanf("%d%d%lld%lld", &s, &t, &xx, &yy);
        if (f1)
        {
            ll tt = dis[s] + dis[t] - dis[lca(s, t)] * 2;
//            printf("%d\n", tt);
            xx -= max(0ll, tt - yy / last);
        }
        else
        {
            flag = top = 0, ans = -1, memset(vis, 0, sizeof(vis));
            dfs(s);
        }
        printf("%d\n", xx >= 0 ? xx : -1);
    }
    return 0;
}
