#include <bits/stdc++.h>
using namespace std;
int mod[11][11];
int main()
{
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    int n,p;
    cin >> n >> p;
    mod[3][0] = -1,mod[3][1] = -1,mod[3][2] = 2;
    mod[5][0] = -1,mod[5][1] = -1,mod[5][2] = 1,mod[5][3] = 1,mod[5][4] = 2;
    for(int i=1,x;i<=n;i++)
    {
        cin >> x;
        if(mod[p][x%p] != 0)
        {
            cout << mod[p][x%p] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
