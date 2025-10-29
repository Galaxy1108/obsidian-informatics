#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
vector<int> ans;
void dfs(int a,int b,int x)
{
    if(a==1) {ans.push_back(b);return;}
    int x1 = ((b-1)/a) + 1;
    x = max(x1,x);
    ans.push_back(x);
    a = a*x - b;
    b = x*b;
    int gd = __gcd(a,b);
    a /= gd,b /= gd;
    dfs(a,b,x+1);
}

signed main()
{
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    int a,b;
    cin >> a >> b;
    dfs(a,b,0);
    cout << ans.size() << '\n';
    for(int x:ans)
    {
        cout << x << ' ';
    }
}