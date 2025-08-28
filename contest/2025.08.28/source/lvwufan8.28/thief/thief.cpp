#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int l,r,s;
int main()
{
    freopen("thief.in","r",stdin);
    freopen("thief.out","w",stdout);
    //ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r>>s;
        int c=s;
        for(int j=l;j<=r;j++)
        {
            if(c<a[j])
            {
                c++;
            }
            if(c>a[j])
            {
                c--;
            }
        }
        cout<<c<<endl;
    }
}