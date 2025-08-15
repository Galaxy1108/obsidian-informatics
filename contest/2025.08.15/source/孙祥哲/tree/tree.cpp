#include <bits/stdc++.h>
using namespace std;

void read(int &n)
{
	int x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	n=x;
}
void read(long long &n)
{
	int x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	n=x;
}

const int mod = 1e9+9;
int n, m, q;
long long f[5005][5005], s[5005][5005];

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    read(n), read(m), read(q);
   	for (int i = 1; i <= m; i++)
    {
    	int l, r;
		long long x;
    	read(l), read(r), read(x);
    	if (l > r) swap(l, r);
    	for (int j = 1; j <= n; j++) f[i][j] = (f[i-1][j] + (j>=l&&j<=r ? x : 0)) % mod;
    	for (int j = 1; j <= n; j++) s[i][j] = (s[i][j-1]+f[i][j]) % mod;
	}
	for (int i = 1; i <= q; i++)
	{
		int u, d, l, r;
		long long sum = 0;
    	if (u > d) swap(u, d);
    	if (l > r) swap(l, r);
		read(u), read(d), read(l), read(r);
		for (int j = u; j <= d; j++) sum = (sum+s[j][r]-s[j][l-1])%mod;
		printf("%d\n", (sum+2ll*mod)%mod);
	}
    return 0;
}

