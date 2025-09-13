#include <cstdio>
#include <iostream>

using namespace std;

char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int f[10000005], sz[10000005], n;
bool used[8000005];
char s[2000005];
int ca[2000005];
int getf(int x)
{
	return (x == f[x]) ? x : (f[x] = getf(f[x]));
}
void un(int x, int y)
{
	int fx = getf(x);
	int fy = getf(y);
	if(fx == fy)
		return ;
	if(sz[fx] > sz[fy])
		swap(fx, fy);
	f[fx] = fy;
	sz[fy] += sz[fx];
}
void build(int p, int l, int r, bool b)
{
	b |= used[p];
	if(l == r)
	{
		if(b)
			un(p + n, l);
		return ;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid, b);
	build(p << 1 | 1, mid + 1, r, b);
	if(b)
	{
		un(p + n, (p << 1) + n);
		un(p + n, (p << 1 | 1) + n);
	}
}
void qry(int p, int l, int r, int ql, int qr, int x)
{
	if(l >= ql && r <= qr)
	{
		used[p] = 1;
		un(p + n, x);
		return ;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid)
		qry(p << 1, l, mid, ql, qr, x);
	if(qr > mid)
		qry(p << 1 | 1, mid + 1, r, ql, qr, x);
}

int main()
{
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
	int lk, rk, i, l, r, q, x, y;
	n = rd();
	lk = rd();
	rk = rd();
	for(i = 1; i <= n; i++)
		s[i] = getchar();
	for(i = 1; i <= 5 * n; i++)
	{
		f[i] = i;
		sz[i] = 1;
	}
	for(i = 1; i <= n; i++)
		ca[i] = ca[i - 1] + (s[i] == 'a');
	l = r = 0;
	for(i = 1; i <= n; i++)
	{
		while(ca[i] - ca[l - 1] > rk)
			l++;
		while(ca[i] - ca[r] >= lk)
			r++;
		if(r)
			qry(1, 1, n, max(l, 1), r, i);
	}
	build(1, 1, n, 0);
	q = rd();
	while(q--)
	{
		x = rd();
		y = rd();
		if(getf(x) == getf(y))
		{
			*O++ = 'Y';
			*O++ = 'e';
			*O++ = 's';
			*O++ = '\n';
		}
		else
		{
			*O++ = 'N';
			*O++ = 'o';
			*O++ = '\n';
		}
	}
	fwrite(obuf,O-obuf,1,stdout);
	return 0;
}