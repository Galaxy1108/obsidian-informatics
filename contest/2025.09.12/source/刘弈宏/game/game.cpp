#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

struct node
{
	int v;
	int i;
	node() {}
	node(int val, int idx)
	{
		v = val;
		i = idx;
	}
};

bool cmp(node l, node r)
{
	if (l.v != r.v)
	{
		return l.v <= r.v;
	}
	return l.i > r.i;
}

int n, m;
node in[8005];

queue<int> que;

signed main()
{
		freopen("game.in", "r", stdin);
		freopen("game.out", "w", stdout);
	//
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> in[i].v;
		in[i].i = i;
		in[i].v *= 2;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		in[u].v += w;
		in[v].v += w;
	}

	sort(in + 1, in + 1 + n, cmp);

	ll cnt[2] = {0};

	while (n)
	{
		cnt[n & 1] += in[n].v;
		if (!(n & 1))
			que.push(in[n].i);
		n--;
	}

	cout << (cnt[0] - cnt[1]) / 2 << endl;
	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}
	return 0;
}
