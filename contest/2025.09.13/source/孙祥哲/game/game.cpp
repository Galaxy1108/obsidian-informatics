#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll read() {ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void write(const int& x) {if(x>9)write(x/10);putchar(x%10+'0');}

int T, n, k;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	k = read(), T = read();
	while (T--)
	{
		n = read();
		if (k == n) printf("0 0\n");
		else if (k > n/2) write(n), printf(" 1\n");
	}
	return 0;
}
/*
5
3
6 7 8
*/
