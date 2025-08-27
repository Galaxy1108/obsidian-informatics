#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int tot=0;
int id;
int n,x;
int a,b;
int head[1000001];
int jie[50010];
struct Edge
{
    int nx,to;
}e[1000001];
void edge(int u,int v)
{
    e[++tot].nx=head[u];
    e[tot].to=v;
    head[u]=tot;
}
long long powq(long long x,long long k)
{
    long long sum=1;
    while(k)
    {
        if(k&1)
        {
            sum*=x%mod;
            sum%=mod;
        }
        x=x%mod*x%mod;
        k>>=1;
    }
    return sum%mod;
}
long long ins(long long x)
{
    return powq(x,mod-2)%mod;
}
void c(int x,int y)
{
    jie[0]=1;
    for(int i=1;i<=y;i++)
    {
        jie[i]=1ll*jie[i-1]%mod*i%mod;
    }
    cout<<jie[y]%mod*ins(jie[y-x]%mod*jie[x]%mod)%mod<<" ";
}
int main()
{
    freopen("youup.in","r",stdin);
    freopen("youup.out","w",stdout);
    cin>>id;
    cin>>n>>x;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        edge(a,b);
    }
    if(x==0)
    {
        cout<<n<<" ";
        for(int i=1;i<n;i++)
        {
            cout<<"0 ";
        }
        return 0;
    }
    if(id==1)
    {
        cout<<n<<" ";
        for(int i=1;i<n;i++)
        {
            cout<<"0 ";
        }
        return 0;
    }
    if(id==4||id==2)
    {
        if(x==0)
        {
            cout<<n<<" ";
            for(int i=1;i<n;i++)
            {
                cout<<"0 ";
            }
            return 0;
        }
        if(x==1)
        {
            cout<<n<<" "<<n-1<<" ";
            for(int i=1;i<n-1;i++)
            {
                cout<<"0 ";
            }
            return 0;
        }
        if(x>=2)
        {
            for(int i=1;i<=n;i++)
            {
                c(i,n);
            }
            return 0;
        }
    }
    if(id==5||id==3)
    {
        for(int i=0;i<=x;i++)
        {
            cout<<n-i<<" ";
        }
        for(int i=1;i<=n-x-1;i++)
        {
            cout<<"0 ";
        }
        return 0;
    }
}