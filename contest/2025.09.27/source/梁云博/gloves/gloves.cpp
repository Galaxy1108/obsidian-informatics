#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int n,m,len;
int L[N],R[N];

bool check(int mid)
{
    int li=1,ri=1,cnt=0;
    while(li<=n && ri<=m)
    {
        if(abs(L[li]-R[ri])>mid)
        {
            if(L[li]>R[ri])ri++;
            else li++;
        }
        else li++,ri++,cnt++;
    }
    return cnt>=len;
}

signed main()
{
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    len=min(n,m);
    for(int i=1;i<=n;i++)cin>>L[i];
    for(int i=1;i<=m;i++)cin>>R[i];
    sort(L+1,L+1+n);
    sort(R+1,R+1+m);
    int l=0,r=1e9,res=-1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))
        {
            r=mid-1;
            res=mid;
        }
        else l=mid+1;
    }
    cout<<res;
    return 0;
}