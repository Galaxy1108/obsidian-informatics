
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define N 1000005
using namespace std;
int n,q;
int tp,m;
bitset<N>vis,tmp;
bitset<21>op1;
namespace solve1
{

    int pre(int cur)
    {
        for(int i=cur-1;i>=1;i--)if(vis[i])return i;
        return -1;
    }

    void solve()
    {
        vis.set();
        vis[0]=0;
        int cnt=n;
        while(q--)
        {
            cin>>tp>>m;
            if(tp==1)
            {
                if(op1[m])continue;
                op1[m]=1;
                int cur=1;
                while(cur<=n)
                {
                    vis[cur]=0;
                    cnt--;
                    cur+=m;
                }
            }
            else if(tp==2)
            {
                if(vis.none())continue;
                int cur=vis._Find_first();
                while(cur<=n)
                {
                    vis[cur]=0;
                    cnt--;
                    for(int i=1;i<=m && cur<=n;i++)cur=vis._Find_next(cur);
                    if(cur>n)continue;
                }
            }
            else
            {
            	tmp=vis;
            	int cntp=cnt;
                if(vis.none())cout<<"-1\n";
                int lst=0;
                while(cnt)
                {
                    int cur=vis._Find_first();
                    while(cur<=n)
                    {
                        vis[cur]=0;
                        cnt--;
                        lst=cur;
                        for(int i=1;i<=m && cur<=n;i++)cur=vis._Find_next(cur);
                        if(cur>n)continue;
                    }
                    
                    
                    cur=pre(n+1);
                    while(cur>=1)
                    {
                        vis[cur]=0;
                        cnt--;
                        lst=cur;
                        for(int i=1;i<=m && cur<=n;i++)cur=pre(cur);
                        if(cur<1)continue;
                    }
                }
                cout<<lst<<"\n";
                vis=tmp;
                cnt=cntp;
            }

        }
    }
}

namespace solve2
{
    using namespace __gnu_pbds;
    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t,trr;
    void solve()
    {
        vis.set();
        vis[0]=0;
        int cnt=n;
        for(int i=1;i<=n;i++)t.insert(i);
        while(q--)
        {
            cin>>tp>>m;
            if(tp==1)
            {
                if(op1[m])continue;
                op1[m]=1;
                int cur=1;
                while(cur<=n)
                {
                    t.erase(cur);
                    vis[cur]=0;
                    cnt--;
                    cur+=m;
                }
            }
            else if(tp==2)
            {
                int cur=*t.find_by_order(0);
                int rk=1;
                while(cur<=n)
                {
                    vis[cur]=0;
                    cnt--;
                    t.erase(cur);
                    rk+=m-1;
                    auto it=t.find_by_order(rk-1);
                    cur=it==t.end()?n+1:*it;
                    if(cur>n)break;
                }
            }
            else
            {
            	tmp=vis;
                trr=t;
            	int cntp=cnt;
                if(t.empty())
                {
                    cout<<"-1\n";
                    continue;
                }
                int lst=0;
                while(cnt)
                {
                    int cur=*t.find_by_order(0);
                    int rk=1;
                    while(cur<=n)
                    {
                        vis[cur]=0;
                        cnt--;
                        lst=cur;
                        t.erase(cur);
                        rk+=m-1;
                        auto it=t.find_by_order(rk-1);
                        cur=it==t.end()?n+1:*it;
                        if(cur>n)break;
                    }
                    if(!cnt)break;

                    rk=cnt;
                    cur=*t.find_by_order(cnt-1);
                    while(cur>=1)
                    {
                        vis[cur]=0;
                        cnt--;
                        lst=cur;
                        t.erase(cur);
                        rk-=m;
                        auto it=t.find_by_order(rk-1);
                        cur=it==t.begin()?-1:*it;
                        if(cur<1)break;
                    }
                }
                cout<<lst<<"\n";
                vis=tmp;
                cnt=cntp;
                t=trr;
            }

        }
    }

}



int main()
{
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    // if(n<=1000)
    // solve1::solve();
    solve2::solve();
    return 0;
}