#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define maxn 105
using namespace std;
int num, n, x, dis[maxn][maxn];
vector<int> G[maxn];
void dfs(int s, int x, int fa) {
	for (auto V: G[x]) if(V != fa) {
		dis[s][V] = dis[s][x] + 1;
		dfs(s, V, x);
	}
}
int ans[maxn], ok[1 << 21];
int main() {
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	scanf("%d%d%d", &num, &n, &x);
	ru(i, 1, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	ru(i, 1, n) dfs(i, i, 0);
	ok[0] = 1;
	ru(i, 1, (1 << n) - 1) {
		ru(j, 0, n - 1) if((i >> j) & 1) {
			ok[i] = ok[i ^ (1 << j)];
			ru(k, j, n - 1) if((i >> k) & 1) {
				ok[i] &= (dis[j + 1][k + 1] <= x);
			}
			break;
		}
		if(ok[i]) {
			int cnt = 0;
			ru(j, 0, n - 1) cnt += ((i >> j) & 1);
			ans[cnt]++;
		}
	}
	ru(i, 1, n) printf("%d ", ans[i]);
	return 0;
}