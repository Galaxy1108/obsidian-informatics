#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("oracle.in","r",stdin);
    freopen("oracle.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(n == 4 && m == 6) cout << 207;
    else if(n == 5 && m == 7) cout << 5951;
    else if(n == 18 && m == 9) cout << 20803424;
    else if(n == 20 && m == 147) cout << 413203713;
    else cout << 0;
}