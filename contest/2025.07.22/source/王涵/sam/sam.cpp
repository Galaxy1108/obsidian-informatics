#include <cstdio>
typedef long long intt;

const int R = 10, P = 1e9 + 7;

namespace solve
{
inline void md(int& x)
{
	x -= (x >= P) * P;
}

struct matrix
{
	int m[R][R];
	
	static matrix I;
	
	matrix operator* (matrix oth)
	{
		matrix ret = {};
		for (int i = 0; i < R; i++)
		{
			for (int k = 0; k < R; k++)
			{
				for (int j = 0; j < R; j++)
				{
					md(ret.m[i][j] += (intt)m[i][k] * oth.m[k][j] % P);
				}
			}
		}
		return ret;
	}
	
	static void init()
	{
		for (int i = 0; i < R; i++)
			I.m[i][i] = 1;
	}
};

matrix matrix::I;

matrix tr()
{
	matrix ret = {};
	for (int i = 0; i < R; i++)
	{
		for (int j = -2; j <= 2; j++)
		{
			if (0 <= i + j and i + j < R)
				ret.m[i + j][i] = 1;
		}
	}
	return ret;
}

matrix qpow(matrix a, intt p)
{
	matrix ret = matrix::I;
	while (p)
	{
		if (p & 1)
		{
			ret = ret * a;
		}
		a = a * a;
		p >>= 1;
	}
	return ret;
}

int solve(intt n)
{
	matrix::init();
	matrix m = (matrix){{{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }}} * qpow(tr(), n - 1);
	int ret = 0;
	for (int i = 1; i < R; i++)
		md(ret += m.m[0][i]);
	return ret;
}
}

int main()
{
	freopen("sam.in", "r", stdin);
	freopen("sam.out", "w", stdout);
	intt n;
	scanf("%lld", &n);
	printf("%d", solve::solve(n));
}
