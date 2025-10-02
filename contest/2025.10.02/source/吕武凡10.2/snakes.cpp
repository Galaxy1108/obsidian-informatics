#include<bits/stdc++.h>
using namespace std;
int n,t;
int k,x,y;
int a[1000005],b[1000005];
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        if(i==1)
        {
            cin>>n;
            for(int j=1;j<=n;j++)
            {
                cin>>a[j];
            }
        }
        else
        {
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                cin>>x>>y;
                a[x]=y;
            }
        }
        for(int j=1;j<=n;j++)
        {
            b[j]=a[j];
        }
        int head=1,tail=n;
        while(a[tail]-a[head]>=a[tail-1]&&head<=tail)
        {
            b[tail]-=b[head];
            head++;
            int p=tail;
            while(b[p]<b[p-1]&&p>head)
            {
                swap(b[p-1],b[p]);
                p--;
            }
        }
        if(tail-head+1!=2) cout<<tail-head+1<<endl;
        else cout<<1<<endl;
    }
}