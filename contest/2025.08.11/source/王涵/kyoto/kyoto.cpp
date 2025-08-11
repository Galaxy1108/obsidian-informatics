#include <cstdio>
#include <stack>
#include <algorithm>
#define max(A, B) (A < B ? B : A)
typedef long long intt;

const int MX = 1000010;

int a[MX], b[MX];

namespace solve
{
struct slope
{
	intt x, y;
	
	bool operator>= (slope oth)
	{
		return oth.x * y >= oth.y * x;
	}
	
	bool operator>= (int k)
	{
		return y >= x * k;
	}
	
	bool operator< (slope oth)
	{
		return oth.x * y < oth.y * x;
	}
	
	slope operator+ (slope oth)
	{
		return { x + oth.x, y + oth.y };
	}
	
	slope operator* (int oth)
	{
		return { x, y * oth };
	}
	
	void operator+= (slope oth)
	{
		*this = *this + oth;
	}
	
	void operator= (int oth)
	{
		y = oth * x;
	}
};

namespace sgt
{
slope mx[MX << 2], tree[MX << 2];
int st[MX << 2], cnt[MX << 2], n;

void build(slope arr[], int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
	{
		tree[p] = mx[p] = arr[cl];
	}
	else
	{
		int mid = (cl + cr) >> 1;
		build(arr, p << 1, cl, mid);
		build(arr, p << 1 | 1, mid + 1, cr);
		tree[p] = mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
	}
}

inline void push_st(int p, int x)
{
	tree[p] = st[p] = x;
	cnt[p] = 0;
}

inline void push_cnt(int p, int x)
{
	tree[p].y += mx[p].y * x;
	cnt[p] += x;
}

void push_down(int p)
{
	if (st[p])
	{
		push_st(p << 1, st[p]);
		push_st(p << 1 | 1, st[p]);
		st[p] = 0;
	}
	if (cnt[p])
	{
		push_cnt(p << 1, cnt[p]);
		push_cnt(p << 1 | 1, cnt[p]);
		cnt[p] = 0;
	}
}

int lower(int x, int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
	{
		return (tree[p] >= x) * cl;
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (tree[p << 1 | 1] >= x)
			return lower(x, p << 1 | 1, mid + 1, cr);
		else if (tree[p << 1] >= x)
			return lower(x, p << 1, cl, mid);
		else
			return 0;
	}
}

void set(int l, int r, int x, int p, int cl, int cr)
{
	if (l <= cl and cr <= r)
	{
		push_st(p, x);
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		if (l <= mid)
			set(l, r, x, p << 1, cl, mid);
		if (mid < r)
			set(l, r, x, p << 1 | 1, mid + 1, cr);
		tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
	}
}

void set(int l, int r, int x)
{
	if (l <= r)
		set(l, r, x, 1, 1, n);
}

void add()
{
	push_cnt(1, 1);
}

slope query(int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
	{
		return tree[p];
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		return query(p << 1, cl, mid) + query(p << 1 | 1, mid + 1, cr);
	}
}

void pp(int p = 1, int cl = 1, int cr = n)
{
	if (cl == cr)
	{
		printf("(%lld, %lld) ", tree[p].x, tree[p].y);
	}
	else
	{
		push_down(p);
		int mid = (cl + cr) >> 1;
		pp(p << 1, cl, mid);
		pp(p << 1 | 1, mid + 1, cr);
	}
}
}

intt solve(int h, int w)
{
	static slope vec[MX];
	static bool vis[MX];
	for (int i = 1; i < h; vec[i] = { 1, a[i] - a[i - 1] }, i++);
	std::stack <int> stk;
	for (int i = 1; i < h; i++)
	{
		while (not stk.empty() and vec[stk.top()] >= vec[i])
			vec[i] += vec[stk.top()],
			stk.pop();
		stk.push(i);
	}
	while (not stk.empty())
		vis[stk.top()] = true,
		stk.pop();
	int tot = 0;
	for (int i = 1; i < h; i++)
		if (vis[i])
			vec[++tot] = vec[i];
	sgt::n = tot;
	sgt::build(vec);
	sgt::set(1, h - 1, b[1]);
	printf("%lld\n", sgt::query().y);
	sgt::pp();putchar('\n');
	for (int i = 2; i <= w; i++)
	{
		sgt::add();
		sgt::set(1, sgt::lower(b[i]), b[i]);
		printf("%lld\n", (intt)a[0] * (i - 1) + sgt::query().y);
		sgt::pp();putchar('\n');
	}
	return (intt)a[0] * (w - 1) + sgt::query().y;
}
}

int main()
{
	freopen("kyoto.in", "r", stdin);
	freopen("kyoto.out", "w", stdout);
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; scanf("%d", a + i++));
	for (int i = 1; i <= w; scanf("%d", b + i++));
	printf("%lld", solve::solve(h, w));
}
