#include<bits/stdc++.h>
using namespace std;
bool mp[1001][1001];
int main(){
	freopen("corridor.in", "r", stdin);
	freopen("corridor.out", "w", stdout);
	int t, n, m, k, x, y, q, op, w;
	cin >> t >> n >> m >> k;
	while(k--){
		cin >> x >> y;
		mp[x][y] = true;
	}
	cin >> q;
	while(q--){
		cin >> op >> x >> y;
		if(op == 1)mp[x][y] = true;
		else{
			cin >> t;
			w = 0;
			if(x)w = 1;
			while(t){
				if(w)y++;
				else x++;
				if(x > n || y > m)break;
				if(mp[x][y]){
					w ^= 1;
					t--;
				}
			}
			cout << x << " " << y << "\n";
		}
	}
	return 0;
}
