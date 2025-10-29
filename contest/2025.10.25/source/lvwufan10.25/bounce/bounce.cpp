#include<bits/stdc++.h>
using namespace std;
int n,q;
int tp,m;
bool tick[100010];
int find(int x)
{
    x++;
    while(x<=n)
    {
        if(tick[x]==1)
        {
            return x;
        }
        x++;
    }
    return 0;
}
int find2(int x)
{
    x--;
    while(x>=1)
    {
        if(tick[x]==1)
        {
            return x;
        }
        x--;
    }
    return 0;
}
int last;
void work2()
{
    int p=find(0);
    tick[p]=0;
    last=p;
    while(p<=n)
    {
        for(int j=1;j<=m;j++)
        {
            int k=find(p);
            if(k==0)
            {
                p=0;
                break;
            }
            p=k;
        }
        if(p==0)
        {
            break;
        }
        tick[p]=0;
        last=p;
    }
}
void fan()
{
    int p=find(n+1);
    tick[p]=0;
    last=p;
    while(p>=1)
    {
        for(int j=1;j<=m;j++)
        {
            int k=find2(p);
            if(k==0)
            {
                p=0;
                break;
            }
            p=k;
        }
        if(p==0)
        {
            break;
        }
        tick[p]=0;
        last=p;
    }
}
void work3()
{
    for(int i=1;i<=20;i++)
    {
        work2();
        fan();
    }
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        tick[i]=1;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>tp>>m;
        if(tp==3)
        {
            work3();
            cout<<last<<endl;
        }
        if(tp==1)
        {
            int p=1;
            while(p<=n)
            {
                tick[p]=0;
                p+=m;
            }
        }
        if(tp==2)
        {
            work2();
        }
        for(int i=1;i<=n;i++)
        {
            cout<<tick[i]<<" ";
        }
        cout<<endl;
    }
}