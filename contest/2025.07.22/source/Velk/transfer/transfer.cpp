#include <cstdio>

const int MX = 1000010;

char s[MX << 1];

int main()
{
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	int n, cnt = 0;
	scanf("%d%*d%s", &n, s + 1);
	for (int i = 2; i <= n << 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (s[j] == 'B' and s[i] == 'A')
				cnt++;
		}
	}
	printf("%d", cnt);
}
