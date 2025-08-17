//乱加了点东西就过了,你猜为什么呢
//1.7s
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, s1, s2;
int getRand(){
	int s3 = s1, s4 = s2;
	s1 = s2 ^ 774527;
	s3 ^= (s3 << 47) ^ (s3 >> 13);
	s2 ^= s3 ^ (s4 << 31) ^ (s4 >> 17);
	return s2 + s4;
}
void get_query(int &op, int &num1, int &num2){
    op = getRand() % 2 + 1;
    num1 = getRand() % n + 1;
    num2 = getRand() % n + 1;
    if(op == 2 && num1 > num2)swap(num1, num2);
}
int c[10000001];
int lowbit(int x){return x & (-x);}
void add(int x, int k){
	int cnt = 0;
	for(; x <= n; x += lowbit(x))c[x] += k * (++cnt);
}
int query(int x){
	int ans = 0;
	for(; x; x -= lowbit(x))ans += c[x];
	return ans;
}
signed main(){
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);
	int q, op, x, y, ans = 0;
	cin >> n >> q >> s1 >> s2;
	for(int i = 1; i <= q; i++){
		get_query(op, x, y);
		if(op == 1)add(x, y);
		else ans ^= (i * (query(y) - query(x - 1)));
	}
	cout << ans;
	return 0;
}
