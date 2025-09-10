#include <bits/stdc++.h>
using namespace std;

mt19937 rd(20100217);
int p[100010],q[100010],h[100010];
bool vis[100010];
vector<vector<int> > p1,h1;

inline void solvep(int x)
{
    vector<int> now;
    while(!vis[x])
    {
        now.push_back(x);
        vis[x] = 1;
        x = p[x];
    }
    p1.push_back(now);
}
inline void solveh(int x)
{
    vector<int> now;
    while(!vis[x])
    {
        now.push_back(x);
        vis[x] = 1;
        x = h[x];
    }
    h1.push_back(now);
}

bool cmp(vector<int> a,vector<int> b)
{
    return a.size() < b.size();
}

int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> q[i];
        h[q[i]] = i;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) solvep(i);
    }
    for(int i=1;i<=n;i++) vis[i] = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) solveh(i);
    }
    if(p1.size() != h1.size())
    {
        cout << "NO";
        return 0;
    }
    sort(p1.begin(),p1.end(),cmp);
    sort(h1.begin(),h1.end(),cmp);
    for(int i=0;i<p1.size();i++)
    {
        if(p1[i].size() != h1[i].size())
        {
            cout << "NO";
            return 0;
        }
        for(int j=0;j<p1[i].size();j++)
        {
            h[h1[i][j]] = p[p1[i][(p1[i].size() - j) % (p1[i].size())]];
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++)
    {
        cout << h[i] << ' ';
    }
    return 0;
}
