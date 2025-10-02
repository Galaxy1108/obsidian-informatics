#include<bits/stdc++.h>
using namespace std;
int a[1000001];
double b[1000001], c[1000001];
bool willEat(int n){
	if(n == 2 || c[n] >= c[1] + c[2])return true;
	c[1] = c[n] - c[1];
	return !willEat(n - 1);
}
bool check(int n){
	for(int i = 1; i <= n; i++)c[i] = b[i];
	return willEat(n);
}
int solve(int n){
	int tmp;
	for(int i = 1; i <= n; i++)b[i] = a[i] + 0.000001 * i;
	while(n > 1){
		if(n == 2 || b[n] >= b[1] + b[2] || check(n)){
			tmp = b[1];
			for(int i = 2; i <= n; i++){
				if(b[i] + tmp <= b[n])b[i - 1] = b[i];
				else{
					b[i - 1] = b[n] - floor(tmp);
					break;
				}
			}
			n--;
		}else break;
	}
	return n;
}
int main(){
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int t, n, k, x, y;
	cin >> t >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	cout << solve(n) << "\n";
	while(--t){
		cin >> k;
		while(k--){
			cin >> x >> y;
			a[x] = y;
		}
		cout << solve(n) << "\n";
	}
	return 0;
}
