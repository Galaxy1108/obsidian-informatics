#include<bits/stdc++.h>
using namespace std;
int a[100001], p[2], pre[100001][2], nxt[100001][2];
int main(){
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n, m, op, l, r, cnt;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i][0] = p[0];
		pre[i][1] = p[1];
		p[a[i]] = i;
	}
	p[0] = p[1] = n + 1;
	for(int i = n; i >= 1; i--){
		nxt[i][0] = p[0];
		nxt[i][1] = p[1];
		p[a[i]] = i;
	}
	cin >> m;
	while(m--){
		cin >> op >> l;
		if(op == 1){
			
		}else{
			cin >> r;
			cnt = 0;
			
		}
	}
	return 0;
}
