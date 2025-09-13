#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 2000005
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int n, l, r, q, sum[maxn], fa[maxn], to[maxn];
char s[maxn];
inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
	n = read(), l = read(), r = read();
	scanf("%s", s + 1);
	int pos = 0;
	ru(i, 1, n) {
		fa[i] = i, sum[i] = sum[i - 1] + (s[i] == 'a');
		while(sum[pos] < sum[i] - r) pos++; 
		if(sum[pos] <= sum[i] - l) to[i] = pos + 1;
		for (int now = find(pos + 1); sum[now] <= sum[i] - l; now = find(now)) fa[now] = now + 1;
	}
	ru(i, 1, n) if(to[i]) {
		//printf("%d", to[i]); printf("\n");
		int x = find(to[i]);
		fa[find(i)] = x;
	}
	//ru(i, 1, n) {
	//	if(find(i) != i) printf("%d\n", i);
	//}
	q = read();
	while(q--) {
		int x = read(), y = read();
		if(find(x) == find(y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}