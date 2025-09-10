#include <bits/stdc++.h>
using namespace std;
int F(int x){
	if(x == 0)return 0;
	int res = 1;
	while(x > 0){
		res *= (x % 10);
		x /= 10;
	}
	
	return res;
}
int g[5005][5005];
int Qsort[10000005], si;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	int n, k;
	cin >> n >> k;
//	cout << F(k) << endl; 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j]++;
			int i1 = F(i), i2 = F(j);
			g[i1][i2]++;
			g[i][j]--;
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(g[i][j])Qsort[++si] = g[i][j];
//			cout << g[i][j] << " ";
		} 
//		cout << endl;
	} 
	sort(Qsort + 1, Qsort + si + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= k; i++)ans += Qsort[i];
//	 cout << Qsort[i] << " ";
	cout << ans;
	return 0;
}
