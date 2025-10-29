#include<bits/stdc++.h>
using namespace std;
int n;
bool a[100010];
int m;
int op;
int x,y;
int calc(int x)
{
    if(x%2==0)
    {
        return 0;
    }
    if(x==1)
    {
        return 1e9;
    }
    return 2;
}
bool check(int l,int r)
{
    if(l==r)
    {
        if(a[l]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int n0=0,n1=0;
    for(int i=l;i<=r;i++)
    {
        if(a[i]==0)
        {
            n0++;
        }
        else
        {
            n1++;
        }
    }
    if(n0>=calc(n1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            a[x]=!a[x];
        }
        else
        {
            cin>>x>>y;
            int ans=0;
            int n0=0,n1=0;
            for(int l=x;l<=y;l++)
            {
                n0=n1=0;
                for(int r=l;r<=y;r++)
                {
                    if(a[r]==1)
                    {
                        n1++;
                    }
                    else
                    {
                        n0++;
                    }
                    if(n0>=calc(n1))
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}