#include<bits/stdc++.h>
using namespace std;
int n;
int a[100],b[100];
bool tick[100];
int ans=0;
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]&&tick[j]==0)
            {
                ans+=abs(i-j);
                tick[j]=1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}