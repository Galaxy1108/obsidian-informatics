#include<bits/stdc++.h>

using namespace std;

const int N = 15;
const int M = 998244353;

struct xl {
    int len;
    int a[N];

    bool operator == (const xl l)const {
        if(len != l.len) return false;
        for(int i = 1; i <= len; ++i) if(a[i] != l.a[i]) return false;
        return true;
    }

    bool operator <(const xl l)const {
        int ll = min(l.len, len);
        for(int i = 1; i <= ll; ++i) {
            if(a[i] < l.a[i]) return true;
            else if(a[i] > l.a[i]) return false;
        }
        if(len < l.len) return true;
        else return false;
    }
};

int n, m;
xl A, B;
xl a[10001];
int tot = 0, cc = 0, temp[101];

void dfs(int nown) {
    if(nown == n + 1) {
        if(!tot) return;
        a[++cc].len = tot;
        for(int i = 1; i <= tot; ++i) a[cc].a[i] = temp[i];
        return;
    }
    dfs(nown + 1);
    temp[++tot] = A.a[nown];
    dfs(nown + 1);
    tot--;
    return;
}

int main() {
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n; A.len = n;
    for(int i = 1; i <= n; ++i) cin >> A.a[i];
    cin >> m; B.len = m;
    for(int i = 1; i <= m; ++i) cin >> B.a[i];
    dfs(1);
    sort(a + 1, a + cc + 1);
    int tk = unique(a + 1, a + cc + 1) - a - 1;
    int Ansn = 0;
    for(int i = 1; i <= tk; ++i) {
        if(a[i] == B) {
            Ansn = i;
            break;
        }
    }
    cout << Ansn % M << '\n';
    return 0;
}