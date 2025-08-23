#include<bits/stdc++.h>
using namespace std;
int type,n,m,k;
struct point
{
    int x,y;
}e[100005];
int Q;
int w;
int x,y,q;
void DFS(int a,int b,int deep,int fang)
{   
    if(deep>q)
    {
        cout<<a<<" "<<b<<endl;
        return;
    }
    if(fang==1)
    {
        int jin=n+1;
        for(int i=1;i<=k;i++)
        {
            if(a<e[i].x&&b==e[i].y&&e[i].x<jin)
            {
                jin=e[i].x;
            }
        }
        if(jin==n+1)
        {
            cout<<n+1<<" "<<b<<endl;
            return;
        }
        else
        {
            DFS(jin,b,deep+1,0);
        }
    }
    if(fang==0)
    {
        int jin=m+1;
        for(int i=1;i<=k;i++)
        {
            if(a==e[i].x&&b<e[i].y&&e[i].y<jin)
            {
                jin=e[i].y;
            }
        }
        if(jin==m+1)
        {
            cout<<a<<" "<<m+1<<endl;
            return;
        }
        else
        {
            DFS(a,jin,deep+1,1);
        }
    }
}
int main()
{
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    cin>>type>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>e[i].x>>e[i].y;
    }
    cin>>Q;
    while(Q--)
    {
        cin>>w;
        if(w==1)
        {
            cin>>x>>y;
            k++;
            e[k].x=x;
            e[k].y=y;
        }
        else
        {
            cin>>x>>y>>q;
            if(x==0)
            {
                DFS(1,y,1,1);
            }
            else
            {
                DFS(x,1,1,0);
            }
        }
    }
}
