#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,y;
namespace solve
{
    vector<int>cur,ans;
    bool Mobius(int lim,int a,int b,int e)
    {
        if(lim==0)
        {
            if(a==0 && (ans.empty() || cur.back()<ans.back()))ans=cur;
            return a==0;
        }
        int g=__gcd(a,b);
        a/=g;
        b/=g;
        bool flg=0;
        if(b>a*1e4)return 0;
        for(int ex=max(e+1,(b+a-1)/a);;ex++)
        {
            if(lim*b<a*ex)return flg;
            cur.push_back(ex);
            flg|=Mobius(lim-1,a*ex-b,b*ex,ex);
            cur.pop_back();
        }
        return flg;
    }

    void solve()
    {
        if(x==0)return cout<<0,void();
        int cnt=0;
        for(int dep=1;dep<=100;dep++)
            if(Mobius(dep,x,y,1))
            {
                cnt=dep;
                break;
            }
                
        if(!cnt)return cout<<0,void();
        cout<<cnt<<"\n";
        for(int i:ans)cout<<i<<" ";
    }
}
signed main()
{
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>x>>y;
    solve::solve();
    return 0;
}
