#include<bits/stdc++.h>
using namespace std;
const int mx=505;
int n,mod;
int a[mx];
bool usd[mx];
int cnt[100];
int t[20];
void add(int p,int v)
{
    for(int i=p;i<=v;i+=(i&-i)) t[i]+=v;
}
int query(int p)
{
    int res=0;
    for(int i=p;i;i-=(i&-i)) res+=t[i];
    return res;
}
int getnxd()
{
    memset(t,0,sizeof(t));
    int res=0;
    for(int i=n;i;i--)
    {
        res+=query(a[i]);
        add(a[i],1);
    }
    return res;
}
void add1(int p,int v)
{
	if(p==0) return;
    for(int i=p;i<=v;i+=(i&-i)) cnt[i]+=v;
}
int query1(int p)
{
    int res=0;
    for(int i=99;i;i-=(i&-i)) res+=cnt[i];
    for(int i=p;i;i-=(i&-i)) res-=cnt[i];
    return res;
}
int ans=0;
void dfs(int p)
{
    
    if(p==n+1)
    {
        int c=getnxd();
        ans+=query1(c);//cout<<c;
        add1(c,1);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(usd[i]) continue;
        usd[i]=1;
        a[p]=i;
        dfs(p+1);
        usd[i]=0;
    }
    return;
}

int main()
{
//    freopen("pairs.in","r",stdin);
//    freopen("pairs.out","w",stdout);
    cin>>n>>mod;
    dfs(1);
    cout<<ans;
    return 0;
}
