#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size()) 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 2e5 + 7, M = 307;
int n, q, a[M][M];
int lx[N], ly[N], rx[N], ry[N];
ll ns[N];

ll dis[M][M];

void dc(int l1, int r1, int l2, int r2, vi VC) {
	if(l1 > r1 || l2 > r2) return ;
	
	vi vl, vr;
	vector < pair < int, int > > qwq;
	
	if(r1 - l1 > r2 - l2) {
		int mid = (l1 + r1) >> 1;
		L(i, l2, r2) qwq.emplace_back(mid, i);
		vi cur, ql, qr;
		for(auto u : VC) {
			if(rx[u] < mid) ql.emplace_back(u);
			else if(lx[u] > mid) qr.emplace_back(u);
			else cur.emplace_back(u);
		} 
		VC = cur;
		dc(l1, mid - 1, l2, r2, ql);
		dc(mid + 1, r1, l2, r2, qr);
	} else {
		int mid = (l2 + r2) >> 1;
		L(i, l1, r1) qwq.emplace_back(i, mid);
		vi cur, ql, qr;
		for(auto u : VC) {
			if(ry[u] < mid) ql.emplace_back(u);
			else if(ly[u] > mid) qr.emplace_back(u);
			else cur.emplace_back(u);
		} 
		VC = cur;
		dc(l1, r1, l2, mid - 1, ql);
		dc(l1, r1, mid + 1, r2, qr);
	}
	
	for(auto u : qwq) {
		int x = u.first, y = u.second;
		R(i, x, l1) {
			R(j, y, l2) {
				if(i == x && j == y) dis[i][j] = 0;
				else if(i == x) dis[i][j] = dis[i][j + 1] + a[i][j];
				else if(j == y) dis[i][j] = dis[i + 1][j] + a[i][j];
				else dis[i][j] = min(dis[i][j + 1], dis[i + 1][j]) + a[i][j];
			}
		}
		L(i, x, r1) {
			L(j, y, r2) {
				if(i == x && j == y) dis[i][j] = 0;
				else if(i == x) dis[i][j] = dis[i][j - 1] + a[i][j];
				else if(j == y) dis[i][j] = dis[i - 1][j] + a[i][j];
				else dis[i][j] = min(dis[i][j - 1], dis[i - 1][j]) + a[i][j];
			}
		}
		for(auto t : VC) 
			if(lx[t] <= x && x <= rx[t] && ly[t] <= y && y <= ry[t]) 
				ns[t] = min(ns[t], dis[lx[t]][ly[t]] + dis[rx[t]][ry[t]] + a[x][y]);
	}
}

int main() {
//	return system("fc glyph.out glyph5.out"), 0;
	freopen("glyph.in", "r", stdin); 
	freopen("glyph.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) {
		L(j, 1, n) {
			cin >> a[i][j];
		}
	}
	
	L(i, 1, q) {
		cin >> lx[i] >> rx[i] >> ly[i] >> ry[i];
		ns[i] = 1e18;
	}
	
	vi all;
	L(i, 1, q) all.emplace_back(i);
	dc(1, n, 1, n, all);
	L(i, 1, q) 
		cout << ns[i] << '\n';
	return 0;
}