#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e6 + 9, mod = 998244353;
int n, k;
int phi[N], f[N], ans[N];
bool pr[N];
inline void init(int nn) 
{
	f[k + 1] = k + 1; 
	for (int i = k + 2; i <= nn; i++) f[i] = (f[i - 1] + f[i - k - 1] + 1) % mod;
	for (int i = 1; i <= nn; i++) phi[i] = i;
	for (int i = 2; i <= nn; i++) 
		if(!pr[i])
			for (int j = i; j <= nn; j += i) phi[j] = phi[j] / i * (i - 1), pr[j] = 1;
	for (int i = 1; i <= nn; i++) 
		for (int j = i; j <= nn; j += i) ans[j] = (ans[j] + phi[j / i] * f[i]) % mod;
	return ;
}
inline int Pow(int x, int y) 
{
	int res = 1, base = x;
	while(y) 
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
signed main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	k = read(); init(1e6);
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) 
	{
		n = read(); 
		if(n < k) while(1);
		printf("%lld %lld\n", f[n], ans[n] * Pow(n, mod - 2) % mod);
	}
	return 0;
}
