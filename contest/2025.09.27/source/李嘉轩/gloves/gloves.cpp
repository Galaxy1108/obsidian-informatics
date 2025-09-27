#include<bits/stdc++.h>
using namespace std;
int n, m, a[100001], b[100001];
bool check(int x){
	int t = 0, sc;
	for(int i = 1; i <= n; i++){
		sc = lower_bound(b + t + 1, b + m + 1, a[i] - x) - b;
		if(sc > m || b[sc] > a[i] + x)return false;
		t = sc;
	}
	return true;
}
int main(){
	freopen("gloves.in", "r", stdin);
	freopen("gloves.out", "w", stdout);
	int t = 0, sc, l = 0, r = 1000000000, mid;
	cin >> n >> m;
	if(n > m){
		for(int i = 1; i <= n; i++)cin >> b[i];
		for(int i = 1; i <= m; i++)cin >> a[i];
		swap(n, m);
	}else{
		for(int i = 1; i <= n; i++)cin >> a[i];
		for(int i = 1; i <= m; i++)cin >> b[i];
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid))r = mid;
		else l = mid + 1;
	}
	cout << r;
	return 0;
}
