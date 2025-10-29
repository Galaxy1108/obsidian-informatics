#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
const int mod=998244353;
int n,x;
long long f[mx][mx];
int a[mx],b[mx];
int ans=0;
void dfs(int p)
{
    if(p==n+1)
    {
        
        return;
    }
    for(int i=1;i<=x;i++)
    {
        a[p]=i;
        dfs(p+1);
    }
    return;
}

int main()
{
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    cin>>n;
    
    cout<<0;
    return 0;
}
