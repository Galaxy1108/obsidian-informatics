#include <cstdio>
#include <algorithm>
#include <ctime>

const int N = 10, MX = N + 5;

void write(int x)
{
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

struct perm
{
	int p[MX], id;
	
	bool eq(const perm& oth)
	{
		for (int i = 1; i <= N; i++)
			if (abs(p[i] - oth.p[i]) > 1)
				return false;
		return true;
	}
} p[4000000];

int tp[MX];
std::vector <perm> vec;

int main()
{
	freopen("constr.in", "r", stdin);
	freopen("constr.out", "w", stdout);
	auto t = clock();
	for (int i = 1; i <= N; i++)
		tp[i] = i;
	int cnt = 0;
	do
	{
		cnt++;
		for (int i = 1; i <= N; i++)
			p[cnt].p[i] = tp[i];
		p[cnt].id = cnt;
	} while (std::next_permutation(tp + 1, tp + N + 1));
	for (int i = 1; i <= cnt; i++)
	{
		bool fl = true;
		for (auto p : vec)
			if (::p[i].eq(p))
			{
				fl = false;
				break;
			}
		if (fl)
		{
			vec.push_back(p[i]);
		}
		if ((double)(clock() - t) / CLOCKS_PER_SEC >= 0.95)
			break;
	}
	write(vec.size());
	putchar('\n');
	for (auto p : vec)
	{
		for (int i = 1; i <= N; i++)
			write(p.p[i]),
			putchar(' ');
		putchar('\n');
	}
}
