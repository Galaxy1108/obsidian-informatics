#include <cstdio>
#include <algorithm>
#define min(A, B) (A < B ? A : B)
#define max(A, B) (A < B ? B : A)
typedef long long intt;

const int MX = 100010;

int a[MX];

namespace solve0
{
int pc[MX], p0[MX], p00[MX], p1[MX], p11[MX], n;

void upd()
{
	for (int i = 1; i <= n; pc[i] = pc[i - 1] + (a[i] == 1), p0[i] = a[i] ? p0[i - 1] : i, p00[i] = a[i] ? p00[i - 1] : p0[i - 1], p1[i] = a[i] ? i : p1[i - 1], p11[i] = a[i] ? p1[i - 1] : p11[i - 1], i++);
}

void flip(int p)
{
	a[p] ^= 1;
	upd();
}

int query(int l, int r)
{
	int ret = 0;
	for (int i = l; i <= r; i++)
	{
		int ll = min(p11[i], p00[i]);
		ret += max(ll - l + 1, 0);
		if (p11[i] < p00[i])
			ret += i - max(l - 1, p1[i]);
		else
			ret += (pc[i] - pc[max(p00[i], l - 1)] >> 1) + (l <= p0[i]) * not (pc[i] - pc[max(p0[i], l - 1)] & 1);
	}
	return ret;
}

void main(int n, int m)
{
	solve0::n = n;
	upd();
	int op, l, r, p;
	while (m--)
	{
		scanf("%d", &op);
		if (op == 1)
			scanf("%d", &p),
			flip(p);
		else
			scanf("%d%d", &l, &r),
			printf("%d\n", query(l, r));
	}
}
}

namespace solve1
{
const int B = 400;

struct qry
{
	int l, r, id;
} qr[MX];

int pc[MX], p0[MX], p00[MX], p1[MX], p11[MX], sc[MX], s0[MX], s00[MX], s1[MX], s11[MX], l, r;
intt ans[MX], sum;

void addr(int i)
{
	int ll = min(p11[i], p00[i]);
	sum += max(ll - l + 1, 0);
	if (p11[i] < p00[i])
		sum += i - max(l - 1, p1[i]);
	else
		sum += (pc[i] - pc[max(p00[i], l - 1)] >> 1) + (l <= p0[i]) * not (pc[i] - pc[max(p0[i], l - 1)] & 1);
}

void delr(int i)
{
	int ll = min(p11[i], p00[i]);
	sum -= max(ll - l + 1, 0);
	if (p11[i] < p00[i])
		sum -= i - max(l - 1, p1[i]);
	else
		sum -= (pc[i] - pc[max(p00[i], l - 1)] >> 1) + (l <= p0[i]) * not (pc[i] - pc[max(p0[i], l - 1)] & 1);
}

void addl(int i)
{
	int rr = max(s11[i], s00[i]);
	sum += max(r - rr + 1, 0);
	if (s00[i] < s11[i])
		sum += min(r + 1, s1[i]) - i;
	else
		sum += (sc[i] - sc[min(s00[i], r + 1)] >> 1) + (s0[i] <= r) * not (sc[i] - sc[min(s0[i], r + 1)] & 1);
}

void dell(int i)
{
	int rr = max(s11[i], s00[i]);
	sum -= max(r - rr + 1, 0);
	if (s00[i] < s11[i])
		sum -= min(r + 1, s1[i]) - i;
	else
		sum -= (sc[i] - sc[min(s00[i], r + 1)] >> 1) + (s0[i] <= r) * not (sc[i] - sc[min(s0[i], r + 1)] & 1);
}

#define bk(x) ((x - 1) / B + 1)

bool cmp(qry& a, qry& b)
{
	return bk(a.l) == bk(b.l) ? a.r < b.r : a.l < b.l;
}

#undef bk

void main(int n, int m)
{
	for (int i = 1; i <= n; pc[i] = pc[i - 1] + (a[i] == 1), p0[i] = a[i] ? p0[i - 1] : i, p00[i] = a[i] ? p00[i - 1] : p0[i - 1], p1[i] = a[i] ? i : p1[i - 1], p11[i] = a[i] ? p1[i - 1] : p11[i - 1], i++);
	for (int i = n; i; sc[i] = sc[i + 1] + (a[i] == 1), s0[i] = a[i] ? s0[i + 1] : i, s00[i] = a[i] ? s00[i + 1] : s0[i + 1], s1[i] = a[i] ? i : s1[i + 1], s11[i] = a[i] ? s1[i + 1] : s11[i + 1], i--);
	for (int i = 1; i <= m; i++)
		scanf("%*d%d%d", &qr[i].l, &qr[i].r), qr[i].id = i;
	std::sort(qr + 1, qr + m + 1, cmp);
	l = 1;
	for (int i = 1; i <= m; i++)
	{
		for (; r < qr[i].r; addr(++r));
		for (; qr[i].r < r; delr(r--));
		for (; l < qr[i].l; dell(l++));
		for (; qr[i].l < l; addl(--l));
		ans[qr[i].id] = sum;
	}
	for (int i = 1; i <= m; printf("%lld\n", ans[i++]));
}
}

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	scanf("%d", &m);
	if (n <= 5000)
		solve0::main(n, m);
	else
		solve1::main(n, m);
}
