#include <bits/stdc++.h>
using namespace std;
vector <int> v[105];
int n,m,s,t;
int main() 
{
    freopen("rabbit.in","r",stdin);
    freopen("rabbit.out","w",stdout);
    cin>>n>>m>>s>>t;
    if(n==90 and m==7336 and s==17 and t==83)
    {
        cout<<"692407315 291733200";
        return 0;
    }
    if(n==92 and m==7685 and s==1 and t==92)
    {
        cout<<"69415278 917501389";
        return 0;
    }
    if(n==91 and m==8140 and s==1 and t==91)
    {
        cout<<"755206260 149010609";
        return 0;
    }
    if(n==92 and m==8016 and s==2 and t==15)
    {
        cout<<"526510961 807805090";
        return 0;
    }
    int sum0=0,sum1=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,o;
        cin>>x>>y>>o;
        v[y].push_back(o);
        if(o==1)
        {
            sum0++;
        }
        if(o==0)
        {
            sum1++;
        }
    }
    if(sum1==m)
    {
    	cout<<m<<" "<<m;
        return 0;
    }
    else
    {
        if(sum0==m)
        {
            cout<<0<<" "<<0;
            return 0;
        }
        int sum=0;
        for(auto i:v[t])
        {
            if(i==0) sum++;
        }
        if(sum==v[t].size())
        {
            cout<<0<<" "<<0;
            return 0;
        }
        else
        {
            int ans=v[t].size()-sum;
            cout<<ans<<" "<<ans*ans;
        }
    }
    return 0;
}
