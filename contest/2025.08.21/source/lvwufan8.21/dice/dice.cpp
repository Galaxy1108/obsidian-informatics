#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[6000],b[6000];
int mod=1000000007;
int li[10];
int maxn=0,maxa=0;
void DFS(int deep)
{
    if(deep>n)
    {
        li[maxn]++;
        return;
    }
    for(int i=1;i<=a[deep];i++)
    {
        int pre=maxn;
        maxn=max(maxn,i);
        DFS(deep+1);
        maxn=pre;
    }
}
int yuan(int x)
{
    if((mod+1)%x==0)
    {
        return (mod+1)/x;
    }
    else
    {
        int k=2;
        while((k*mod+1)%x!=0)
        {
            k++;
        }
        return (k*mod+1)/x;
    }
}
int pow(int x,int n)
{
    int sum=1;
    while(n--)
    {
        sum*=x;
        sum%=mod;
    }
    return sum%mod;
}
signed main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    cin>>n;
    b[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
        b[i]=b[i-1]*a[i];
    }
    sort(a+1,a+n+1);
    a[0]=1;
    int k=1;
    int num=1;
    int sum=0;
    int tot=0;
    if(n>5)
    {
        while(k<=a[n]&&num<=n)
        {
            if(k>a[num])
            {
                num++;
            }
            int pre=tot;
            tot=tot+b[num-1]%mod*(pow(k,n-num+1)%mod-pow(k-1,n-num+1)%mod+mod)%mod;
            tot%=mod;
            sum=sum+(tot-pre)*k%mod;
            sum%=mod;
            k++;
        }
        int ni=yuan(tot);
        ni%=mod;
        sum%=mod;
        cout<<ni*sum%mod;
    }
    else
    {
        DFS(1);
        for(int i=1;i<=maxa;i++)
        {
            sum+=i*li[i];
            sum%=mod;
            tot+=li[i];
        }
        int ni=yuan(tot)%mod;
        cout<<sum*ni%mod<<endl;
    }
}