#include <bits/stdc++.h>
using namespace std;

const int N = 5050;

int a[N][N], n, seed, b[N][N], vis[N], now[N << 1];

void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d%d", &n, &seed);
    if (seed == 0)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n + 1; j++)
                scanf("%d", &a[i][j]);
    else
        gen(n, seed);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            b[i][a[i][j]] = j;
    for (int i = 1; i <= 2 * n; i++)
        now[i] = 1;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = n; j >= 1; j--) {
            int p = (i + j - 1 - 1) % n + 1;
            while (vis[b[p][now[i + j - 1]]]) now[i + j - 1]++;
            vis[b[p][now[i + j - 1]]] = 1;
        }
        for (int i = 1; i <= n + 1; i++)
            if (vis[i] == 0) printf("%d ", i);
    }
    return 0;
}
/*
2 0
1 2 3
1 3 2
*/