#include <bits/stdc++.h>
#define reg register int
#define il inline
#define fi first
#define se second
#define mk(a,b) make_pair(a,b)
#define numb (ch^'0')
#define pb push_back
#define solid const auto &
#define enter cout<<endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;

template<class T>il void rd(T &x) {
	char ch;
	x = 0;
	bool fl = false;
	while (!isdigit(ch = getchar()))
		(ch == '-') && (fl = true);
	for (x = numb; isdigit(ch = getchar()); x = x * 10 + numb);
	(fl == true) &&(x = -x);
}

template<class T>il void output(T x) {
	if (x / 10)
		output(x / 10);
	putchar(x % 10 + '0');
}

template<class T>il void ot(T x) {
	if (x < 0)
		putchar('-'), x = -x;
	output(x);
	putchar(' ');
}

template<class T>il void prt(T a[], int st, int nd) {
	for (reg i = st; i <= nd; ++i)
		ot(a[i]);
	putchar('\n');
}

namespace Miracle {
	const int N = 100000 + 5;
	const int M = 500000 + 5;
	int n, m;
	struct node {
		int a, b, w;
		bool friend operator <(node a, node b) {
			return a.w < b.w;
		}
	} e[M];
	int fa[N], sz[N], mx[N];
	int z[N];
	int fin(int x) {
		return fa[x] == x ? x : fa[x] = fin(fa[x]);
	}
	vector<int>mem[N];
	int main() {
		rd(n);
		rd(m);
		for (reg i = 1; i <= n; ++i)
			rd(z[i]);
		for (reg i = 1; i <= m; ++i) {
			rd(e[i].a);
			rd(e[i].b);
			rd(e[i].w);
		}
		sort(e + 1, e + m + 1);
		for (reg i = 1; i <= n; ++i) {
			fa[i] = i;
			sz[i] = 1;
		}
		for (reg i = 1; i <= m; ++i) {
			int x = e[i].a, y = e[i].b;
			int k1 = fin(x), k2 = fin(y);
			if (k1 != k2) {
				if (e[i].w <= min(mx[k1] + z[sz[k1]], mx[k2] + z[sz[k2]])) {
					fa[k1] = k2;
					sz[k2] += sz[k1];
					mx[k2] = e[i].w;
				}
			}
		}
		int cnt = 0;
		for (reg i = 1; i <= n; ++i) {
			int k = fin(i);
			if (!mem[k].size())
				++cnt;
			mem[k].push_back(i);
		}
		printf("%d\n", cnt);
		for (reg i = 1; i <= n; ++i) {
			if (mem[i].size()) {
				printf("%d ", mem[i].size());
				for (reg j = 0; j < (int)mem[i].size(); ++j) {
					printf("%d ", mem[i][j]);
				}
				puts("");
			}
		}
		return 0;
	}

}

signed main() {
	freopen("shattersong.in", "r", stdin);
	freopen("shattersong.out", "w", stdout);
	Miracle::main();
	return 0;
}
