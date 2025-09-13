#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int n, x, y;
bool flag;
int a[301][301];
int fz[N], tot = 0;
int BIT[N], BIT2[11];
int vis[11];

inline int lowbit(int x) {
    return x & (-x);
}

void update(int *A, int x, int k) {
    for(int i = x; i <= n * n; i += lowbit(i)) A[i] += k;
    return;
}

int query(int *A, int x) {
    int ans = 0;
    for(int i = x; i >= 1; i -= lowbit(i)) ans += A[i];
    return ans;
}


void prin() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return;
}

bool chk(int opt, int tt) {
    tot = 0;
    if(opt == 0) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) fz[++tot] = a[j][i];
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) fz[++tot] = a[i][j];
        }
    }
    int tmp = (opt == 0 ? y : x);
    if(tt == 0) memset(BIT2, 0, sizeof(BIT2));
    else memset(BIT, 0, sizeof(BIT));
    int cnt = 0;
    for(int i = 1; i <= tot; i++) {
        if(tt == 0) cnt += query(BIT2, n * n) - query(BIT2, fz[i]), update(BIT2, fz[i], 1);
        else cnt += query(BIT, n * n) - query(BIT, fz[i]), update(BIT, fz[i], 1);
    }
    return (cnt == tmp);
}  

void dfs(int nown) {
    if(nown == n * n + 1) {
        if(chk(0, 0) && chk(1, 0)) flag = 1;
        return;
    }
    int x = (nown - 1) / n + 1, y = (nown - 1) % n + 1;
    for(int i = 1; i <= n * n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        a[x][y] = i;
        dfs(nown + 1);
        if(flag) return;
        vis[i] = 0;
        a[x][y] = 0;
    }
    return;
}

int main() {
    freopen("matrixcascade.in", "r", stdin);
    freopen("matrixcascade.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        if(min(x, y) == 0) {
            if(x == 0) {
                int tot = 1;
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) a[i][j] = tot, tot++;
                }
                if(chk(0, 1)) {
                    cout << "YES" << endl;
                    prin();
                }
                else cout << "NO" << endl; 
            }
            else if(y == 0) {
                int tot = 1;
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++) a[j][i] = tot, tot++;
                }
                if(chk(1, 1)) {
                    cout << "YES" << endl;
                    prin();
                }
                else cout << "NO" << endl;
            }
        }
        else if(n <= 3) {
            memset(vis, 0, sizeof(vis));
            flag = 0;
            dfs(1);
            if(!flag) cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                prin();
            }
        }
        else {
            cout << "YES" << endl;
            int tot = 1;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) cout << tot << " ", tot++;
                cout << endl;
            }
        }
    }
    return 0;
}