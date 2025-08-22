#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define lb(x) (x&(-x))
const int N=25,M=131100,inf=1e9;

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

int n,seed,a[N][N],f[M],s[M],U,cnt;

int dfs(int i,int state,int d){
    // if(state>M)exit(0);
    // cout<<" /dfs i:"<<i<<" state:"<<state<<" d:"<<d<<endl;
    // cout<<" s:"<<s[state]<<endl;
    if(d==n+1)return s[state];
    if(f[state])return f[state];
    // ++cnt;if(cnt%1000==0)print(cnt),putchar('\n');
    int x=state,ans=0;
    while(x){
        int an=dfs(i%n+1,state-lb(x),d+1);
        if(a[i][an]>a[i][ans])ans=an;
        x-=lb(x);
    }
    // if(ans==0)exit(0);
    return f[state]=ans;
}

signed main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    n=read();seed=read();
    if(seed==0){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n+1;++j){
                a[i][j]=read();
            }
        }
    }
    U=(1<<n+1)-1;
    for(int i=1;i<=n+1;++i){
        s[1<<i-1]=i;
        // cout<<" i:"<<i<<" p:"<<(1<<i-1)<<" s:"<<s[(1<<i-1)]<<endl;
    }
    for(int i=1;i<=n;++i){
        memset(f,0,sizeof(f));
        int ans=dfs(i,U,1);
        print(ans);putchar(' ');
    }
    putchar('\n');
    return 0;
}