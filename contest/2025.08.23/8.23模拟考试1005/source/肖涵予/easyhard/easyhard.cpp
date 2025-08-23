#include <bits/stdc++.h>
using namespace std;
int n, m, p;
vector <int> res;
map <vector <int>, bool> mp;
void dfs(int step, int a, int b) {
	if (step > m) {
		mp[res] = true;
		return ;
	}
	if (a) {
		res.push_back(1), res.push_back(1);
		dfs(step + 1, a - 1, b + 1);
		res.pop_back(), res.push_back(0);
		dfs(step + 1, a, b);
		res.pop_back(), res.pop_back();
	}
	if (b) {
		res.push_back(0), res.push_back(1);
		dfs(step + 1, a, b);
		res.pop_back(), res.push_back(0);
		dfs(step + 1, a + 1, b - 1);
		res.pop_back(), res.pop_back();
	}
	return ;
}
int main(void) {
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &p);
	for (int a = 0; a <= n; ++a)
		dfs(1, a, n - a);
	printf("%d", mp.size());
	return 0;
}
