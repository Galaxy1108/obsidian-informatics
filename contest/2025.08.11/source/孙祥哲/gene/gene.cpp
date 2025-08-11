#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, l, r, maxn = -1e9, ans = 1e9;
int a[1000005], ci[1000005], nxt[1000005], frt[1000005], nr[1000005];
bool f1[1000005], f2[1000005];
vector<int> s[1000005];

void print()
{
	for(int i=1;i<=n;i++){cout<<f1[i]<<" ";}cout<<'\n';
	for(int i=1;i<=n;i++){cout<<f2[i]<<" ";}cout<<'\n';
	for(int i=1;i<=n;i++){cout<<nxt[i]<<" ";}cout<<'\n';
	for(int i=1;i<=n;i++){cout<<frt[i]<<" ";}cout<<'\n';
	for(int i=1;i<=n;i++){cout<<nr[i]<<" ";}cout<<'\n';
}

int main()
{
	freopen("gene.in", "r", stdin);
	freopen("gene.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) cin >> a[i], maxn = max(maxn, a[i]);
//	if (n <= 1000)
//	{
//		for (int i = 1; i < n; i++)
//			for (int j = i+1; j <= n; j++)
//				m[a[i]][a[j]]++;
//		for (int i = 1; i < l; i++)
//			for (int j = r+1; j <= n; j++)
//				if (m[a[i]][a[j]] == 1) ans = min(ans, j-i+1);
//		cout << (ans==1e9?-1:ans);
//	}
//	else if (maxn <= 1000)
	{
		for (int i = 1; i <= n; i++) s[a[i]].push_back(i);
		for (int i = 1; i <= n; i++) ci[a[i]]++, f1[i] = ci[a[i]]==1;
		memset(ci, 0, sizeof(ci));
		for (int i = n; i >= 1; i--) ci[a[i]]++, f2[i] = ci[a[i]]==1;
		for (int i = 1; i <= n; i++)
		{
			auto p = lower_bound(s[a[i]].begin(), s[a[i]].end(), i); p++;
			if (p != s[a[i]].end()) nxt[i] = *p;
			p--;
			if (p != s[a[i]].begin()) p--, frt[i] = *p;
		}
		for (int i = n; i >= 1; i--) nr[i] = f2[i]?i:nr[i+1];
		for (int i = l-1; i >= 1; i--)
		{
			if (nxt[i] == 0) nxt[i] = n+1;
			if (!f1[i] || nxt[i]<=nr[r+1]) continue;
			//nr[r+1]~nxt[i]-1
			for (int j = nr[r+1]; j < min(nxt[i], i+ans); j++)
				if (f2[j] && frt[j] < i) {ans = min(ans, j-i+1);break;}
//			if ((nxt[i]>j||nxt[i]==0) && frt[j] < i) ans = min(ans, j-i+1);
		}
//		print();
		cout << (ans==1e9?-1:ans);
	}
	return 0;
} 
