#include <bits/stdc++.h>
#define i28 __int128
using namespace std;

int n, a[2000005];

int main(){
	freopen("drama.in", "r", stdin);
	freopen("drama.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	i28 tm1, tm2, tm3, mx = 0;
	for (i28 i = 1; i < n; i++){
		tm1 = a[i];
		tm2 = a[i];
		for (i28 j = i + 1; j <= n; j++){
			if (a[j] > tm1) tm1 = a[j];
			if (a[j] < tm2) tm2 = a[j];
			tm3 = tm1 * tm2 * (j - i + 1);
			if (tm3 > mx) mx = tm3;
//			printf("%3d %3d %3d %3d %3d %3d\n", i, j, tm1, tm2, tm3, mx);
		}
	}
	string aaa;
	while (mx > 0){
		aaa = char(mx % 10 + '0') + aaa;
		mx /= 10;
	}
	cout << aaa;
	return 0;
} 
