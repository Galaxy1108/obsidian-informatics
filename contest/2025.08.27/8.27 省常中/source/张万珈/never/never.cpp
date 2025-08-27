#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
long long n;
long long x,y,s,t;
void solve()
{
    cin >> n >> s >> t >> x >> y;
    while(n)
    {
        if(s >= t)
        {
            int cnt = (s-t)/x + 1;
            if(n <= cnt)
            {
                cout << s - n*x << endl;
                return;
            }
            n -= cnt;
            s -= cnt*x;
        }
        else
        {
            int cnt = (t-s-1)/y + 1;
            if(n <= cnt)
            {
                cout << s + n*y << endl;
                return;
            }
            n -= cnt;
            s += cnt*y;
        }
        if(x == y && ((s >= t && s-x < t) || (s < t && s+y >= t)))
        {
            n &= 1;
        }
    }
    cout << s << "\n";    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}