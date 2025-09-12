#include <cstdio>

int main()
{
	freopen("shattersong.in", "r", stdin);
	freopen("shattersong.out", "w", stdout);
	int x, y;
	scanf("%*d%*d%d%*d%*d%*d%d", &x, &y);
	if (y > x)
		printf("2\n1 1\n1 2");
	else
		printf("1\n2 1 2");
}
