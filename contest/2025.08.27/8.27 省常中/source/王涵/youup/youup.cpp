#include <cstdio>

int main()
{
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	int n;
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; printf("%d ", i++ == 1 ? n : 0));
}
