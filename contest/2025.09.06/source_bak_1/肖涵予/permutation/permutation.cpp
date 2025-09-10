#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int n, p[N], q[N];
int totp, totq, sizp[N], sizq[N], cycp[N], cycq[N], fromp[N], fromq[N];
bool visp[N], visq[N];
int h[N];
struct Node {
	int idx, siz;
	bool operator < (const Node cmp) const {
		return (siz < cmp.siz);
	}
	Node () = default;
	Node (int idx, int siz) : idx(idx), siz(siz) {}
};
vector <Node> vecp, vecq;
int main(void) {
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1; i <= n; ++i)
		cin >> q[i];
	for (int i = 1; i <= n; ++i) {
		if (visp[i]) continue;
		sizp[++totp] = 1, cycp[i] = totp, visp[i] = true, fromp[totp] = i;
		int now = p[i];
		while (now != i) {
			++sizp[totp], cycp[now] = totp, visp[now] = true;
			now = p[now];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (visq[i]) continue;
		sizq[++totq] = 1, cycq[i] = totq, visq[i] = true, fromq[totq] = i;
		int now = q[i];
		while (now != i) {
			++sizq[totq], cycq[now] = totq, visq[now] = true;
			now = q[now];
		}
	}
	if (totp != totq) {
		cout << "NO";
		return 0;
	}
	for (int i = 1; i <= totp; ++i)
		vecp.push_back(Node(i, sizp[i]));
	for (int i = 1; i <= totq; ++i)
		vecq.push_back(Node(i, sizq[i]));
	sort(vecp.begin(), vecp.end()), sort(vecq.begin(), vecq.end());
	for (int i = 0; i < totp; ++i)
		if (vecp[i].siz != vecq[i].siz) {
			cout << "NO";
			return 0;
		}
	cout << "YES\n";
	for (int i = 0; i < totp; ++i) {
		int nowl = fromp[vecp[i].idx], nowr = fromq[vecq[i].idx];
		int num = 0;
		while (num < sizp[vecp[i].idx]) {
			++num;
			h[nowr] = nowl;
			nowl = p[nowl], nowr = q[nowr];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << h[i];
		if (i < n) cout << ' ';
	}
	return 0;
}
