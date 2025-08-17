#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001], fa[500001][21], dist[500001][21], dep[500001], maxn, now;
int dis(int x, int y){
	int ans = 0;
	if(dep[x] < dep[y])swap(x, y);
	for(int i = 20; i >= 0; i--){
		if(dep[x] - (1 << i) >= dep[y]){
			ans += dist[x][i];
			x = fa[x][i];
		}
	}
	if(x == y)return ans;
	for(int i = 20; i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			ans += dist[x][i] + dist[y][i];
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return ans + dist[x][0] + dist[y][0];
}
vector<int>g[500001];
void dfs(int x, int t, int sum){
	maxn = max(maxn, dis(x, now) + t);
	sum += a[x];
	t += sum;
	for(int i = 0; i < g[x].size(); i++)dfs(g[x][i], t, sum);
}
signed main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n, x;
	cin >> n;
	dep[1] = 1;
	for(int i = 2; i <= n; i++){
		cin >> fa[i][0];
		dep[i] = dep[fa[i][0]] + 1;
	}
	for(int i = 2; i <= n; i++)cin >> dist[i][0];
	for(int i = 2; i <= n; i++){
		cin >> x;
		g[x].push_back(i);
	}
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= n; j++){
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
			dist[j][i] = dist[j][i - 1] + dist[fa[j][i - 1]][i - 1];
		}
	}
	for(now = 1; now <= n; now++){
		maxn = 0;
		dfs(now, 0, 0);
		cout << maxn << " ";
	}
	return 0;
}
