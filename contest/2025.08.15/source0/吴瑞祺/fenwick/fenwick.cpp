#include <bits/stdc++.h>
#define MAXN 10000010
using namespace std;
#define ull unsigned long long
int n, q;
int op;
ull val1, val2;
ull s1, s2, s3, s4;
ull ans, a[MAXN];

ull my_rand() {
	s3 = s1, s4 = s2, s1 = s2 ^ 774527, s3 ^= (s3 << 47) ^ (s3 >> 13), s2 ^= s3 ^ (s4 << 31) ^ (s4 >> 17);
	return s2 + s4;
}

void get_query(int &op, ull &num1, ull &num2) {
	op = (my_rand() & 1) + 1;
	if(op == 1) num1 = my_rand() % n + 1, num2 = my_rand() % n + 1;
	else {
		num1 = my_rand() % n + 1, num2 = my_rand() % n + 1;
		if(num1 > num2) swap(num1, num2);
	}
	return;
}

void add(int x, const ull k){
	ull now = 0;
	for (; x <= n; x += x & -x) a[x] += (now += k);
	return;
}

ull query(int x) {
	ull ans = 0;
	for (; x; x -= x & -x) ans += a[x];
	return ans;
}

int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> n >> q >> s1 >> s2;
    for (int i = 1; i <= q; ++i) {
    	get_query(op, val1, val2);
    	if (op == 1) add(val1, val2);
    	else ans ^= (query(val2) - query(val1 - 1)) * i;
    }
    cout << ans;
    return 0;
}