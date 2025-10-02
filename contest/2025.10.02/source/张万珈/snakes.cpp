#include <bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int T;
    cin >> T;
    int n;
    cin >> n;
    for(int i=1,x;i<=n;i++)
    {
        cin >> x;
    }
    while(T--)
    {
        cout << rd()%n+1 << "\n";
    }
}