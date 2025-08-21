#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

struct node {
    int val, id;
};

int n;
node h[N];
int num[N];
int vis[N];
int ys[N];
int ans = 0;

bool chk() {
    for(int i = 1; i < n; i++) if(h[i].val > h[i + 1].val) return false;
    return true;
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i].val, h[i].id = i, num[i] = h[i].val;
    sort(num + 1, num + n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(num[j] == h[i].val && !vis[j]) {
                vis[j] = 1;
                ys[h[i].id] = j;
                break;
            }
        }
    } 
    while(1) {
        if(chk()) break;
        for(int i = n; i >= 1; i--) {
            if(h[i].id != ys[h[i].id]) {
                for(int j = i - 1; j >= 1; j--) {
                    if(ys[h[i].id] > j) break;
                    if(h[j].id == ys[h[j].id]) continue;
                    if(ys[h[j].id] >= i) {
                        swap(h[i], h[j]);
                        ans += abs(i - j) * 2;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}