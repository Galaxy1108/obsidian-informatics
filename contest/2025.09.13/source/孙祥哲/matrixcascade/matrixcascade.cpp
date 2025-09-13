#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll read() {ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void write(const int& x) {if(x>9)write(x/10);putchar(x%10+'0');}

struct BIT
{
	int c[310*310],n;
	void clear(){memset(c,0,sizeof(c));}
	inline int lowbit(int x){return x&(-x);}
	void add(int u,int x)
	{
		for (int i=u;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int u)
	{
		int res=0;
		for (int i=u;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
}t;

int T, n, X, Y;
int c[305][305], vis[305*305], flag = 0;

bool check()
{
	t.clear(),t.n=n*n;ll s=0;
		for (int i=n;i>=1;i--)for (int j=n;j>=1;j--)
			s+=t.ask(c[i][j]),t.add(c[i][j],1);
		if (s!=X) return 0;

		s=0;t.clear();
		for (int i=n;i>=1;i--)for (int j=n;j>=1;j--)
			s+=t.ask(c[j][i]),t.add(c[j][i],1);
		if (s!=Y) return 0;
	return 1;
}

void dfs(int x, int y)
{
	int xx = x, yy = y+1;
	if (yy > n) xx++, yy = 1;
//	printf("(%d,%d)\n",x,y);
//	for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++) cout << vis[i*n+j-n];
//			cout << '\n';
//		}
//		puts("---------------------------");
	if (flag) return;
	if (x > n)
	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++) cout << c[i][j] << '-';
//			cout << '\n';
//		}
//		puts("---------------------------");
		if (check())
		{
			puts("YES");
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++) cout << c[i][j] << ' ';
				cout << '\n';
			}
			flag = 1;
		}
		return;
	}
	for (int i = 1; i <= n*n; i++) 
		if (!vis[i])
			vis[i] = 1, c[x][y] = i, dfs(xx, yy), vis[i] = 0;
}

int main()
{
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
	T = read();
	while (T--)
	{
		n = read(), X = read(), Y = read();
		if (n <= 3)
		{
			flag = 0, dfs(1, 1);
			if (!flag) puts("NO");
		}
		else if (x == 0)
		{
			
		}
		else if (y == 0)
		{
			
		}
		else
		{
			cout << "YES\n";
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++) cout << (i-1)*n+j << ' ';
				cout << '\n';
			}
		} 
	}
	return 0;
}
/*
5
3
6 7 8
*/
