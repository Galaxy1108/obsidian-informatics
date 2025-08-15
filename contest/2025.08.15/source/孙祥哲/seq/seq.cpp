#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

void read(int &n)
{
	int x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	n=x;
}

int n, m, a[105], b[105], p2[105];
int ans, c[35];
map<vector<int>, int> mp;

void dfs(int x, int cnt)
{
	if (x > n)
	{
		if (cnt)
		{
			cnt = 0;
			bool flag = 0;
			vector<int> v(15);
			for (int i = 1; i <= n; i++)
				if (c[i]) v[++cnt] = a[i];
			if (mp[v]) return;
			mp[v] = 1;
			for (int i = 1; i <= max(cnt, m); i++)
				if (v[i] != b[i]) { flag = b[i]>v[i]; break; }
			ans += flag;
		}
		return;
	}
	c[x] = 1, dfs(x+1, cnt+1);
	c[x] = 0, dfs(x+1, cnt);
}

int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    read(n); for (int i = 1; i <= n; i++) read(a[i]);
    read(m); for (int i = 1; i <= m; i++) read(b[i]);
    dfs(1, 0);
    cout << ans+1;
    return 0;
}

