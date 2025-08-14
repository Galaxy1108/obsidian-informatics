#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	int t, p, b;
	cin >> t >> p;
	while(t--){
		cin >> b;
		if(p == 1)cout << "1\n";
		else if(p == 2){
			if(b & 1)cout << "1\n";
			else cout << "-1\n";
		}else cout << "-1\n";
	}
	return 0;
}
