#include<bits/stdc++.h>
using namespace std;
int lg[2000001], l[2000001], r[2000001], st[21][2000001], s[2000001];
__int128 query(int l, int r){
	int len = lg[r - l + 1];
	return (__int128)max(st[len][l], st[len][r - (1 << len) + 1]);
}
int qread(){
	int x;
	char c = 0;
	while(c < '0' || c > '9')c = getchar();
	x = c - '0';
	while(1){
		c = getchar();
		if(c < '0' || c > '9')break;
		x = (x << 3) + (x << 1) + c - '0';
	}
	return x;
}
int main(){
	freopen("drama.in", "r", stdin);
	freopen("drama.out", "w", stdout);
	int n, len = 0;
	string res = "";
	__int128 maxn = 0;
	cin >> n;
	lg[0] = -1;
	for(int i = 1; i <= n; i++){
		st[0][i] = qread();
		lg[i] = lg[i >> 1] + 1;
		l[i] = 1;
		r[i] = n;
	}
	for(int i = 1; i <= 20; i++){
		for(register int j = 1; j <= n; j++){
			st[i][j] = st[i - 1][j];
			if(j + (1 << i - 1) <= n)st[i][j] = max(st[i][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	for(int i = 1; i <= n; i++){
		while(len && st[0][s[len]] > st[0][i]){
			r[s[len]] = i - 1;
			len--;
		}
		s[++len] = i;
	}
	len = 0;
	for(int i = n; i >= 1; i--){
		while(len && st[0][s[len]] > st[0][i]){
			l[s[len]] = i + 1;
			len--;
		}
		s[++len] = i;
	}
	for(int i = 1; i <= n; i++){
		maxn = max(maxn, (__int128)(st[0][i]) * (__int128)(r[i] - l[i] + 1) * query(l[i], r[i]));
	}
	while(maxn){
		res += (maxn % 10 + '0');
		maxn /= 10;
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
