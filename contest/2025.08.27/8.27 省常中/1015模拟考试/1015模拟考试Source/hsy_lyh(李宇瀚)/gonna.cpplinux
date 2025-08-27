#include<bits/stdc++.h>
#define int long long

using namespace std;

// 开O2好吗？ 秋梨膏！

int n, p;
int pri[100001], tot = 0;
int ju[100001];
vector<pair<int,int> > v[20001];
int gx[20001];
int ttt[20001];
int ans = 0;

inline int fpow(int a, int b) {
    int ans = 1, base = a;
    while(b > 0) {
        if(b & 1) ans = (ans * base) % p;
        base = (base * base) % p;
        b >>= 1;
    }
    return ans % p;
}

inline int getInv(int x) {
    return fpow(x, p - 2);
}

void el() {
    for(int i = 2; i <= 100000; i++) {
        if(!ju[i]) pri[++tot] = i;
        for(int j = 1; j <= tot; j++) {
            if(i * pri[j] > 100000) break;
            ju[i * pri[j]] = 1;
            if(!i % pri[j]) break;
        }
    }
    return;
}

signed main() {
    freopen("gonna.in", "r", stdin);
    freopen("gonna.out", "w", stdout);
    cin >> n >> p;
    el();
    for(int i = 1; i <= n; i++) {
        v[i] = v[i - 1];
        int indx = 0;
        int k = i;
        for(int j = 1; j <= tot; j++) {
            if(pri[j] > i) break;
            if(k % pri[j] == 0) {
                int cc = 0;
                while(k % pri[j] == 0) k /= pri[j], cc++;
                while(indx < v[i].size() && v[i][indx].first < pri[j]) indx++;
                if(indx < v[i].size()) v[i][indx].second += cc;
                else v[i].push_back(make_pair(pri[j], cc));
            }
        }
        for(int j = 0; j < v[i].size(); j++) ttt[v[i][j].first] -= 2 * v[i][j].second;
        for(int j = 0; j < v[i].size(); j++) gx[v[i][j].first] = (i + 1) * v[i][j].second + ttt[v[i][j].first];
        int tmp = 1;
        for(int j = 2; j <= i; j++) {
            if(gx[j] == 0) continue;
            int t1 = (((fpow(j, gx[j] + 1) - 1 + p) % p) * getInv(j - 1)) % p;
            tmp = (tmp * t1) % p;
        }
        ans = (ans + tmp) % p; 
    }
    cout << ans << endl;
    return 0;
}