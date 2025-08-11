#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[21]; 
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t, n, m, x, y, ans;
	cin >> t;
	while(t--){
		cin >> n >> m;
		ans = -0x7f7f7f7f7f7f7f7f;
		for(int i = 1; i <= m; i++)cin >> a[i];
		for(int i = 0; i < (n == 1 ? 1 : (1 << m)); i++){
			x = y = 0;
			for(int j = 1; j <= m; j++){
				if(i & (1 << (j - 1)))x = a[j] - x;
				else y = a[j] - y;
			}
			ans = max(ans, x + y);
		}
		cout << ans << "\n";
	}
	return 0;
}
