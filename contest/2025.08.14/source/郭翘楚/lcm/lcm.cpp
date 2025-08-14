#include <bits/stdc++.h>
using namespace std;
unsigned long long f[105];
unsigned long long g[105];
void p()
{
    g[0]=1;
    unsigned long long x=1,y=1;
    for(int i=1;i<=100;i++)
    {
        f[i]=y;
        unsigned long long z=y;
        y+=x;
        x+=2*z;
    }
    return;
}
int main() 
{
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
    p();
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        unsigned long long n,p;
        cin>>n>>p;
        unsigned long long ans=0;
        for(int j=1;j<=n;j++)
        {
            g[j]=g[j-1]*f[j]/__gcd(g[j-1],f[j]);
        }
        for(int j=1;j<=n;j++)
        {
            ans+=(j*g[j])%p;
            ans%=p;
        }
        cout<<ans<<endl;  
    }
    return 0;
}
