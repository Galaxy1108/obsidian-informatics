#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int k;
    cin >> k;
    int q;
    cin >> q;
    for(int i=1,n;i<=q;i++)
    {
        cin >> n;
        if(k*2 >= n)
        {
            cout << n << " 1\n";
        }
    }
}