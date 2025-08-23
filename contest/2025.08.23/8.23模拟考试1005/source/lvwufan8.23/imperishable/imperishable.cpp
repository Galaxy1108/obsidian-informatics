#include<bits/stdc++.h>
using namespace std;
int n;
int num;
int a[200005];
int maxn[200005];
int q;
int x,y;
int mod=998244353;
int powq(int x,int k)
{
    int sum=1;
    while(k)
    {
        if(k&1)
        {
            sum*=x%mod;
            sum%=mod;
        }
        k>>=1;
        x*=x;
        x%=mod;
    }
    return sum%mod;
}
int calc(int l,int r)
{
    if(a[l]>=maxn[l+1])
    {
        return powq(2,l);
    }
    else
    {
        int x=l+1;
        int sum=a[l];
        for(;x<=r;x++)
        {
            sum+=a[x];
            if(sum>=maxn[x+1])
            {
                break;
            }
        }
        long long ans=1;
        for(int i=l;i<=x;i++)
        {
            sum+=powq(2,i);
        }
        return sum;
    }
}
int main()
{
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    cin>>num;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    maxn[i+1]=-1;
    for(int i=n;i>=1;i--)
    {
        maxn[i]=max(maxn[i+1],a[i]);
    }
    while(q--)
    {
        cout<<calc(1,n)<<endl;
    }
}
