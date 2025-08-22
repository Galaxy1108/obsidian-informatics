#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+5,inf=1e18;

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

// bool f1;
int n,w[N][N],f[N],midis[N];
vector<int> mp;
struct node{
    int id,w;
    bool operator<(const node &n1){
        return w<n1.w;
    }
}a[N];
// bool f2;

signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    // int siz=&f1-&f2;
    // cout<<" siz:"<<siz/1024/1024<<endl;
    n=read();
    for(int i=1;i<=n;++i){
        w[i][i]=inf;a[i].id=i;a[i].w=inf;
        for(int j=i+1;j<=n;++j){
            w[i][j]=w[j][i]=read();
        }
        for(int j=1;j<=n;++j){
            a[i].w=min(a[i].w,w[i][j]);
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(a[i].w!=a[1].w)break;
        mp.push_back(a[i].id);
    }
    for(int i=1;i<=n;++i){
        midis[i]=inf;
        for(int j:mp){
            midis[i]=min(midis[i],w[i][j]);
        }
    }
    for(int i=1;i<=n;++i)f[i]=inf;
    for(int i=1;i<=n;++i){
        int u=a[i].id;
        f[u]=min(midis[u]-a[1].w,(a[i].w-a[1].w)*2);
        for(int j=1;j<=n;++j){
            // cout<<" u:"<<u<<" j:"<<j<<" w:"<<w[u][j]<<" f:"<<f[j]<<endl;
            f[u]=min(f[u],w[u][j]-a[1].w+f[j]);
        }
        // cout<<" u:"<<u<<" f:"<<f[u]<<endl;
    }
    int ans=a[1].w*(n-1);
    for(int i=1;i<=n;++i){
        print(ans+f[i]);putchar('\n');
    }
    return 0;
}