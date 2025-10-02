#include <bits/stdc++.h>
#define N 2000006
using namespace std;
int a[N],n,k;
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    for(int x=1;x<=T;x++)
    {
        if(x==1)
        {
            cin>>n;
            for(int i=1;i<=n;i++)cin>>a[i];
            if(n==3)
            {
                if(a[3]-a[1]>=a[2])cout<<"1\n";
                else cout<<"3\n";
            }
        }
        else
        {
            cin>>k;
            for(int i=1,u,v;i<=k;i++)cin>>u>>v,a[u]=v;
            if(n==3)
            {
                if(a[3]-a[1]>=a[2])cout<<"1\n";
                else cout<<"3\n";
            } 
        }
        
    }
	
	return 0;
}