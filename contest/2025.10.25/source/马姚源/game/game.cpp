#include <bits/stdc++.h>
using namespace std;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n & 1){
		cout << n << endl;
	}
	else cout << 0; 
	return 0;
}
