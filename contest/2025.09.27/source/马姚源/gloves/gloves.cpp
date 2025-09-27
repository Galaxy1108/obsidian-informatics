#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];int n, m;
bool check(int x){
	int r = 1;
	for(int i = 1; i <= n; i++){
		while(r <= m && b[r] < a[i] - x)r++;
		if(r > m || b[r] > a[i] + x)return 0;
		r++;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("gloves.in", "r", stdin);
	freopen("gloves.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= m; i++)cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	if(n == m){
		int ans = 0;
		for(int i = 1; i <= m ;i ++){
			ans = max(ans, abs(a[i] - b[i]));
		}
		cout << ans;
		return 0;
	}
	if(m < n){
		for(int i = 1; i <= n; i++)swap(a[i], b[i]);
		swap(n, m);
	}
	int l = 0, r = 1e9; 
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else l = mid + 1;
	}
	cout << l ;
	return 0;
}
