#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 5;

int n, m, k;
struct line{
    int l, r; 
};

line b[N];
int a[N];
int num[N * 4], tot = 0;
int su[N * 4];
int mapn[N * 4];
vector<int> v[1001];
int minans = 1e9;

int getans() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!v[i].size()) continue;
        sort(v[i].begin(), v[i].end());
        if(v[i][v[i].size() - 1] < a[i]) ans += num[a[i]] - num[v[i][0]];
        else if(v[i][0] > a[i]) ans += num[v[i][v[i].size() - 1]] - num[a[i]];
        else ans += num[v[i][v[i].size() - 1]] - num[v[i][0]] + min(num[a[i]] - num[v[i][0]], num[v[i][v[i].size() - 1]] - num[a[i]]);
    }
    return ans;
}

void dfs(int nown) {
    if(nown == m + 1) {
        minans = min(minans, getans());
        cout << minans << endl;
        return;
    }
    if(su[b[nown].r] - su[b[nown].l - 1] == 0) dfs(nown + 1); 
    else {
        int indx = 0;
        for(int i = b[nown].l; i >= 1; i--) {
            if(mapn[i]) {
                indx = mapn[i];
                break;
            }
        }
        if(indx) {
            v[indx].push_back(b[nown].l), dfs(nown + 1);
            v[indx].pop_back();
        }
        indx = 0;
        for(int i = b[nown].r; i <= k; i++) {
            if(mapn[i]) {
                indx = mapn[i];
                break;
            }
        }
        if(indx) {
            v[indx].push_back(b[nown].r), dfs(nown + 1);
            v[indx].pop_back();
        }
    }
    return;
}

signed main() {
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], num[++tot] = a[i];
    for(int i = 1; i <= m; i++) cin >> b[i].l >> b[i].r, num[++tot] = b[i].l, num[++tot] = b[i].r;
    sort(num + 1, num + tot + 1);
    k = unique(num + 1, num + tot + 1) - num - 1;
    for(int i = 1; i <= n; i++) a[i] = lower_bound(num + 1, num + k + 1, a[i]) - num;
    for(int i = 1; i <= m; i++) b[i].l = lower_bound(num + 1, num + k + 1, b[i].l) - num, b[i].r = lower_bound(num + 1, num + k + 1, b[i].r) - num;
    for(int i = 1; i <= n; i++) mapn[a[i]] = i;
    for(int i = 1; i <= k; i++) su[i] = su[i - 1] + (mapn[i] != 0);
    dfs(1);
    cout << minans << endl;
    return 0;
}