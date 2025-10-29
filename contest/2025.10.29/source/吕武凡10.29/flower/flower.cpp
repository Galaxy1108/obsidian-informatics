#include<bits/stdc++.h>
using namespace std;
int n;
string a[100];
int ans[200];
bool tick[200];
void DFS(int dep)
{
    if(dep==0)
    {
        for(int i=1;i<=2*n;i++)
        {
            cout<<a[ans[i]]<<endl;
        }
        exit(0);
        return;
    }
    for(int l=1,r=l+dep+1;l<=2*n&&r<=2*n;l++,r++)
    {
        if(tick[l]==0&&tick[r]==0)
        {
            tick[l]=tick[r]=1;
            ans[l]=ans[r]=dep;
            DFS(dep-1);
            tick[l]=tick[r]=0;
        }
    }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(tick,0,sizeof(tick));
    DFS(n);
}