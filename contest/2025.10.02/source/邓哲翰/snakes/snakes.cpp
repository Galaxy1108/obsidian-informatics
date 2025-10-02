#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c, aa, bb, cc, aaa, bbb, ccc;

void s(){
	a = aaa;
	b = bbb;
	c = ccc;
	if (a < b){
		swap(a, b);
		swap(aa, bb);
	}
	if (a < c){
		swap(a, c);
		swap(aa, cc);
	}
	if (b < c){
		swap(b, c);
		swap(bb, cc);
	}
	if (a > b + c || (a == b + c && aa == 1)){
		cout << 1 << '\n';
		return ;
	}
	if (b > a + c || (b == a + c && bb == 1)){
		cout << 1 << '\n';
		return ;
	}
	if (c > a + b || (c == a + b && cc == 1)){
		cout << 1 << '\n';
		return ;
	}
	cout << 3 << '\n';
	return ;
}

int main(){
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin >> t;
	cin >> n;
	cin >> aaa >> bbb >> ccc;
	s();
	for (int i = 1; i < t; i++){
		int ttt1, ttt2;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> ttt1 >> ttt2;
			if (ttt1 == 1) aaa = ttt2;
			if (ttt1 == 2) bbb = ttt2;
			if (ttt1 == 3) ccc = ttt2;
		}
		s();
	}
	return 0;
} 
