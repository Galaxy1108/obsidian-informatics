#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    if(x<y)
    {
        swap(x,y);
    }
    return gcd(y,x%y);
}
int lca(int x,int y)
{
    int k=gcd(x,y);
    return x/k*y;
}
int root(int x)
{
    int sum=1;
    for(int i=x;i>=2;i--)
    {
        sum=lca(sum,i);
    }
    return sum;
}
signed main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    cin>>n;
    cout<<root(n)<<" ";
    for(int i=2;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<"1 "<<i<<endl;
    }
}