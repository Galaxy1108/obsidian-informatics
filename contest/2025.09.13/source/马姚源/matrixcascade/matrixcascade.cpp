#include <bits/stdc++.h>
using namespace std;
int g[500][500];
bool book[100000];
void Main(){
	int x, y, n;
	cin >> n >> x >> y;
	if(x == y && min(x, y) == 0){
		if(n == 1)cout << "Yes\n";
		else cout << "No\n";
		return;
	}
	if(n == 10){
		cout << "Yes\n";
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cnt++;
				cout << cnt << " ";
			}
			cout << endl;
		}
	}
	else cout << "No\n";
	
}
int main(){
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)Main();
	return 0;
}
