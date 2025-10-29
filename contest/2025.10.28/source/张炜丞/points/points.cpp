#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,inf=1e18;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,m,vn,a[N],g[N],f[N],dp[N],mi1[N],mi2[N],p[N];
// vector<int> nums;
struct node{
    int l,r;
    bool operator<(const node &n1)const{
        return r==n1.r?l>n1.l:r<n1.r;
    }
}b[N];

struct node2{
    int x,id,op;
    bool operator<(const node2 &n2)const{
        return x==n2.x?id<n2.id:x<n2.x;
    }
}c[N<<1];

// inline int ma(int x){
//     return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
// }

signed main(){
    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);
    n=read();m=read();
    int cm=0;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;++i){
        b[++cm].l=read();b[cm].r=read();
        // cout<<" i:"<<i<<" l:"<<b[cm].l<<" r:"<<b[cm].r<<endl;
        int p=lower_bound(a+1,a+n+1,b[cm].l)-a;
        // cout<<" p:"<<p<<" l:"<<b[cm].l<<
        // cout<<" l:"<<b[cm].l<<" p:"<<a[p]<<" r:"<<b[cm].r<<endl;
        if(b[cm].l<=a[p]&&a[p]<=b[cm].r)--cm;
    }
    // cout<<" ddd"<<endl;
    m=cm;
    sort(b+1,b+m+1);
    // cout<<" m:"<<m<<endl;
    cm=1;
    for(int i=2;i<=m;++i){
        if(b[i].l<=b[cm].l&&b[cm].r<=b[i].r)continue;
        b[++cm]=b[i];
    }
    a[++n]=1e17;
    m=cm;
    int cnt=0;
    for(int i=1;i<=n;++i){
        c[++cnt]={a[i],i,0};
        // if(a[i]<a[i-1]){
        //     cout<<" i:"<<i<<" a:"<<a[i]<<" a-1:"<<a[i-1]<<endl;
        // }
    }
    for(int i=1;i<=m;++i){
        c[++cnt]={b[i].r,i,1};
        // cout<<" i:"<<i<<" l:"<<b[i].l<<" r:"<<b[i].r<<endl;
    }
    sort(c+1,c+cnt+1);
    for(int i=1;i<=cnt;++i){
        if(c[i].op==0)p[c[i].id]=i;
    }
    // nums.push_back(-inf);
    // for(int i=1;i<=n;++i)nums.push_back(a[i]);
    // for(int i=1;i<=m;++i)nums.push_back(b[i].l),nums.push_back(b[i].r);
    // sort(nums.begin(),nums.end());
    // nums.erase(unique(nums.begin(),nums.end()),nums.end());
    // for(int i=1;i<=n;++i)a[i]=ma(a[i]);
    // for(int i=1;i<=m;++i)b[i].l=ma(b[i].l),b[i].r=ma(b[i].r);
    // vn=nums.size()-1;
    memset(f,0x3F,sizeof(f));
    memset(g,0x3F,sizeof(g));
    memset(dp,0x3F,sizeof(dp));
    memset(mi1,0x3F,sizeof(mi1));
    memset(mi2,0x3F,sizeof(mi2));
    if(p[1]!=1){
        f[1]=a[1]-b[1].r;
        for(int i=2;i<p[1];++i)f[c[i].id]=inf;
        dp[1]=inf;
    }
    else dp[1]=0;
    for(int i=2;i<=n;++i){
        for(int j=p[i-2]+1;j<p[i-1];++j){
            mi1[i-1]=min(mi1[i-1],f[c[j].id]);
            mi2[i-1]=min(mi2[i-1],f[c[j].id]-b[c[j].id].r);
        }
        mi1[i-1]=min(mi1[i-1],dp[i-1]);
        mi2[i-1]=min(mi2[i-1],dp[i-1]-a[i-1]);
        if(p[i]==p[i-1]+1){
            for(int j=p[i-2]+1;j<p[i-1];++j){
                // cout<<" j:"<<c[j].id<<" f:"<<f[c[j].id]<<endl;
                dp[i]=min(dp[i],f[c[j].id]);
            }
            dp[i]=min(dp[i],dp[i-1]);
            // cout<<" i:"<<i<<" dp:"<<dp[i]<<endl;
            continue;
        }
        else{
            // cout<<"      //d i:"<<i<<" p:"<<p[i]<<" p-1:"<<p[i-1]<<" lst:"<<c[p[i]-1].id<<endl;
            for(int jj=p[i-1]+1;jj<p[i];++jj){
                int j=c[jj].id;
                // for(int kk=p[i-2]+1;kk<p[i-1];++kk){
                //     int k=c[kk].id;
                //     g[j]=min(g[j],f[k]+min(b[j].l-b[k].r,2*(b[j].l-a[i-1])));
                // }
                // g[j]=min(g[j],dp[i-1]+b[j].l-a[i-1]);
                g[j]=min(mi1[i-1]+2*(b[j].l-a[i-1]),mi2[i-1]+b[j].l);
                // cout<<" j:"<<j<<" g:"<<g[j]<<endl;
            }
            // int mi=inf;
            // for(int j=p[i-2]+1;j<p[i-1];++j){
            //     mi=min(mi,f[c[j].id]);
            //     // cout<<" j:"<<c[j].id<<" f:"<<f[c[j].id]<<" mi:"<<mi<<endl;
            // }
            // mi=min(mi,dp[i-1]);
            // cout<<" mi:"<<mi<<" id:"<<c[p[i-1]+1].id<<endl;
            f[c[p[i-1]+1].id]=mi1[i-1]+a[i]-b[c[p[i-1]+1].id].r;
            // cout<<" f:"<<f[c[p[i-1]+1].id]<<endl;
            for(int jj=p[i-1]+2;jj<p[i];++jj){
                int j=c[jj].id;
                f[j]=g[j-1]+a[i]-b[j].r;
            }
            dp[i]=g[c[p[i]-1].id];
        }
        // cout<<" i:"<<i<<" dp:"<<dp[i]<<endl;
    }
    print(dp[n]);putchar('\n');
    return  0;
}