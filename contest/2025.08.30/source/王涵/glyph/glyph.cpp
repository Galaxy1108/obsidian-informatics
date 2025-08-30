#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
typedef long long intt;

const int MX = 310, MXQ = 200010;

struct qry
{
	int sr, sc, tr, tc, id;
} qr[MXQ];

int a[MX][MX];

namespace solve
{
intt ans[MXQ], dis[MX][MX];

void getdis(int sr, int sc, int rl, int rr, int cl, int cr, intt dis[][MX])
{
	dis[sr][sc] = a[sr][sc];
	for (int i = sc + 1; i <= cr; i++)
		dis[sr][i] = dis[sr][i - 1] + a[sr][i];
	for (int i = sc - 1; cl <= i; i--)
		dis[sr][i] = dis[sr][i + 1] + a[sr][i];
	for (int i = sr + 1; i <= rr; i++)
		dis[i][sc] = dis[i - 1][sc] + a[i][sc];
	for (int i = sr - 1; rl <= i; i--)
		dis[i][sc] = dis[i + 1][sc] + a[i][sc];
	for (int i = sr + 1; i <= rr; i++)
		for (int j = sc + 1; j <= cr; j++)
			dis[i][j] = min(dis[i - 1][j], dis[i][j - 1]) + a[i][j];
	for (int i = sr - 1; rl <= i; i--)
		for (int j = sc + 1; j <= cr; j++)
			dis[i][j] = min(dis[i + 1][j], dis[i][j - 1]) + a[i][j];
	for (int i = sr + 1; i <= rr; i++)
		for (int j = sc - 1; cl <= j; j--)
			dis[i][j] = min(dis[i - 1][j], dis[i][j + 1]) + a[i][j];
	for (int i = sr - 1; rl <= i; i--)
		for (int j = sc - 1; cl <= j; j--)
			dis[i][j] = min(dis[i + 1][j], dis[i][j + 1]) + a[i][j];
}

void solve(int rl, int rr, int cl, int cr, int ql, int qr)
{
	if (ql > qr)
		return;
	
	if (rl == rr)
	{
		getdis(rl, cl, rl, rr, cl, cr, dis);
		for (int i = ql; i <= qr; i++)
			ans[::qr[i].id] = dis[::qr[i].tr][::qr[i].tc] - (cl < ::qr[i].sc ? dis[::qr[i].sr][::qr[i].sc - 1] : 0);
	}
	else if (cl == cr)
	{
		getdis(rl, cl, rl, rr, cl, cr, dis);
		for (int i = ql; i <= qr; i++)
			ans[::qr[i].id] = dis[::qr[i].tr][::qr[i].tc] - (rl < ::qr[i].sr ? dis[::qr[i].sr - 1][::qr[i].sc] : 0);
	}
	else if (rr - rl > cr - cl)
	{
		int mid = (rl + rr) >> 1;
		auto id = [&mid](const qry& a) -> int
		{
			return a.sr <= mid and mid < a.tr ? 0 : a.tr <= mid ? 1 : 2;
		};
		std::sort(::qr + ql, ::qr + qr + 1, [&id](const qry& a, const qry& b) -> bool
		{
			return id(a) < id(b);
		});
		for (int p = cl; p <= cr; p++)
		{
			getdis(mid, p, rl, rr, cl, cr, dis);
			for (int i = ql; i <= qr and not id(::qr[i]); i++)
				if (::qr[i].sc <= p and p <= ::qr[i].tc)
					minx(ans[::qr[i].id], dis[::qr[i].sr][::qr[i].sc] + dis[::qr[i].tr][::qr[i].tc] - a[mid][p]);
		}
		for (; ql <= qr and not id(::qr[ql]); ql++);
		int qm = qr;
		for (; ql <= qm and id(::qr[qm]) == 2; qm--);
		solve(rl, mid, cl, cr, ql, qm);
		solve(mid + 1, rr, cl, cr, qm + 1, qr);
	}
	else
	{
		int mid = (cl + cr) >> 1;
		auto id = [&mid](const qry& a) -> int
		{
			return a.sc <= mid and mid < a.tc ? 0 : a.tc <= mid ? 1 : 2;
		};
		std::sort(::qr + ql, ::qr + qr + 1, [&id](const qry& a, const qry& b) -> bool
		{
			return id(a) < id(b);
		});
		for (int p = rl; p <= rr; p++)
		{
			getdis(p, mid, rl, rr, cl, cr, dis);
			for (int i = ql; i <= qr and not id(::qr[i]); i++)
				if (::qr[i].sr <= p and p <= ::qr[i].tr)
					minx(ans[::qr[i].id], dis[::qr[i].sr][::qr[i].sc] + dis[::qr[i].tr][::qr[i].tc] - a[p][mid]);
		}
		for (; ql <= qr and not id(::qr[ql]); ql++);
		int qm = qr;
		for (; ql <= qm and id(::qr[qm]) == 2; qm--);
		solve(rl, rr, cl, mid, ql, qm);
		solve(rl, rr, mid + 1, cr, qm + 1, qr);
	}
}

void solve(int n, int q)
{
	memset(ans + 1, 0x3f, sizeof(intt) * q);
	solve(1, n, 1, n, 1, q);
}
}

int main()
{
	freopen("glyph.in", "r", stdin);
	freopen("glyph.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; scanf("%d", a[i] + j++));
	for (int i = 1; i <= q; i++)
		scanf("%d%d%d%d", &qr[i].sr, &qr[i].tr, &qr[i].sc, &qr[i].tc),
		qr[i].id = i;
	solve::solve(n, q);
	for (int i = 1; i <= q; i++)
		printf("%lld\n", solve::ans[i]);
}
