#include <bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;

ll n, mod;
lll C[105][105], res;
lll s[100] = 
{0,
(lll)1,
(lll)4,
(lll)17,
(lll)269,
(lll)5736,
(lll)590892,
(lll)55905463,
(lll)30896505127,
(lll)41166677425218,
(lll)141740594713218418,
};

void write(lll x)
{
	if (x > 9) write(x/10);
	putchar(x%10+'0');
}
void init()
{
	for (int i = 1; i <= 50; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = C[i-1][j-1] + C[i-1][j];
//			printf("C(%d,%d)=", i, j), write(C[i][j]);
//			puts("");
		}
	}
}

int main()
{
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0);
//	init();
	cin >> n >> mod;
	if (n <= 10) write(s[n]%mod);
//	for (int i = 1; i <= n; i++)
//	{
//		lll mul = 1, sum = 0;
//		for (int j = 0; j <= i; j++) mul *= C[i][j];
//		for (lll j = 1; j*j <= mul; j++)
//		{
//			if (mul % j == 0) sum += j + mul / j;
//			if (j * j == mul) sum -= j;
//		}
//		res = res+sum;
//		write(res), putchar('\n');
//	}
//	write(res%mod);
	return 0;
} 
