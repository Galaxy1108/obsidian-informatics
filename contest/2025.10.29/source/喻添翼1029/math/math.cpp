#include<bits/stdc++.h>
using namespace std;
const int mx=45;
int A,B;
int a[mx*2];
vector<int> ans;
long long gcd(long long a,long long b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return 1ll*a/gcd(a,b)*b;
}
pair<long long,long long> del(long long x,long long y,long long xx,long long yy)
{
    long long gfm=lcm(y,yy);
    long long gfz=gfm/y*x-gfm/yy*xx;
    return make_pair(gfz,gfm);
}
void dfs(int a,int b)
{
    for(int i=2;i<=1005;i++)
    {
        long long fz=del(a,b,1,i).first;
        long long fm=del(a,b,1,i).second;
        if(fz>=0)
        {
            cout<<fz<<' '<<fm<<endl;
            a=fz,b=fm;
            ans.push_back(i);
        }
        if(a==0) break;
    }
}
int main()
{
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    cin>>A>>B;
    if(A==0) cout<<0;
    else 
    {
        dfs(A,B);
        cout<<ans.size()<<endl;
        for(int i:ans) cout<<i<<' ';
    }
    return 0;
}
