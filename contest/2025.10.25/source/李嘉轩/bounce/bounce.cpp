#include<bits/stdc++.h>
using namespace std;
bool d[1000001];
int ans[21], nxt[1000002], pre[1000002];
int get(int n, int m){
	for(int i = 1; i <= n; i++){
		nxt[i] = i + 1;
		pre[i] = i - 1;
	}
	nxt[0] = 1;
	pre[n + 1] = n;
	int pos = 0, dir, cnt;
	while(nxt[0] != pre[n + 1]){
		if(pos == 0){
			dir = 1;
			pos = nxt[0];
		}else if(pos == n + 1){
			dir = 0;
			pos = pre[n + 1];
		}else{
			for(int i = 1; i <= m; i++){
				if(dir)pos = nxt[pos];
				else pos = pre[pos];
				if(pos == 0 || pos == n + 1)break;
			}
		}
		if(pos >= 1 && pos <= n){
			pre[nxt[pos]] = pre[pos];
			nxt[pre[pos]] = nxt[pos];
		}
	}
	return nxt[0];
}
int main(){
	freopen("bounce.in", "r", stdin);
	freopen("bounce.out", "w", stdout);
	int n, q, op, m, l, cnt;
	bool sp = true;
	cin >> n >> q;
	l = n;
	for(int i = 2; i <= 20; i++)ans[i] = get(n, i);
	while(q--){
		cin >> op >> m;
		if(op <= 2)sp = false;
		if(op == 1){
			for(int i = 1; i <= n; i += m){
				if(!d[i]){
					d[i] = true;
					l--;
				}
			}
		}else if(op == 2){
			cnt = 0;
			for(int i = 1; i <= n; i++){
				if(!d[i] && (++cnt) % m == 1){
					d[i] = true;
					l--;
				}
			}
		}else{
			if(sp)cout << ans[m] << "\n";
			else{
				if(l == 0)cout << "-1\n";
				else{
					cnt = get(l, m);
					for(int i = 1; i <= n; i++){
						if(!d[i] && (--cnt) == 0){
							cout << i << "\n";
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
