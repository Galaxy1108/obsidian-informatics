#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N][N];
void gen(int n, int seed) {
    std::mt19937 rng(seed);
    for(int i = 1;i <= n; ++i) {
        for(int j = 1; j <= n + 1; ++j) {
            a[i][j] = j;
            std::swap(a[i][j], a[i][rng() % j + 1]);
        }
    }
    return ;
}
int main(void) {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	return 0;
}
