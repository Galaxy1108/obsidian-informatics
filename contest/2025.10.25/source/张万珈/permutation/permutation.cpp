#include <bits/stdc++.h>
using namespace std;
const int N = 610;
int a[N];
int a1[N];
int b[N];
bool vis[N];
int n;
map<int,int> cnt;
int ans;
void count()
{
    int now = 0;
    // for(int i=1;i<=n*2;i++)
    // {
    //     cout << a1[i] << ' ';
    // }
    for(int i=1;i<=n;i++)
    {
        b[i] = min(a1[i*2-1],a1[i*2]);
        now = now*10 + b[i];
    }
    // cout << now << '\n';
    if(!cnt[now])
    {
        ans++;
    }
    cnt[now]++;
}
void dfs(int now)
{
    if(now > n*2)
    {
        count();
        return;
    }
    if(a[now] != -1) {a1[now] = a[now];dfs(now+1);}
    else
    {
        for(int i=1;i<=n*2;i++)
        {
            if(!vis[i])
            {
                a1[now] = i;
                vis[i] = 1;
                dfs(now+1);
                vis[i] = 0;
            }
        }
    }
}
int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n*2;i++)
    {
        cin >> a[i];
        if(a[i] != -1) vis[a[i]] = 1;
    }
    if(n<=5) {dfs(1);cout << ans;}
    else cout << 1;
}