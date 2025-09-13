#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector<int> 
#define mod 998244353
using namespace std;

ll read() {ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void write(int x) {if(x>9)write(x/10);putchar(x%10+'0');}

int T, n;
vi a;
map<vi, int> dis, vis;

bool check(const vi& x)
{
	for (int i = 1; i < n; i++) if (x[i+1] > x[i]) return 0;
	return 1;
}

signed main()
{
	freopen("jyrg.in", "r", stdin);
	freopen("jyrg.out", "w", stdout);
	T = read();
	while (T--)
	{
		vis.clear(), dis.clear(), a.clear();
		n = read(); a = vi(n+5);
		for (int i = 1; i <= n; i++) a[i] = read();
		vis[a] = 1, dis[a] = 0;
		queue<vi> q; q.push(a);
		int minn = 5e18;
		while (!q.empty())
		{
			vi x = q.front(); q.pop();
//			for (int i = 1; i <= n; i++) cout << x[i] << "-"; cout << '\n';
			if (check(x)) {minn = min(minn, dis[x]); continue;} 
			if (dis[x] >= minn) continue;
			for (int i = 1; i < n; i++)
			{
				vi y = x;
				swap(y[i], y[i+1]), y[i]--, y[i+1]++;
				if (!vis[y])
				{
					vis[y] = 1, dis[y] = max(dis[x], x[i]+x[i+1]);
					q.push(y);
				}
			}
		}
		cout<<(minn==5e18?-1:minn), putchar('\n');
	}
	return 0;
}
/*
5
3
6 7 8
*/
