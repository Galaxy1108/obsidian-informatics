#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1001;

int a, b;
int vis[N];
int ans[N];
int lim = 0;
bool flag = 0;

int gcd(int x, int y) {
    if(x % y == 0) return y;
    else return gcd(y, x % y);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

void dfs(int dep, int a, int b, int lastn) {
    if(dep == lim) {
        if(a == 1) {
            if(b > vis[dep - 1]) flag = 1, vis[dep] = b;
            else {
                for(int i = 1; i <= dep - 1; i++) if(vis[i] == b) return;
                vis[dep] = b;
            }
        }
        return;
    }
    for(int i = (lim - dep + 1) * b / a; i >= max(lastn + 1, (b % a == 0 ? b / a: b / a + 1)); i--) {
        vis[dep] = i;
        int t1 = (a * i - b), t2 = b * i;
        int ttt = gcd(t1, t2);
        t1 /= ttt, t2 /= ttt;
        dfs(dep + 1, t1, t2, i);
        if(flag) return;
        vis[dep] = 0;
    }
    return;
}

signed main() {
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    cin >> a >> b;
    if(a == 0) {
        cout << -1 << endl;
        return 0;
    }
    int ttt = gcd(a, b);
    a /= ttt, b /= ttt;
    for(int i = 1; i <= 100; i++) {
        lim = i;
        dfs(1, a, b, 0);
        if(flag) {
            sort(vis + 1, vis + lim + 1);
            cout << lim << endl;
            for(int i = 1; i <= lim; i++) cout << vis[i] << " ";
            cout << endl;
            break;
        }
    }
    return 0;
}