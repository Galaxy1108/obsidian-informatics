#include <bits/stdc++.h>
#define N 1000006

using namespace std;

int a[N],n;
bool isall1()
{
    for(int i=1;i<=n;i++)if(a[i]!=1)return 0;
    return 1;
}

namespace solve
{
    void solve()
    {

    }
}



int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(isall1())cout<<(n%2==0?0:n)<<"\n";

    return 0;
}