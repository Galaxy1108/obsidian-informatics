//完了我没补上次的历史版本和T4
//没救了
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct operation{int l, r, x;}a[100001];
struct query{int u, d;}b[100001];
vector<operation>q[100001];
int n, t, cnt, vers, pos[100001], val[100001], sum[100001], ssum[100001];
int nxt(int x){
	if(x > 0)return q[x][++pos[x]].x;
	return 0;
}
signed main(){
	freopen("newfile.in", "r", stdin);
	freopen("newfile.out", "w", stdout);
	int m, Q, l, r;
	cin >> n >> m >> Q;
	for(int i = 1; i <= m; i++)cin >> a[i].l >> a[i].r >> a[i].x;
	for(int i = 1; i <= Q; i++){
		cin >> b[i].u >> b[i].d >> l >> r;
		q[b[i].d].push_back({l, r, 0});
		if(b[i].u > 1)q[b[i].u - 1].push_back({l, r, 0});
	}
	for(int i = 1; i <= m; i++){
		for(int j = a[i].l; j <= a[i].r; j++)val[j] += a[i].x;
		for(int j = 1; j <= n; j++)sum[j] += val[j];
		for(int j = 1; j <= n; j++)ssum[j] = ssum[j - 1] + sum[j];
		for(int j = 0; j < q[i].size(); j++)q[i][j].x = ssum[q[i][j].r] - ssum[q[i][j].l - 1];
	}
	memset(pos, -1, sizeof(pos));
	for(int i = 1; i <= Q; i++)cout << nxt(b[i].d) - nxt(b[i].u - 1) << "\n";
	return 0;
}
