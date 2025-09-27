#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, cnt[3], _;
queue<string> q;
map<string, int> dis, vis;
string s;

bool check(const string& s) {_=1;for(int i=1;i<=n;i++)_&=s[i]!=s[i-1];return _;}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s; n = s.size(), s = " " + s;
	for (int i = 1; i <= n; i++) cnt[s[i]-'0']++;
	if (check(s)) { cout<<"0"; return 0; }
//	cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
	if (cnt[0] > (n+1)/2 || cnt[1] > (n+1)/2 || cnt[2] > (n+1)/2) { cout<<"-1"; return 0; }
	vis[s] = 1, dis[s] = 0;
	q.push(s);
	while (!s.empty())
	{
		string u = q.front(); q.pop();
		if (check(u)) { cout<<dis[u]; return 0; }
		for (int i = 1; i < n; i++)
		{
			string v = u; swap(v[i], v[i+1]);
			if (!vis[v]) { vis[v] = 1; q.push(v), dis[v] = dis[u]+1; }
		}
	}
	return 0;
}
//111110000022222
