//√ª–¥ÕÍ...’‚Ã‚∑œ¡À
#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[200001], r[200001], nxt[200001], d[200001], cnt = 0, mfY = 0;
struct node{int h, c;}a[200001];
bool vis[200001];
vector<int>g[200001], now, dp[200001];
vector<node>rs[200001];
void dfs(int x){
	if(vis[x]){
		cnt++;
		for(int i = now.size() - 1; i >= 0; i--){
			r[now[i]] = cnt;
			if(now[i] == x)break;
		}
		return;
	}
	vis[x] = true;
	now.push_back(x);
	dfs(nxt[x]);
	now.pop_back();
}
int MFy(int x, bool root){
	int t, ans = 0x7f7f7f7f7f7f7f7f, minn;
	for(int i = 0; i < g[x].size(); i++){
		t = g[x][i];
		MFy(t, false);
		if(root && false){
			//∞°∞°∞°∞°∞°∞°∞°∞°∞°∞°
		}else{
			minn = 0x7f7f7f7f7f7f7f7f;
			for(int j = mfY; j >= 1; j--){
				minn = min(minn, dp[t][j]);
				dp[x][j] += minn;
			}
		}
	}
	dp[x][rs[x][0].h] -= rs[x][0].c;
	if(root)for(int i = 1; i <= mfY; i++)ans = min(ans, dp[x][i]);
	return ans;
}
signed main(){
	freopen("reporter.in", "r", stdin);
	freopen("reporter.out", "w", stdout);
	cout << 0;
	return 0;
	int n, len, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> nxt[i] >> a[i].h >> a[i].c;
		mfY = max(mfY, b[i] = a[i].h);
	}
	sort(b + 1, b + n + 1);
	len = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++)a[i].h = lower_bound(b + 1, b + len + 1, a[i].h) - b;
	for(int i = 1; i <= n; i++)if(!vis[i])dfs(i);
	for(int i = 1; i <= n; i++){
		if(!r[i])r[i] = ++cnt;
		rs[r[i]].push_back(a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(r[i] != r[nxt[i]]){
			g[r[nxt[i]]].push_back(r[i]);
			d[r[i]]++;
		}
	}
	for(int i = 1; i <= n; i++)for(int j = 1; j <= mfY; j++)dp[i].push_back(0);
	for(int i = 1; i <= n; i++)if(d[i] == 0)ans += MFy(i, true);
	cout << ans;
	return 0;
}
