#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	int n, m, p;
	unsigned ans = 1;
	cin >> n >> m >> p;
	assert(n >= m);
	for(int i = 1; i <= m; i++)ans = (ans << 2) % p;
	cout << ans;
	return 0;
} 
