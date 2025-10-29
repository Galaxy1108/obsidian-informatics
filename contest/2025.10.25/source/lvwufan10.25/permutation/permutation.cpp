#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int b[1010];
bool tick[1010];
int pos[1010];
int l=0;
int len=0;
//3,628,800
int ans[3628801][11];
int sum=0;
int r[1010];
bool check()
{
    if(sum==0)
    {
        return true;
    }
    for(int i=1;i<=sum;i++)
    {
        bool f=0;
        for(int j=1;j<=n;j++)
        {
            if(ans[i][j]!=b[j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            return false;
        }
    }
    return true;
}
void SA()
{
    for(int i=1;i<=2*n;i++)
    {
        int p1=rand()%(2*n)*i%(2*n)+1;
        int p2=(rand()+3)%(2*n)*i%(2*n)+1;
        swap(r[p1],r[p2]);
    }
}
void DFS(int dep)
{
    if((double)clock()/CLOCKS_PER_SEC>=0.99)
    {
        cout<<sum;
        exit(0);
    }
    if(dep>l)
    {
        len++;
        for(int i=1;i<=n;i++)
        {
            b[i]=min(a[2*i-1],a[2*i]);
        }
        if(check())
        {
            sum++;
            for(int i=1;i<=n;i++)
            {
                ans[sum][i]=b[i];
            }
        }
        return;
    }
    else
    {
        for(int j=1;j<=2*n;j++)
        {
            int i=r[j];
            if(tick[i]==0)
            {
                tick[i]=1;
                a[pos[dep]]=i;
                DFS(dep+1);
                tick[i]=0;
            }
        }
    }
}
int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    srand(time(0));
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        r[i]=i;
        cin>>a[i];
        if(a[i]!=-1)
        {
            tick[a[i]]=1;
        }
        else
        {
            pos[++l]=i;
        }
    }
    SA();
    if(l==0)
    {
        cout<<1;
        return 0;
    }
    else
    {
        DFS(1);
        cout<<sum;
        return 0;
    }
}