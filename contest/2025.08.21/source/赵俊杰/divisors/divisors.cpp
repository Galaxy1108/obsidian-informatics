#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n==3)
    {
        cout<<"2 6 3\n1 2\n2 3\n";
        return 0;
    }
    if(n==4)
    {
        cout<<"3 6 8 12\n1 2\n2 3\n3 4\n";
        return 0;
    }
    int sum=1;
    for(int i=2;i<=n;i++)
    {
        sum=sum/gcd(sum,i)*i;
        cout<<i<<' ';
    }
    cout<<sum;
    cout<<'\n';
    for(int i=1;i<n;i++)cout<<n<<' '<<i<<'\n';
    cout<<'\n';
    return 0;
}
