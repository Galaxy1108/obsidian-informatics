#include <bits/stdc++.h>
using namespace std;
int n;
int sum;
int h1[100];
int h2[100];
int k[1000];

int a[100];
int b[100];
bool check () {
	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}
int main () {
	freopen ("lineup.in", "r", stdin);
	freopen ("lineup.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h1[i];
		h2[i] = h1[i];
	}
	sort (h2 + 1, h2 + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (h2[i] > h2[i - 1]) {
			k[h2[i]] = i;
		}
		b[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = k[h1[i]];
		k[h1[i]]++;
//		cout << setw (3) << a[i] << ' ';
	}
//	cout << '\n';
	
	while (!check ()) {
		for (int i = n; i >= 1; --i) {
			if (a[i] == b[i]) {
				continue;
			}
			int o = i;
			for (int j = i; j >= 1; --j) {
				if (a[o] > b[j]) {
					break;
				}
				if (a[j] >= b[o]) {
					sum += 2 * abs (o - j);
					swap (a[o], a[j]);
					o = j;
				}
			}
		}
//		for (int i = 1; i <= n; ++i) {
//			cout << a[i] << ' ';
//		}
//		cout << '\n';
	}
	cout << sum;
	return 0;
}

