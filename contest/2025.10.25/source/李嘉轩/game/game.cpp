#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	bool sp = true;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1)sp = false;
	}
	if(sp){
		if(n & 1)cout << n;
		else cout << 0;
		return 0;
	}
	return 0;
}
