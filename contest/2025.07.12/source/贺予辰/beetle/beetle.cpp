#include<bits/stdc++.h>
#define int long long
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
using namespace std;
const int lzj = 1e9 + 7; 
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const int lzj = 1e9 + 7;
int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a = a * a % lzj)
		if (b & 1) ans = ans * a % lzj;
	return ans;
}
int write(int n) {
	if (n < 0) putchar('-'), n = -n;
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int n, k, s[1000006], f[1000006], ans = 0, mx[1000006];
signed main() {
	freopen("beetle.in", "r", stdin);
	freopen("beetle.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= k; ++i) s[i] = read(), f[i] = max(s[i], f[i - 1]);
	for (int i = k + 1; i <= n; ++i) {
		s[i] = read(), mx[i] = s[i], f[i] = 1e18;
		for (int j = i - 1; j > i - k; --j) mx[i] = max(mx[j + 1], s[j]);
		for (int j = i - k + 1; j < i; ++j) f[i] = min(f[i], f[j] + mx[j]);
	}
	for (int i = 1; i <= n; ++i) {
		ans = (ans + f[i] * qpow(23, n - i) % lzj ) % lzj;
	}
	cout << ans << endl;
	return 0;
}
