#include <bits/stdc++.h>
using namespace std;
namespace my_std{
long long a[2000010],win[2000010][25];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        win[i][0] = a[i];
    }
    for(int i=1;i<=21;i++)
    {
        for(int j=1;j<=n-(1<<i)+1;j++) {win[j][i] = abs(win[j][i-1] - win[j+(1<<(i-1))][i-1]);}
    }
    while(q--)
    {
        int type,x,y;
        cin >> type >> x >> y;
        if(type==1)
        {
            win[x][0] = y;
            for(int i=1;i<=21;i++)
            {
                for(int j=max(x-(1<<i)+1,0);j<=min(x,n-(1<<i)+1);j++) win[j][i] = abs(win[j][i-1] - win[j+(1<<(i-1))][i-1]);
            }
        }
        if(type == 2)
        {
            cout << win[x][y] << endl;
        }
    }
    return 0;
}
}
int main()
{
    return my_std::main();
}