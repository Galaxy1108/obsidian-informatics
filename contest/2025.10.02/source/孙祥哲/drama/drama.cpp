#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define lll __int128
using namespace std;

int rd(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
template<typename T>void write(T x){if(x<0)putchar('-'),write(-x);else{if(x>9)write(x/10);putchar(x%10+'0');}}

int n, a[2000005];
lll ans;

signed main()
{
	freopen("drama.in", "r", stdin);
	freopen("drama.out", "w", stdout);
	n = rd();	
	for (int i = 1; i <= n; i++) a[i] = rd();
	for (int i = 1; i <= n; i++)
	{
		int l = 2e9, r = 0;
		for (int j = i; j >= 1; j--)
			l = min(l,a[j]), r = max(r,a[j]), ans = max(ans,(lll)l*r*(i-j+1));
	}
	write(ans);
	return 0;
} 
