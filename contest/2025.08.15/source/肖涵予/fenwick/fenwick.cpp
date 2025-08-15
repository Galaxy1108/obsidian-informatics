#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;
typedef unsigned long long ull;
const int N = 1e7 + 3;
ull n, Q, opt, a, b, s1, s2;
ull tr[N], ans, res;
ull my_rand(void) {
    ull s3 = s1, s4 = s2;
    s1 = s2 ^ 774527;
    s3 ^= (s3 << 47) ^ (s3 >> 13);
    s2 ^= s3 ^ (s4 << 31) ^ (s4 >> 17);
    return s2 + s4;
}
void get_query(ull &op, ull &num1, ull &num2) {
    op = my_rand() % 2 + 1;
    if (op == 1) {
        num1 = my_rand() % n + 1;
        num2 = my_rand() % n + 1;
    }
    else {
        num1 = my_rand() % n + 1;
        num2 = my_rand() % n + 1;
        if (num1 > num2) swap(num1, num2);
    }
    return ;
}
void add(ull x, ull k) {
	ull tmp = k;
	while (x <= n) {
		tr[x] += k;
		x += lowbit(x);
		k += tmp;
	}
	return ;
}
ull sum(ull x) {
	ull res = 0;
	while (x) {
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}
int main(void) {
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);
	scanf("%llu %llu %llu %llu", &n, &Q, &s1, &s2);
	for (ull t = 1; t <= Q; ++t) {
		get_query(opt, a, b);
		if (opt == 1) add(a, b);
		else {
			res = t * (sum(b) - sum(--a));
			ans ^= res;
		}
	}
	printf("%llu", ans);
	return 0;
}
