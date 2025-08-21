#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int n,m;
int l[50],r[50];
int sum=0;
int ans=0;
bool check(int x)
{
    int far[70];
    int len=0;
    int k=x;
    while(k)
    {
        far[++len]=k%2;
        k/=2;
    }
    if(len<m)
    {
        for(int i=len+1;i<=m;i++)
        {
            far[i]=0;
        }
        len=m;
    }
    for(int i=1;i<=len/2;i++)
    {
        if(far[i]!=far[len-i+1])
        {
            return false;
        }
    }
    return true;
}
void DFS(int x,int deep)
{
    if(x>deep)
    {
        if(check(sum))
        {
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int i=l[x];i<=r[x];i++)
    {
        int pre=sum;
        sum^=i;
        DFS(x+1,deep);
        sum=pre;
    }
}
signed main()
{
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        sum=0;
        ans=0;
        DFS(1,i);
        cout<<ans%mod<<endl;
    }
}