#include<bits/stdc++.h>
using namespace std;
const int mx=505;
const int mod=998244353;
int n,m;
long long f[mx][mx];
int a[mx];
struct line
{
    int l,r;
}b[mx];
bool cmp1(line x,line y)
{
    if(x.l==y.l) return x.r>y.r;
    return x.l<y.l;
}
bool cmp2(line x,line y)
{
    if(x.l==y.l) return x.r<y.r;
    return x.l<y.l;
}
bool ok[mx];
long long ans=0;

int main()
{
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i].l>>b[i].r;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m,cmp1);
    for(int i=1;i<=m;i++) ok[i]=1;
    for(int i=1;i<m;i++)
        if(b[i].r>=b[i+1].r) ok[i]=0;
    sort(b+1,b+1+m,cmp2);
    int p=1;
    for(int i=1;i<=m;i++)
    {
        while(b[i].l>a[p]&&p<=n) p++;
        if(a[p]>=b[i].l&&a[p]<=b[i].r) ok[i]=0;
    }
    vector<line> v,v1;
    for(int i=1;i<=m;i++) if(ok[i]) v.push_back(b[i]);
    // int L=v[1].l,R=v[1].r;
    // for(int i=1;i<v.size();i++)
    // {
    //     if
    // }
    p=1;
    for(int i=0;i<v.size();i++)
    {
        int res=0;
        while(v[i].l>a[p]&&p<=n) p++;
        res=min(v[i].l-a[p-1],a[p]-v[i].r);
        ans+=res;
    }
    cout<<ans;
    return 0;
}
