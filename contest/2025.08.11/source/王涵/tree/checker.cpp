#include <cstdio>
#define abs(x) (x < 0 ? -(x) : x)

const int MX = 500010;

double ans[MX];

int main()
{
	freopen("tree.out", "r", stdin);
	int pt = 0;
	while (~scanf("%lf", ans + ++pt));
	pt = 0;
	double x;
	freopen("tree.ans", "r", stdin);
	while (~scanf("%lf", &x))
	{
		pt++;
		if (abs(ans[pt] - x) > 1e-6)
			return 1;
	}
	return 0;
}
