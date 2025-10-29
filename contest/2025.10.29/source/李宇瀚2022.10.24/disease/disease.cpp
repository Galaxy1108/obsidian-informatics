#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

struct node {
    int nown, siz;
    bool operator < (const node &n) const{
        return siz > n.siz;
    }
    bool operator > (const node &n) const{
        return siz < n.siz;
    }
};

int n, p;
int head[N], pre[N], ver[N], cnt = 0;
int siz[N], fa[N];
int cntt;
priority_queue<node> q;

void add_edge(int u, int v) {
    pre[++cnt] = head[u];
    head[u] = cnt;
    ver[cnt] = v;
    return ;
}

void dfs(int nown, int f) {
    fa[nown] = f, siz[nown] = 1;
    for(int i = head[nown]; i; i = pre[i]) {
        int v = ver[i];
        if(v == f) continue;
        dfs(v, nown);
        siz[nown] += siz[v];
    }
    return;
}

int main() {
    freopen("disease.in", "r", stdin);
    freopen("disease.out", "w", stdout);
    cin >> n >> p;
    for(int i = 1; i <= p; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    q.push((node){1, siz[1]});
    int cntt = n - 1;
    while(cnt > 0) {
        vector<int> v;
        if(q.empty()) break;
        int maxn = 0, indx = 0;
        while(!q.empty()) {
            int nown = q.top().nown, nowb = q.top().siz;
            q.pop();
            for(int i = head[nown]; i; i = pre[i]) {
                int vv = ver[i];
                if(vv == fa[nown]) continue;
                v.push_back(vv);
                if(siz[vv] > maxn) {
                    maxn = siz[vv];
                    indx = vv;
                }
            }
        }
        for(int i = 0; i < v.size(); i++) {
            if(indx != v[i]) {
                q.push((node){v[i], siz[v[i]]});
                cntt--;
            }
        }
    }
    cout << n - cntt << endl;
    return 0;
}