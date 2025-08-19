#include <bits/stdc++.h>
using namespace std;
vector<int> p[1000010];
long long solve(int x,int l,int r)
{
    long long ret = 0;
    for(int i=l;i<=r;i++)
    {
    	if(__gcd(i,x) == 1) ret++;
	}
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
    int n;
    cin >> n;
    while(n--)
    {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int l = ((c-1)/k) + 1,r = d/k;
        long long ans = 0;
        for(int i=((a-1)/k) + 1;i<=b/k;i++)
        {
            ans += solve(i,l,r);
        }
        cout << ans << '\n';
    }
    return 0;
}
