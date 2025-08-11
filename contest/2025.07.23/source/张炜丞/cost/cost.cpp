#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
const int N=1030,inf=1e18;

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

int n,m,a[N],b[N],c[N],f[N][N],ans=inf;

struct node{
    int v,cnta;
}t[N<<2];

void slove(int p,int l,int r){
    if(l==r){
        t[p].cnta=b[l]==0;t[p].v=0;return;
    }
    int mid=l+r>>1;
    slove(ls,l,mid);slove(rs,mid+1,r);
    t[p].cnta=t[ls].cnta+t[rs].cnta;
    t[p].v=t[ls].v+t[rs].v;
    int s[2][2];
    s[0][1]=s[1][0]=1;
    s[0][0]=t[p].cnta<(r-l+1-t[p].cnta)?2:0;
    s[1][1]=2-s[0][0];
    for(int i=l;i<=mid;++i){
        for(int j=mid+1;j<=r;++j){
            t[p].v+=s[b[i]][b[j]]*f[i][j];
        }
    }
}

void dfs(int d,int x){
    if(x>=ans)return;
    if(d==m+1){
        slove(1,1,m);
        //cout<<" x:"<<x<<" v:"<<t[1].v<<endl;
        //if(t[1].v==5)
        ans=min(ans,t[1].v+x);
        return;
    }
    b[d]=a[d];
    dfs(d+1,x);
    b[d]=a[d]^1;
    dfs(d+1,x+c[d]);
}

signed main(){
    freopen("cost.in","r",stdin);
    freopen("cost.out","w",stdout);
    n=read();m=(1<<n);
    bool flag1=1;
    for(int i=1;i<=m;++i)a[i]=read();
    for(int i=1;i<=m;++i){
        c[i]=read();
        if(c[i])flag1=0;
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j+i<=m;++j){
            f[i][i+j]=read();
        }
    }
    if(flag1){
        puts("0");return 0;
    }
    dfs(1,0);
    print(ans);putchar('\n');
    return 0;
}