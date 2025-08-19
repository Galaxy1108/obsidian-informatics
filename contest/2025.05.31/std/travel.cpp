#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
const int INF = 0x7fffffff;

#define FI(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;

        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};

struct node
{
    int v, w, pre;
    node(int v, int w, int pre = 0)
    {
        this->v = v;
        this->w = w;
        this->pre = pre;
    }
    friend bool operator < (const node &a, const node &b)
    {
        if (a.w != b.w) return a.w > b.w;
        if (a.v != b.v) return a.v < b.v;
        return a.pre < b.pre;
    }
};
vector<node> g[maxn];
priority_queue<node> pq;
int dis[maxn][52];
bool vis[maxn][52];
int n, m;

void dijkstra()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= 50; ++j)
            dis[i][j] = INF;
    dis[1][0] = 0;
    pq.push(node(1, 0));
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        int u = cur.v;
        int pre = cur.pre;
        if (vis[u][pre]) continue;
        vis[u][pre] = true;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if (pre)
            {
                if (dis[u][pre] + (pre + w) * (pre + w) < dis[v][0])
                {
                    dis[v][0] = dis[u][pre] + (pre + w) * (pre + w);
                    pq.push(node(v, dis[v][0], 0));
                }
            }
            else
            {
                if (dis[v][w] > dis[u][0])
                {
                    dis[v][w] = dis[u][0];
                    pq.push(node(v, dis[v][w], w));
                }
            }
        }
    }
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    FI(n); FI(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        FI(u); FI(v); FI(w);
        g[u].push_back(node(v, w));
        g[v].push_back(node(u, w));
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
    {
        if (dis[i][0] == INF) dis[i][0] = -1;
        printf("%d ", dis[i][0]);
    }
    return 0;
}