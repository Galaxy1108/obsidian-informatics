#include <bits/stdc++.h>
#define N 2005
#define INF 0x7fffffff
#define ll long long
using namespace std;
inline int read(){
	char ch = getchar(); int x = 0, f = 1;
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
int n, ut, vt, mn;
int w[N][N], d[N][N], dis[N][N], cnt[N][N], son[N];
typedef pair<int, int> pll;
priority_queue<pll, vector<pll>, greater<pll>> q;
bitset<N> vis;

void bfs(int x){
	for(int i = 1; i <= n; i++) d[x][i] = INF, vis[i] = 0;
	q.push({d[x][x], x});
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 1; i <= n; i++){
			if(vis[i]) continue;
			if(d[x][i] > min(d[x][u], w[u][i])){
				d[x][i] = min(d[x][u], w[u][i]);
				dis[x][i] = dis[x][u] + d[x][i];
				cnt[x][i] = cnt[x][u] + 1;
				q.push({d[x][i], i});
			}
		}
	}
}

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	n = read();
	mn = INF;
	memset(w, 0x7f, sizeof w);
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			w[i][j] = w[j][i] = read();
			if(w[i][j] < mn) mn = w[i][j], ut = i, vt = j;
		}
	}
	for(int i = 1; i <= n; i++){
		ll ans = 0;
		if(i == ut || i == vt) ans = 1ll * mn * (n - 1);
		else{
			bfs(i);
			ans = dis[i][ut] + 1ll * mn * (n - 1 - cnt[i][ut]);
			ans = min(ans, dis[i][vt] + 1ll * mn * (n - 1 - cnt[i][vt]));
//			bfs(i);
//			for(int j = 1; j <= n; j++) if(j ^ i) ans += d[i][j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
