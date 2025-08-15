#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+9;
typedef unsigned long long ull;
#define int ull
__int128 f[5010][5010];
__int128 md(__int128 x)
{
    x -= (x/mod)*mod;
    if(x<0) x+=mod;
    return x;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
	int n,m,q;
    cin >> n >> m >> q;
    for(int i=1,l,r,x;i<=m;i++)
    {
        cin >> l >> r >> x;
        for(int j=1;j<=n;j++)
        {
            f[i][j] = f[i-1][j];
            if(l <= j && j <= r)f[i][j] = (f[i][j] + x%mod) % mod;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
        	// cout << f[i][j] << ' ';
            f[i][j] = md(f[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1]); 
        }
        // cout << endl;
    }
    for(int i=1,u,d,l,r;i<=q;i++)
    {
        cin >> u >> d >> l >> r;
        cout << (long long)md(f[d][r] - f[d][max(l-1,0ull)] - f[max(u-1,0ull)][r] + f[max(u-1,0ull)][max(l-1,0ull)]) << endl;
    }
    return 0;
}
