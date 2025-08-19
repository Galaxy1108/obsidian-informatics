#include<bits/stdc++.h>
using namespace std;
const int N=2005,inf=1e9;
const long double eps=1e-9;

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

int n,m;
long double f[N],g[N],c[N],d[N],w[N],s[N];
int h[N][2],path[N];

signed main(){
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i){
        scanf("%Lf%Lf%Lf",&w[i],&c[i],&d[i]);
        s[i]=s[i-1]+w[i];
        // if(c[i]*d[i]-1.00>eps)cout<<" wA"<<endl;
    }
    // f[1]=w[1];
    for(int i=1;i<=n;++i){
        f[i]=f[i-1]+w[i];h[i][0]=0;
        for(int j=1;j<i;++j){
            if(g[j]*d[i]+s[i]-s[j]-m>f[i]){
                f[i]=g[j]*d[i]+s[i]-s[j]-m;
                h[i][0]=j;
            }
            // f[i]=max(f[i],g[j]*d[i]+s[i]-s[j]-m);
        }
        g[i]=(f[i-1]+w[i])*c[i];h[i][1]=0;
        for(int j=1;j<i;++j){
            if(g[i]<g[j]+(s[i]-s[j])*c[i]){
                h[i][1]=j;
                g[i]=g[j]+(s[i]-s[j])*c[i];
            }
        }
        // f[i]=max(f[i],g[i]*d[i]-m);
        // cout<<" i:"<<i<<" f:"<<f[i]<<" g:"<<g[i]<<" s:"<<s[i]<<" w:"<<w[i]<<endl;
    }
    int x=n,state=0;
    for(;x;){
        // path[x]=state;
        // cout<<" x:"<<x<<" h:"<<h[x][state]<<endl;
        if(state==0){
            if(!h[x][0]){
                --x;continue;
            }
            else{
                path[x]=1;
                x=h[x][0];
                state=1;
            }
        }
        else{
            path[x]=2;
            if(!h[x][1]){
                --x;state=0;
            }
            else{
                x=h[x][1];
            }
        }
    }
    long double ans=0,ans2=0;
    for(int i=1;i<=n;++i){
        ans+=w[i];
        if(path[i]==1){
            ans+=ans2*d[i]-m;ans2=0;
        }
        else if(path[i]==2){
            ans2+=ans*c[i];ans=0;
        }
        // cout<<" i:"<<i<<" path:"<<path[i]<<" ans:"<<ans<<" ans2:"<<ans2<<" f:"<<f[i]<<" g:"<<g[i]<<endl;
    }
    printf("%.4Lf",ans);putchar('\n');
    return 0;
}