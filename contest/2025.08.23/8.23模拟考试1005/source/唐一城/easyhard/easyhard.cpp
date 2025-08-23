#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=3005;
int n,m,mod;
il int qmi(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=1ll*res*a%mod;
        b>>=1,a=1ll*a*a%mod;
    }return res;
}
int main()
{
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    cin>>n>>m>>mod;
    if(n==1)cout<<qmi(2,m+1);
    else cout<<qmi(2,2*m);
    return 0;
}