#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 200000 + 1, P = 998244353;

void solve() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 1; ; ++i) {
		cout << i << endl;
		assert(!system("gen > input.txt"));
		assert(!system("brute < input.txt > brute.txt"));
		assert(!system("better < input.txt > better.txt"));
		assert(!system("fc brute.txt better.txt"));
	}
	return 0;
}
