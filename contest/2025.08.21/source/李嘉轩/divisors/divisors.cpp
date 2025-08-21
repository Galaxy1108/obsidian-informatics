#include<bits/stdc++.h>
using namespace std;
int val[2501];
int main(){
	freopen("divisors.in", "r", stdin);
	freopen("divisors.out", "w", stdout);
	int n;
	cin >> n;
	val[0] = val[n] = 1;
	for(int i = 1; i < n; i++){
		if(i & 1)val[i] = n - (i >> 1);
		else val[i] = (i >> 1) + 1;
	}
	for(int i = 1; i <= n; i++)cout << val[i - 1] * val[i] << " ";
	cout << "\n";
	for(int i = 1; i < n; i++)cout << i << " " << i + 1 << "\n";
	return 0;
}
