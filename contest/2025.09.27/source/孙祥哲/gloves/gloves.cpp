#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[100005], b[100005];
multiset<int> s, t;

bool check(int mid)
{
	s = t;
	for (int i = 1; i <= n; i++)
	{
		auto p1 = s.lower_bound(a[i]-mid), p2 = s.upper_bound(a[i]+mid);
		if (p2 == s.begin()) return 0; p2--;
		if (p1 == s.end()) return 0;
//		cout << "("; for (auto j : s) cout << j << "."; cout << ")";
//		cout << a[i] << " " << mid << "-" << *p1 << "-" << *p2 << '\n';
		if (*p1 > a[i] && *p2 < a[i]) return 0;
		s.erase(p1);
	}
	return 1;
}

signed main()
{
	freopen("gloves.in", "r", stdin);
	freopen("gloves.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	if (n <= m)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i], t.insert(b[i]);
	}
	else
	{
		for (int i = 1; i <= n; i++) cin >> b[i], t.insert(b[i]);
		for (int i = 1; i <= m; i++) cin >> a[i];
		swap(n, m);
	}
	sort(a+1, a+1+n), sort(b+1, b+1+m);
//	cout << check(3);
	int l = 0, r = max(a[n],b[m])-min(a[1],b[1]), ans;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid-1;
		else l = mid+1;
	}
	cout << ans;
	return 0;
}
