#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[1000010],p[1000010],c[1000010],t[1000010],s[1000010];
int dp[1000010];
int q[1000010],hd=1,tl;
int dy(int a,int b)
{
    return dp[a] + t[a] - dp[b] - t[b];
}
int dx(int a,int b)
{
    return s[a] - s[b];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("storage.in","r",stdin);
    freopen("storage.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> p[i] >> c[i];
        s[i] = s[i-1] + p[i];
        t[i] = t[i-1] + (x[i] * p[i]);
    }
    q[++tl] = 0;
    for(int i=1;i<=n;i++)
    {
        while(hd<tl && x[i] * dx(q[hd],q[hd+1]) <= dy(q[hd],q[hd+1])) hd++;
        int j=q[hd];
        dp[i] = dp[j] + x[i]*(s[i] - s[j]) - (t[i] - t[j]) + c[i];
        while(hd < tl && dy(q[tl-1],q[tl]) * dx(q[tl],i) > dy(q[tl],i) * dx(q[tl-1],q[tl])) tl--;
        q[++tl] = i; 
    }
    cout << dp[n];
    return 0;
}