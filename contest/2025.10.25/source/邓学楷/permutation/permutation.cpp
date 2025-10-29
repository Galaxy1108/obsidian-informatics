#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
int n, a[610], in[610], cnt;
long long prod[610] = {1};
vector<int> bi, bn;
map<vector<int>, bool> mp;

int main()
{
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n * 2; i++) cin >> a[i];
    for (int i = 1; i <= n * 2; i++)
        if (a[i] == -1) bi.push_back(i);
        else in[a[i]] = 1;
    for (int i = 1; i <= n * 2; i++)
        if (!in[i])
            bn.push_back(i);
    do
    {
        for (int i = 0; i < bn.size(); i++)
            a[bi[i]] = bn[i];
        vector<int> v;
        for (int i = 1; i <= n * 2; i+=2)
            v.push_back(min(a[i], a[i + 1]));
        if (!mp[v])
            mp[v] = 1, cnt = (cnt + 1) % M;
    } while (next_permutation(bn.begin(), bn.end()));
    cout << cnt << endl;
    return 0;
}