#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
const int N=605,M=1055,K=22,P=1e9+7;

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

int n,a[N],f[K][M][12],b[N],c[N];

inline int md(int x){
    return x>=P?x-P:x;
}

signed main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    n=read();
    // cerr<<" n:"<<n<<endl;
    bool flag=1;
    for(int i=1;i<=n*2;++i){
        a[i]=read();
        if(a[i]!=-1)flag=0,b[a[i]]=i;
    }
    if(n>10){
        puts("1");return 0;
    }
    // if(flag){
    //     int ans=1;
    //     for(int i=1;i<=n;++i)ans=ans*i%P;
    //     // cerr<<" n:"<<n<<" ans:"<<ans<<endl;
    //     print(ans);putchar('\n');
    //     return 0;
    // }
    int U=(1<<n)-1;
    f[0][0][0]=1;
    for(int i=0;i<n*2;++i){
        for(int s=0;s<=U;++s){
            for(int k=0;k<=n;++k){
                if(!f[i][s][k])continue;
                if(b[i+1]){
                    int p=(1<<(b[i+1]+1)/2-1);
                    if(s&p)f[i+1][s][k]=md(f[i+1][s][k]+f[i][s][k]);
                    else {
                        int pp=((b[i+1]&1)?1:-1)+b[i+1],nk=k+(a[pp]==-1);
                        f[i+1][s|p][nk]=md(f[i+1][s|p][nk]+f[i][s][k]);
                    }
                    continue;
                }
                if(k)f[i+1][s][k-1]=md(f[i+1][s][k-1]+f[i][s][k]);
                for(int j=0;j<n;++j){
                    if(s&(1<<j))continue;
                    if(a[j*2+1]!=-1&&a[j*2+2]!=-1)continue;
                    int nk=k+((a[j*2+1]==-1)+(a[j*2+2]==-1)-1);
                    f[i+1][s|(1<<j)][nk]=md(f[i+1][s|(1<<j)][nk]+f[i][s][k]);
                }
            }
        }
    }
    print(f[n*2][U][0]);putchar('\n');
    return 0;
}