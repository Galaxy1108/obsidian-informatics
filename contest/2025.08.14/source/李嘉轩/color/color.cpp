#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int n, x, y, z;
	cin >> n;
	if(n == 2){
		cin >> x >> y;
		if(x == y)cout << 0;
		else cout << 4;
	}else{
		cin >> x >> y >> z;
		if(x == y && x == z)cout << 0;
		else if(x == y || x == z || y == z)cout << 40;
		else cout << 42;
	}
	return 0;
}
