#include <cstdio>
#define max(A, B) (A < B ? B : A)
typedef long long intt;

namespace solve
{
intt lower(intt& n, intt a, intt b, intt c)
{
	intt l = 0, r = n, mid;
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		if (mid + max(((__int128)a * mid + b) / c, 0) <= n)
			l = mid;
		else
			r = mid - 1;
	}
	n -= l + max(((__int128)a * l + b) / c, 0);
	return l;
}

intt euclid(intt n, intt a, intt b, intt c, intt U, intt R)
{
	intt ret = 0;
	if (b < 0 and n)
		ret += U * ((a + b) / c) + R,
		n--,
		(b += a) %= c;
	else if (b < 0 and not n)
		return 0;
	
	ret += U * (b / c);
	b %= c;
	R = U * (a / c) + R;
	a %= c;
	
	if (not n)
		return ret;
	else if (not (((__int128)a * n + b) / c))
		return ret + R * n;
	else
		return ret + euclid(((__int128)a * n + b) / c, c, -b - 1, a, R, U) + R * (((__int128)a * n + b) % c / a + 1);
}

intt solve(intt n, intt s, intt t, intt x, intt y)
{
	if (s < t)
	{
		if (n <= (t - s + y - 1) / y)
			return s + n * y;
		else
			n -= (t - s + y - 1) / y,
			s += (t - s + y - 1) / y * y;
	}
	intt r = lower(n, y, x - y + s - t, x);
	return s + euclid(r, y, x - y + s - t, x, -x, y) - n * x;
}
}

int main()
{
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout);
	int tt;
	intt n, s, t, x, y;
	scanf("%d", &tt);
	while (tt--)
	{
		scanf("%lld%lld%lld%lld%lld", &n, &s, &t, &x, &y);
		printf("%lld\n", solve::solve(n, s, t, x, y));
	}
}
