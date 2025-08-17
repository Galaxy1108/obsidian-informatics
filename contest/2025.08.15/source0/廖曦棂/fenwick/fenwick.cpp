#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 10000010;
int n, Q, op;
ull x, y, s1, s2, ans, a[N], b[N];
void add_a(int x, ull k)
{
    for (int i = 1; x <= n; x += (x & -x), i++)
        a[x] += k, b[x] += i * k;
}
ull ask(ull x)
{
    ull res = 0;
    for (; x; x -= (x & -x))
        res += b[x];
    return res;
}
ull my_rand()
{
    ull s3 = s1, s4 = s2;
    s1 = s2 ^ 774527;
    s3 ^= (s3 << 47) ^ (s3 >> 13);
    s2 ^= s3 ^ (s4 << 31) ^ (s4 >> 17);
    return s2 + s4;
}
void get_query(int &op, ull &num1, ull &num2)
{
    op = my_rand() % 2 + 1;
    if (op == 1)
    {
        num1 = my_rand() % n + 1;
        num2 = my_rand() % n + 1;
    }
    else
    {
        num1 = my_rand() % n + 1;
        num2 = my_rand() % n + 1;
        if (num1 > num2)
            swap(num1, num2);
    }
}
int main()
{
    freopen("fenwick.in", "r", stdin);
    freopen("fenwick.out", "w", stdout);
    scanf("%d%d%llu%llu", &n, &Q, &s1, &s2);
    for (int i = 1; i <= Q; i++)
    {
        get_query(op, x, y);
        if (op == 1)
            add_a(x, y);
        else
            ans ^= (i * (ask(y) - ask(x - 1)));
    }
    cout << ans << endl;
    // printf("2588154976231288790\n");
    return 0;
}
