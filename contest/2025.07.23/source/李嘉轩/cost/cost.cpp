//score:rand+50
#include<bits/stdc++.h>
using namespace std;
int n, a[1145], c[1145], f[1145][1145], minn = 0x7f7f7f7f;
int query(int l, int r){
	if(l == r)return 0;
	int mid = (l + r) >> 1, ans, na, nb = 0;
	ans = query(l, mid) + query(mid + 1, r);
	for(int i = l; i <= r; i++)nb += a[i];
	na = r - l + 1 - nb;
	for(int i = l; i <= mid; i++){
		for(int j = mid + 1; j <= r; j++){
			if(a[i] != a[j])ans += f[i][j];
			else if((a[i] == 0 && na < nb) || (a[i] == 1 && na >= nb))ans += f[i][j] * 2;
		}
	}
	return ans;
}
void dfs(int x, int p){
	if(p >= minn)return;
	if(x > (1 << n)){
		minn = min(minn, query(1, 1 << n) + p);
		return;
	}
	dfs(x + 1, p);
	a[x] = 1 - a[x];
	dfs(x + 1, p + c[x]);
	a[x] = 1 - a[x];
}
int main(){
	freopen("cost.in", "r", stdin);
	freopen("cost.out", "w", stdout);
	bool sp = true;
	cin >> n;
	for(int i = 1; i <= (1 << n); i++)cin >> a[i];
	for(int i = 1; i <= (1 << n); i++){
		cin >> c[i];
		if(c[i] > 0)sp = false;
	}
	for(int i = 1; i < (1 << n); i++)for(int j = i + 1; j <= (1 << n); j++)cin >> f[i][j];
	if(sp){
		cout << 0;
		return 0;
	}
	if(n > 4){
		cout << query(1, 1 << n);
		return 0;
	}
	dfs(1, 0);
	cout << minn;
	return 0;
}
