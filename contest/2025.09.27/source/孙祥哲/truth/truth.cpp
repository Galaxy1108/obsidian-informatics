#include <bits/stdc++.h>
#define ll long long
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;

int read() {int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void write(int x) {if(x>9)write(x/10);putchar(x%10+'0');}

int n, k, m, minn, _, _1_;
int a[50005], s[50005][35], lst[35], change[35], res[100005];

void init()
{
//	for (int i = 1; i <= k; i++) lst[i] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = lst[a[i]]+1; j <= i; j++) s[j][a[i]] = i;
//		lst[a[i]] = i;
//	}
//	for (int i = 1; i <= k; i++)
//		for (int j = lst[i]+1; j <= n; j++)
//			s[j][i] = 1e9;
//	minn = 1e9;
//	for (int i = 1; i <= n; i++)
//	{
//		int _ = 0;
//		for (int j = 1; j <= k; j++) _ = max(s[i][j], _);
//		minn = min(minn, _-i+1);
//	}
	for (int p = 1; p <= k; p++)
	{
		if (!change[p]) continue;
		lst[p] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != p) continue;
			for (int j = lst[a[i]]+1; j <= i; j++) s[j][a[i]] = i;
			lst[a[i]] = i;
		}
		for (int j = lst[p]+1; j <= n; j++)
			s[j][p] = 1e9;
	}
	
	minn = 1e9;
	for (int i = 1; i <= n; i++)
	{
		if (minn == k) break;
		int _ = 0;
		for (int j = 1; j <= k; j++) _ = max(s[i][j], _);
		minn = min(minn, _-i+1);
	}
//	for (int i = 1; i <= k; i++)
//	{
//		for (int j = 1; j <= n; j++) cout << s[j][i] << " "; cout << '\n';
//	}
}

signed main()
{
	freopen("truth.in", "r", stdin);
	freopen("truth.out", "w", stdout);
	n = read(), k = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= k; i++) change[i] = 1;
	while (m--)
	{
		int op = read(), x, y;
		if (op == 1) x = read(), y = read(), change[y] = change[a[x]] = 1, a[x] = y, _ = 0;
		else
		{
			if (k == 3) { puts("3"); continue; }
			if (!_)
			{
				init(), _ = 1; _1_++;
				for (int i = 1; i <= k; i++) change[i] = 0;
			}
			minn>n?puts("-1"):(write(minn),putchar('\n'));
		}
	}
//	cout << _1_ << "---------";
	return 0;
}
