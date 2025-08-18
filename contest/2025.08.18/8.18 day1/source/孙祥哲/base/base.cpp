#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

long long n, a[2005], b[2005];
long long s1[2005], s2[2005];
long long f1[2005], f2[2005];

int main()
{
	 freopen("base.in", "r", stdin);
	 freopen("base.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s1[i] = s1[i-1]+a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], s2[i] = s2[i-1]+b[i];
    f1[1] = a[1]+b[1], f2[n] = a[n]+b[n];
    for (int i = 2; i <= n; i++) f1[i] = max(f1[i-1]+a[i]+b[i], a[i]+b[i]);
    for (int i = n-1; i >= 1; i--) f2[i] = max(f2[i+1]+a[i]+b[i], a[i]+b[i]);
//    for (int i = 1; i <= n; i++) cout << f1[i] << " ";  puts("");
//    for (int i = 1; i <= n; i++) cout << f2[i] << " ";  puts("");
    long long ans = -1e18;
    for (int i = 1; i <= n; i++)
    	for (int j = i+2; j <= n; j++)
    		ans = max(ans, f1[i]+f2[j]+s2[j-1]-s2[i]);
    cout << ans;
	return 0;
}
