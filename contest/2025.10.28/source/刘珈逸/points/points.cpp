#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f3f3f3f3f;
set<int>st;
map<int,int>mp;
int n,m,a[N];
struct Seg{
    int l,r;
}tmp[N],sg[N];
int cur;
bool operator<(Seg x,Seg y){
    return x.l==y.l?x.r<y.r:x.l>y.l;
}
int get(int l,int r){
    auto it1=*(st.lower_bound(l)),it2=*prev(st.upper_bound(r));
    if(it1==it2&&mp[it1]==1)return 1;
    if(it1>it2)return 0;
    return 2;
}
typedef long long ll;
ll dp[N];
signed main(){
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    st.insert(-inf),st.insert(inf);
    for(int i=1;i<=n;i++)scanf("%lld",a+i),st.insert(a[i]),mp[a[i]]++;
    for(int i=1;i<=m;i++)scanf("%lld%lld",&sg[i].l,&sg[i].r);
    sort(sg+1,sg+1+m);
    for(int i=1,lst=inf;i<=m;i++){
        if(lst>sg[i].r)tmp[++cur]=sg[i];
        lst=min(lst,sg[i].r);
    }swap(sg,tmp);
    m=cur;cur=0;
    for(int i=1;i<=m;i++)if(!get(sg[i].l,sg[i].r))tmp[++cur]=sg[i];
    swap(sg,tmp);
    m=cur,cur=0;
    reverse(sg+1,sg+1+m);
    ll v1=inf,v2=inf;
    memset(dp,0x3f,sizeof(dp));dp[0]=0;
    ll lst=-inf,ans=0,lv=0;
    for(int i=1,j;i<=m;i=j+1){
        j=i;
        while(j<m&&!get(sg[j].r,sg[j+1].l))j++;
        for(int k=i;k<=j;k++){
            int pos=*prev(st.upper_bound(sg[i].l));
            dp[k]=sg[k].l-lst;
            if(pos!=-inf)dp[k]=min(dp[k],dp[i-1]+sg[k].l-pos);
            dp[k]=min(dp[k],v1+sg[k].l);
            dp[k]=min(dp[k],v2+2*sg[k].l);
        }
        int pos=*(st.lower_bound(sg[j].r));
        v1=pos-sg[i].r*2ll+lv,v2=-(pos+sg[i].r)+lv;
        for(int k=i+1;k<=j;k++){
            v1=min(v1,dp[k-1]+(pos-sg[k].r*2ll));
            v2=min(v2,dp[k-1]-(pos+sg[k].r));
        }
        if(j==m||get(sg[j].r,sg[j+1].l)==2){
            ans+=min(v2+pos*2ll,dp[j]);
            v1=inf,v2=inf;
            lst=*prev(st.upper_bound(sg[j+1].l));
            dp[j]=0;
        }else lv=min(v2+pos*2ll,dp[j]);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
首先把被完全包含的区间去掉
把已经包含了一个点的区间也去掉
若缝隙中点数>=2不用管

*/