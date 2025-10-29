#include<bits/stdc++.h>
using namespace std;
const int mx=45;
int n;
string s[mx];
int a[mx*2];
bool usd[mx],vis[mx*2];
void pp()
{
    for(int i=1;i<=n*2;i++)
        cout<<s[a[i]]<<"\n";
}
bool flag=0;
void dfs(int p)
{
    if(p==2*n+1)
    {
        pp();
        flag=1;
        return;
    }
    if(flag) return;
    if(vis[p]) 
    {
        dfs(p+1);
        return;
    }
    for(int i=n;i;i--)
    {
        if(usd[i]) continue;
        if(p+i+1>2*n||vis[p+i+1]) continue;
        a[p]=i,a[p+i+1]=i;
        usd[i]=1;
        vis[p]=1,vis[p+i+1]=1;
        dfs(p+1);
        usd[i]=0;
        vis[p]=0,vis[p+i+1]=0;
    }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    dfs(1);
    return 0;
}
