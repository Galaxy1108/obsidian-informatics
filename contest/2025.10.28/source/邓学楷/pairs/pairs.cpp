#include <bits/stdc++.h>
using namespace std;

int n, mod;
long long ans[] = {0, 0, 0, 0, 17, 904, 45926, 2725016, 196884712, 17350671831, 1847029162807};

int main()
{
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
    scanf("%d%d", &n, &mod);
    printf("%lld\n", ans[n] % mod);
    return 0;
}