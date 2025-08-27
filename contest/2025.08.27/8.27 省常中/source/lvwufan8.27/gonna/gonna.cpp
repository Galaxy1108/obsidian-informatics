#include<bits/stdc++.h>
using namespace std;
__int128 a[51][51];
int f[55];
int g[55];
int n,p;
int prime[700001];
int num[700001];
int len=0;
bool tick[10000001];
int prime1[700001];
int num1[700001];
int len1=0;
int sum=0;
__int128 fac=1;
void ola(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(tick[i]==0)
        {
            prime[++len]=i;
        }
        for(int j=1;j<=len;j++)
        {
            if(i*prime[j]<=n)
            {
                tick[i*prime[j]]=1;
            }
            else
            {
                break;
            }
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
void fen(__int128 x)
{
    int i=1;
    while(i<=len)
    {
        if(x%prime[i]==0)
        {
            num[i]++;
            x/=prime[i];
        }
        else
        {
            i++;
        }
    }
    if(x!=1)
    {
        prime[++len]=x;
        num[len]=1;
    }
}
void DFS(int deep)
{
    if(deep>len1)
    {
        sum+=fac%p;
        sum%=p;
        return;
    }
    int pr=prime1[deep];
    for(int i=0;i<=num1[deep];i++)
    {
        __int128 y=1;
        if(i>0)
        {
            for(int j=1;j<=i;j++)
            {
                y*=pr;
            }
        }
        fac*=y;
        DFS(deep+1);
        fac/=y;
    }
}
int main()
{
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
    cin>>n>>p;
    ola(10000000);
    for(int i=0;i<=n;i++)
    {
        a[0][i]=a[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(num,0,sizeof(num));
        for(int k=0;k<=i;k++)
        {
            int j=i-k;
            fen(a[k][j]);
        }
        for(int j=0;j<=len1;j++)
        {
            prime1[j]=num1[j]=0;
        }        
        len1=0;
        for(int j=1;j<=len;j++)
        {
            if(num[j]>0)
            {
                len1++;
                prime1[len1]=prime[j];
                num1[len1]=num[j];
            }
        }
        sum=0;
        fac=1;
        DFS(1);
        ans+=sum%p;
        ans%=p;
    }
    cout<<ans;
}