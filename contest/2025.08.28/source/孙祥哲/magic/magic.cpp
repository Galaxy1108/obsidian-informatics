#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
#define N 250005
#define ls p<<1
#define rs p<<1|1 
using namespace std;

ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	return x*f;
}
void write(ll x) { if (x < 0) putchar('-'), x=-x; if (x > 9) write(x / 10); putchar(x%10+'0'); }
void write(ll x, char ed) { write(x),putchar(ed); }

struct Node { int l, r; ll v, tg; } t[3][4*N];

int n, m;
ll a[N], b[N], c[N];
ll op[N], l[N], r[N], v[N];

void addtg(int p, ll v, int op)
{
	if (op == 0)
	{
		t[op][p].v = (t[op][p].v+v*(t[op][p].r-t[op][p].l+1))%mod;
		t[op][p].tg = (t[op][p].tg+v)%mod;
	}
	if (op == 1)
	{
		t[op][p].v = (t[op][p].v*v)%mod;
		t[op][p].tg = (t[op][p].tg*v)%mod;
	}
	if (op == 2)
	{
		t[op][p].v = v*(t[op][p].r-t[op][p].l+1)%mod;
		t[op][p].tg = v;
	}
}
void pushdown(int p, int op)
{
	if ((op!=1&&!t[op][p].tg)||(op==1&&t[op][p].tg==1)) return;
	addtg(ls, t[op][p].tg, op), addtg(rs, t[op][p].tg, op);
	if (op != 1) t[op][p].tg = 0;
	else t[op][p].tg = 1;
}
void build(int p, int l, int r)
{
	t[0][p].l = t[1][p].l = t[2][p].l = l;
	t[0][p].r = t[1][p].r = t[2][p].r = r;
	t[1][p].tg = 1;
	if (l == r)
	{
		t[0][p].v = a[l], t[1][p].v = b[l], t[2][p].v = c[l];
		return;
	}
	int mid = l+r >> 1;
	build(ls, l, mid), build(rs, mid+1, r);
	t[0][p].v = (t[0][ls].v+t[0][rs].v)%mod;
	t[1][p].v = (t[1][ls].v+t[1][rs].v)%mod;
	t[2][p].v = (t[2][ls].v+t[2][rs].v)%mod;
}
void change(int p, int l, int r, ll v, int op) 
{
	if (l <= t[op][p].l && t[op][p].r <= r)	{ addtg(p, v, op); return; }
	int mid = t[op][p].l+t[op][p].r>>1;
	pushdown(p, op);
	if (l <= mid) change(ls, l, r, v, op);
	if (r > mid) change(rs, l, r, v, op);
	t[op][p].v = (t[op][ls].v+t[op][rs].v)%mod;
}
ll qry(int p, int l, int r, int op)
{
	if (l <= t[op][p].l && t[op][p].r <= r) return t[op][p].v;
	ll mid = t[op][p].l+t[op][p].r>>1, res = 0;
	pushdown(p, op);
	if (l <= mid) res += qry(ls, l, r, op);
	if (r > mid) res += qry(rs, l, r, op);
	return res%mod;
}

signed main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) a[i]=read(), b[i]=read(), c[i]=read();
	m = read();
	if (n <= 1000 && m <= 1000)
	{
		while (m--)
		{
			ll op = read(), l = read(), r = read(), v, s1 = 0, s2 = 0, s3 = 0;
			if (op >= 4 && op <= 6) v = read();
			for (int i = l; i <= r; i++)
			{
				if (op == 1) a[i] = (a[i]+b[i])%mod;
				if (op == 2) b[i] = (b[i]+c[i])%mod;
				if (op == 3) c[i] = (c[i]+a[i])%mod;
				if (op == 4) a[i] = (a[i]+v)%mod;
				if (op == 5) b[i] = (b[i]*v)%mod;
				if (op == 6) c[i] = v;
				if (op == 7) s1 = (s1+a[i])%mod, s2 = (s2+b[i])%mod, s3 = (s3+c[i])%mod;
			}
			if (op == 7) write(s1, ' '), write(s2, ' '), write(s3, '\n');
		}
	}
	else
	{
		bool f1 = 1, f2 = 1;
		for (int i = 1; i <= m; i++)
		{
			op[i] = read(), l[i] = read(), r[i] = read();
			if (op[i] >= 4 && op[i] <= 6) v[i] = read();
			if (op[i] == 7) f2 = 0;
			if (op[i] >= 1 && op[i] <= 3) f1 = 0;
		}
		if (!f2)
		{
			build(1, 1, n);
			for (int i = 1; i <= m; i++)
			{
				if (op[i] == 7)
					write(qry(1,l[i],r[i],0),' '),write(qry(1,l[i],r[i],1),' '),write(qry(1,l[i],r[i],2),'\n');
				else change(1, l[i], r[i], v[i], op[i]-4);
			}
		}
	}
	return 0;
}
