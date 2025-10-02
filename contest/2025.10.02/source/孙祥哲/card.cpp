#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define lll __int128
#define N 1000005
using namespace std;

int rd(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
template<typename T>void write(T x){if(x<0)putchar('-'),write(-x);else{if(x>9)write(x/10);putchar(x%10+'0');}}

int n, m, q, a[N], b[N], x, y, op;
bool f[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = rd(), m = rd(), q = rd();
	for (int i = 1; i <= n; i++) b[i] = a[i] = rd()%2;
	while (m--) x = rd(), y = rd(), b[x] = y%2, f[x] = 1;
	while (q--)
	{
		op = rd(), x = rd();
		if (op == 1) b[x] = a[x], f[x] = 0;
		else y = rd(), b[x] = y%2, f[x] = 1;
//		for (int i = 1; i <= n; i++) cout << b[i] << "-"; puts(""); 
//		for (int i = 1; i <= n; i++) cout << f[i] << "-"; puts(""); 
		int c1 = 0, c2 = 0, res = 0;
		for (int i = 1; i <= n; i++) c1 += b[i]&&(!f[i]), c2 += f[i];
		for (int i = 1; i <= n; i++)
		{
			
		}
	}
	return 0;
} 
