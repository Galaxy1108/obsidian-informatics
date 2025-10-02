#include <bits/stdc++.h>
using namespace std;
#define il inline
#define fi first
#define se second
const int N=1e6+5;
int n,a[N],b[N];
struct node
{
    int h,t,q[N<<1],num[N<<1],id[N<<1];
    void push(int x,int now,int ttt){q[t]=x,num[t]=now,id[t]=ttt;t++;}
    int size(){return t-h;}
    pair<int,int> top(){return make_pair(q[h],id[h]);}
    pair<int,int> back(){return make_pair(q[t-1],id[t-1]);}
    void pop_top(){h++;}
    void pop_back(){t--;}
    void pop(){h++,t--;}
    int tui_back(){return num[t-1];}
    int tui_top(){return num[h];}
}q1,q2;
bool cmp(int x,int y){return x>y;}
int ans=-1;
il void dfs(int x)
{
    // cout<<x<<'\n';
    // cout<<"q1:";
    // for(int i=q1.h;i<q1.t;i++)cout<<q1.q[i]<<' ';cout<<'\n';
    // cout<<"q2:";
    // for(int i=q2.h;i<q2.t;i++)cout<<q2.q[i]<<' ';cout<<'\n';
    // cout<<'\n';
    if(!q2.size())
    {
        if(q1.size()!=1)
        {
            q2.push(q1.top().fi-q1.back().fi,x,q1.top().se);
            q1.pop();    
        }
    }
    else if(q1.top()<q2.top())
    {
        int t1=q1.top().fi,t2=q2.top().fi,t3=q1.back().fi,t4=q2.back().fi;
        if(q1.back()<q2.back())
        {
            q1.pop_back(),q2.pop_top();
            q2.push(t2-t3,x,q2.top().se);
        }
        else {
            ans=n-q2.tui_back();return;
            q2.pop();
            q2.push(t2-t4,x,q2.top().se);
        }
    }
    else{//q1.top
        int t1=q1.top().fi,t2=q2.top().fi,t3=q1.back().fi,t4=q2.back().fi;
        if(q1.back()<q2.back())
        {
            q1.pop();
            q2.push(t1-t3,x,q1.top().se);
        }
        else {
            ans=n-q2.tui_back();return;
            q1.pop_top(),q2.pop_back();
            q2.push(t1-t4,x,q1.top().se);
        }
    }
    if(x==n-1){ans=1;return;}dfs(x+1);
}
il void solve()
{
    int k;
    cin>>k;
    for(int i=1,x,y;i<=k;i++){cin>>x>>y;a[x]=y;}
    for(int i=1;i<=n;i++)b[i]=a[i];
    sort(b+1,b+n+1,cmp);
    q1.h=q1.t=q2.h=q2.t=1;
    for(int i=1;i<=n;i++)q1.push(b[i],0,i);ans=-1;
    dfs(0);cout<<ans<<'\n';
}
int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int T;cin>>T>>n;
    for(int i=1;i<=n;i++)cin>>a[i];T--;
    for(int i=1;i<=n;i++)b[i]=a[i];
    sort(b+1,b+n+1,cmp);
    q1.h=q1.t=q2.h=q2.t=1;
    for(int i=1;i<=n;i++)q1.push(b[i],0,i);ans=-1;
    dfs(0);cout<<ans<<'\n';
    while(T--)solve();
    return 0;
}
/*
1
5
7 10 24 48 50

1
3
5 6 25

*/