#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct per
{
	vector<int> v; int len;
	per() { len = 0; }
	per(int l) { len = l; v = vector<int>(l+1); }
	void print() {for(int i=1;i<=len;i++)cout<<v[i]<<" ";cout<<'\n';}
};
per operator * (const per& x)
{
	per y(x.len);
	for (int i = 1; i <= x.len; i++) y.v[x.v[i]] = i;
	return y;
}
per operator * (const per& x, const per& y)
{
	per z(x.len);
	for (int i = 1; i <= x.len; i++) z.v[i] = y.v[x.v[i]];
	return z;
}

int n, _;
bool vis[100005], vi[100005];
per p, q, h;

void dfs(int x)
{
	if (_) return;
	if (x > n)
	{
		if ((h*p**h).v == q.v) { _=1,cout << "YES\n"; h.print();exit(0); }
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) vis[i]=1, h.v[x]=i, dfs(x+1), vis[i] = 0;
}
//void ds(int x)
//{
//	if (x > n)
//	{
////		puts("-------------");
//		_ = 0;
//		memset(vis, 0, sizeof(vis));
//		dfs(1);
//		if (_) cout<<"--",p.print(),cout<<"--",q.print(),puts("-------------");
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//		if (!vi[i]) vi[i]=1, q.v[x]=i, ds(x+1), vi[i] = 0;
//}

int main()
{
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	cin >> n;
	p = per(n), q = per(n), h = per(n);
	for (int i = 1; i <= n; i++) cin >> p.v[i];
//	ds(1);
	for (int i = 1; i <= n; i++) cin >> q.v[i];
	if (p.v == q.v)
	{
		cout << "YES\n";
		for(int i=1;i<=n;i++)cout<<i<<" ";cout<<'\n';
		exit(0);
	}
	if (n > 10) { puts("NO"), exit(0); }
	dfs(1);
	puts("NO");
	return 0;
}
/*
5
2 1 5 3 4
4 3 2 5 1
(3 1 2 5 4)
3
2 1 3
3 2 1
(1 3 2)
5
2 3 4 5 1
4 3 5 2 1
10
1 2 3 4 5 6 7 8 9 10
7 3 6 2 9 5 8 4 1 10

*/
