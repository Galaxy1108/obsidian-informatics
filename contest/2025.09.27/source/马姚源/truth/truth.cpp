#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int b[31], a[N];
int main(){
	freopen("truth.in", "r", stdin);
	freopen("truth.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, K, m;
	cin >> n >> K >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= m; i++){
		int op;
		cin >> op;
		if(op == 1){
			int p, v;
			cin >> p >> v;
			a[p] = v;
		}
		if(op == 2){
			int fl = 2e9;
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					memset(b, 0, sizeof(b));
					for(int k = i; k <= j; k ++){
						b[a[k]]++;
					}
					int cnt = 0;
					for(int k = 1; k <= K; k++)
						if(b[k] > 0)cnt++;
					if(cnt >= K){
						fl = min(j - i + 1, fl);
//						cout << endl;
						break;
					}
				}
//				
			}
			if(!fl)cout << "-1\n";
			else cout << fl << endl;
		}
	}
	return 0;
}

