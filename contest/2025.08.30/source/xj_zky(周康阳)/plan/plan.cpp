#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size()) 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 507, M = 250;
int n, k, a[N];

vi vc[N];

int *dp[N][M];
int cur[N], siz[N], mn[N];

vi getfac(int n) {
	vi qwq;
	L(i, 1, sqrt(n)) if(n % i == 0) {
		int t = n / i;
		qwq.emplace_back(i);
		if(i != t) qwq.emplace_back(t);
	}
	return qwq;
}

vi e[N];


int sav[N];
void muti(int *a, int *b, int sx, int sy) {
	me(sav, -0x3f);
	L(i, 0, sx) L(j, 0, sy) 
		sav[i + j] = max(sav[i + j], a[i] + b[j]);
}

void dfs(int x, int f) {
	vc[x] = getfac(a[x]);
	
	int sall = 1;
	for(const int &v : e[x]) if(v != f) 
		dfs(v, x), sall += siz[v];
	L(i, 0, sz(vc[x])) {
		dp[x][i] = new int [sall + 2];
		L(j, 0, sall + 1) 
			dp[x][i][j] = -1e9;
	}
	L(i, 1, sz(vc[x])) 
		dp[x][i][0] = 0;
	
	siz[x] = 1;
	for(const int &v : e[x]) if(v != f) {
		L(i, 1, sz(vc[x])) {
			int p = 0;
			L(j, 1, sz(vc[v])) if(vc[x][i - 1] == vc[v][j - 1]) p = j;
			muti(dp[x][i], dp[v][p], siz[x], siz[v]);
			L(j, 0, siz[x] + siz[v]) 
				dp[x][i][j] = sav[j];
		}
		siz[x] += siz[v];
	}
	
	L(i, 1, sz(vc[x])) L(j, 0, siz[x]) dp[x][0][j + 1] = max(dp[x][0][j + 1], dp[x][i][j] + vc[x][i - 1]);
	L(i, 1, sz(vc[x])) L(j, 0, siz[x]) dp[x][i][j] = max(dp[x][i][j], dp[x][0][j]);
}

int main() {
//	return system("fc plan.out plan6.out"), 0;
	freopen("plan.in", "r", stdin); 
	freopen("plan.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	L(i, 1, n) 
		cin >> a[i];
	dfs(1, 0);
	cout << dp[1][0][k + 1] << '\n';
	return 0;
}