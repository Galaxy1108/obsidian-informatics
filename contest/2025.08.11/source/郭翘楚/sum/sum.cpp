#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        long long s,k;
        cin>>s>>k;
        long long l=s-1;
        if(k*2>l)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<k*2<<endl;
        }
    }
    return 0;
}