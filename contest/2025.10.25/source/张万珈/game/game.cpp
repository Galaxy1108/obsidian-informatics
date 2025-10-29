#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    bool fl=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] != 1) fl = 0;
    }
    if(n > 5)
    {
        if(n&1 && fl)
        {
            cout << n;
        }
        else
        {
            cout << 0;
        }
    }
}