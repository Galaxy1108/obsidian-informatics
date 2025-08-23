#include<bits/stdc++.h>
using namespace std;
long long n,m,p;
long long powq(long long x,long long k)
{
    long long sum=1;
    while(k)
    {
        if(k&1)
        {
            sum*=1ll*(x%p);
            sum%=p;
        }
        k>>=1;
        x*=1ll*x;
        x%=p;
    }
    return sum%p;
}
int main()
{
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    cin>>n>>m>>p;
    if(n>=m) cout<<powq(2,2*m);
    else
    {
        cout<<powq(2,n+m);
    }
}
