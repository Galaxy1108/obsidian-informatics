#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	int t, s, k;
	cin >> t;
	while(t--){
		cin >> s >> k;
		if(s < (k << 1))cout << "-1\n";
		else cout << (k << 1) << "\n";
	}
	return 0;
}
