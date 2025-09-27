#include <bits/stdc++.h>
#define lc (p << 1)
#define rc (p << 1 | 1)
#define mid (l + r >> 1)
using namespace std;
const int N = 1e5 + 10;
int maxx[N << 2], sum[N << 2], a[N];
void up(int p){
	maxx[p] = max(maxx[lc], maxx[rc]);
	sum[p] = sum[lc] ^ sum[rc];
}
void build(int p, int l, int r){
	if(l == r){
		maxx[p] = sum[p] = a[l];
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	up(p);
}
int query_sum(int p, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr)return sum[p];
	int res = 0;
	if(ql <= mid)res ^= query_sum(lc, l, mid, ql, qr);
	if(qr > mid)res ^= query_sum(rc, mid + 1, r, ql, qr);
	return res;
}
int query_max(int p, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr)return maxx[p];
	int res = 0;
	if(ql <= mid)res = max(query_max(lc, l, mid, ql, qr), res);
	if(qr > mid)res = max(res, query_max(rc, mid + 1, r, ql, qr));
	return res;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(query_sum(1, 1, n, i, j) <= query_max(1, 1, n, i, j)){
//				cout << i << j <<endl;
				 ans++;
			}
		}
	}
	cout << ans; 
	return 0;
}

