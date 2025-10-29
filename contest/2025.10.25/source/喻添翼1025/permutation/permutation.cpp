#include<bits/stdc++.h>
using namespace std;
const int mx=310;
const int mod=1e9+7;
int n;
int a[mx*2],b[mx];
bool vis[mx*2],usd[mx*2];
unordered_map<string,bool> mp;
int ans=0;

void dfs(int k)
{
    if(k==n*2+1)
    {
        string s="";
        for(int i=1;i<=n;i++)
        {
            b[i]=min(a[i*2],a[i*2-1]);
            s+=char(b[i]+'0');
        }
        if(!mp[s]) ans++,mp[s]=1;
        return;
    }
    if(vis[k]) dfs(k+1);
    else
    {
        for(int i=1;i<=n*2;i++)
        {
            if(!usd[i])
            {
                usd[i]=1;
                a[k]=i;
                dfs(k+1);
                usd[i]=0;
            }

        }
    }
}
int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n*2;i++) 
    {
        cin>>a[i];
        if(a[i]!=-1) vis[i]=1,usd[a[i]]=1;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
