#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,a[N];
inline void print(__int128 x)
{
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
int main()
{
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    __int128 ans=0,tt=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i,mxn=0,mn=1e9;j<=n;j++)
        {
            mxn=max(mxn,a[j]),mn=min(mn,a[j]);
            ans=max(ans,tt*mxn*mn*(j-i+1));
        }
    }print(ans);
    return 0;
}