#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
#define int long long
#define lb(x) (x&(-x))
const int N=1e6+5;

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

int n,a[N],m,b[N],ans,vis[N],lst[N],s[N],t[N];
struct node{
    int x,y,lst,isnode;
    bool operator<(const node &n1){
        return y==n1.y?isnode<n1.isnode:y<n1.y;
    }
}q[N+N];

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;y>>=1;
    }
    return ans;
}

void init(){
    s[n+1]=1;
    for(int i=n;i>=1;--i){
        s[i]=s[i+1]*2;
        if(lst[a[i]])s[i]-=s[lst[a[i]]+1];
        lst[a[i]]=i;
        s[i]=(s[i]%P+P)%P;
        // cout<<" i:"<<i<<" s:"<<s[i]<<endl;
    }
    memset(lst,0,sizeof(lst));
    for(int i=1;i<=n;++i){
        q[i].y=a[i];q[i].x=i;q[i].lst=lst[a[i]];q[i].isnode=1;
        lst[a[i]]=i;
    }
}

void add(int x,int v){
    while(x<=n){
        t[x]=(t[x]+v)%P;
        x+=lb(x);
    }
}

int sum(int x){
    int ans=0;
    while(x){
        ans=(ans+t[x])%P;
        x-=lb(x);
    }
    return (ans%P+P)%P;
}

signed main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    m=read();
    for(int i=1;i<=m;++i)b[i]=read();
    init();
    int cnt=n;
    q[++cnt]={1,b[1],0,0};
    for(int i=1,j=1;i<m;++i){
        while(j<=n&&a[j]!=b[i])++j;++j;
        if(j>n)break;
        q[++cnt]={j,b[i+1]};++ans;
    }
    sort(q+1,q+cnt+1);
    for(int i=1;i<=cnt;++i){
        if(q[i].isnode){
            add(q[i].lst+1,s[q[i].x+1]);
            add(q[i].x+1,-s[q[i].x+1]);
        }
        else{
            // cout<<" x:"<<q[i].x<<" v:"<<q[i].y<<" ans:"<<sum(q[i].x)<<endl;
            ans=(ans+sum(q[i].x))%P;
        }
    }
    print(ans+1);putchar('\n');
    return 0;
}