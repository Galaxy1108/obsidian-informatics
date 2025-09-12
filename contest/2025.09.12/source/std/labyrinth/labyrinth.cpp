#include <bits/stdc++.h>
#define MAXN 200010
#define MAXK 18
using namespace std;

int T, n;
vector<int> ed[MAXN];
int dp[1 << MAXK], S[1 << MAXK];
int lg[1 << MAXK], tlg[1 << MAXK];

void dfs(const int p, const int from) {
	int msk = 0, ban = 0;
	if (((int)ed[p].size() + (from == 0)) <= 1) {S[p] = 1; return;} 
	for (int q : ed[p]) if (q != from) {
		dfs(q, p), dp[p] = max(dp[p], dp[q]);
		msk |= ban & S[q], ban |= S[q];
	}
	msk = ((1 << 18) - (1 << lg[msk])) & ((1 << 18) - 1 - ban);
	int c = !msk ? lg[n] + 1 : tlg[msk & -msk];
	dp[p] = max(dp[p], c);
	S[p] = (ban & ((1 << 18) - (1 << c))) | (1 << c);
	return;
}

int main()
{
	freopen("labyrinth.in", "r", stdin);
	freopen("labyrinth.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for (int i = 2; i < (1 << 18); ++i) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i < 18; ++i) tlg[1 << i] = i;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			ed[i].clear();
			dp[i] = S[i] = 0;
		}
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		dfs(1, 0);
		cout << dp[1] + 1 << "\n";
	}
	return 0;
}