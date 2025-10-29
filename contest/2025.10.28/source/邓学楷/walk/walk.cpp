#include <bits/stdc++.h>
using namespace std;

int n, a[200010];
long long ans = 0;
vector<int> v;

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    printf("%lld\n", ans);
    return 0;
}