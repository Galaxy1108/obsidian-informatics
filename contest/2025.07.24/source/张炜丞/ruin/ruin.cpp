#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=605,P=1e9+7;

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

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

int n,a[N],b[N<<1],bb[N<<1],c[N],ans;
bool vis[N];

void dfs(int d){
    if(d==n+n+1){
        for(int i=1;i<=n+n;++i)bb[i]=b[i];
        for(int i=1;i<=n;++i){
            for(int j=n+n;j>=1;--j){
                if(bb[j]!=0&&vis[bb[j]])--bb[j];
                else vis[bb[j]]=1;
                //if(ans==0)cout<<" i:"<<i<<" j:"<<j<<" b:"<<bb[j]<<endl;
            }
            for(int j=1;j<=n;++j)vis[j]=0;
        }
        for(int i=1;i<=n;++i)if(!bb[a[i]])return;
        ++ans;return;
    }
    for(int i=1;i<=n;++i){
        if(!c[i])continue;
        b[d]=i;--c[i];
        dfs(d+1);
        b[d]=0;++c[i];
    }
}

signed main(){
    freopen("ruin.in","r",stdin);
    freopen("ruin.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)a[i]=read(),c[i]=2;
    if(a[n]!=n+n||a[1]==1){
        puts("0");return 0;
    }
    dfs(1);
    print(ans);putchar('\n');
    return 0;
}
