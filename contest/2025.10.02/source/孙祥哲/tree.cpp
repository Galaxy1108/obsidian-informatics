#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define lll __int128
#define N 1000005
using namespace std;

int rd(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
template<typename T>void write(T x){if(x<0)putchar('-'),write(-x);else{if(x>9)write(x/10);putchar(x%10+'0');}}

struct Node {int x,y;};
bool operator < (Node x, Node y) { return x.x==y.x?x.y<y.y:x.x<y.x; }

int T, n, a[N], b[N], ans;
bool eat[N];

void dfs(set<Node> s)
{
	Node x = *s.begin(), y = *(--s.end());
//	printf("(%d,%d)(%d,%d)\n",x.x,x.y,y.x,y.y);
	
}

void sol()
{
	set<Node> s;
	for (int i = 1; i <= n; i++) s.insert({a[i], i});
	if (n == 3)
	{
		if (a[3] >= a[1] + a[2]) puts("1");
		else puts("3");
		return;
	}
	for (int i = 1; i <= n; i++) eat[i] = 0;
	for (int i = 1; ;i++)
	{
		if (s.size() == 1) { puts("1"); return; }
		Node x = *s.begin(), y = *(--s.end());
		eat[y.y] = 1, b[y.y] = i;
//		printf("-----------\n(%d,%d)(%d,%d)\n",x.x,x.y,y.x,y.y);
//		for (int i = 1; i <= n; i++) cout << eat[i]; puts("");
//		for (int i = 1; i <= n; i++) cout << b[i] << " "; puts("\n----------");
		if (eat[x.y]) {  write(n-b[x.y]+1), putchar('\n'); return; }
		s.erase(s.begin()), s.erase(--s.end());
		y.x -= x.x,s.insert(y);
	}
}

signed main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	T = rd(), n = rd();
	for (int i = 1; i <= n; i++) a[i] = rd();
	sol();
	for (int i = 1; i < T; i++)
	{
		int k = rd(), x, y;
		while (k--) x = rd(), y = rd(), a[x] = y;
//		for (int j = 1; j <= n; j++) cout << a[j] << " "; puts("");
		sol();
	}
	return 0;
}
