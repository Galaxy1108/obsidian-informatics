#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000100];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n%2==0)
    {
        cout<<0;
    }
    else
    {
        cout<<1;
    }
}