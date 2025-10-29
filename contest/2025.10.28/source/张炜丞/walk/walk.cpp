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

int n,x,f[N][3][3][2],a[N],sum[N],vn;

signed main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)a[i]=read(),sum[i]=sum[i-1]+a[i],vn=max(vn,a[i]);
    memset(f,0x3F,sizeof(f));
    f[0][1][0][0]=0;
    int ans=inf;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=2;++j){
            if(a[i]+j-1<0)continue;
            for(int l=0;l<3;++l){
                for(int g=0;g<=1;++g){
                    // if(f[i][j][l][g]>=100)continue;
                    if(g==1&&a[i]+j-1==0){
                        ans=min(ans,f[i][j][l][g]+sum[n]-sum[i]);
                        continue;
                    }
                    // cout<<" i:"<<i<<" j:"<<j<<" l:"<<l<<" g:"<<g<<" f:"<<f[i][j][l][g]<<endl;
                    for(int k=0;k<=2;++k){
                        if(a[i+1]+k-1<0)continue;
                        int nl=l+(((a[i]+j-1)&1)^((a[i+1]+k-1)&1));
                        int ng=g|((a[i+1]+k-1)>0);
                        if(nl>=3)continue;
                        f[i+1][k][nl][ng]=min(f[i+1][k][nl][ng],f[i][j][l][g]+abs(j-1));
                    }
                }
            }
        }
    }
    ans=min(ans,min(f[n+1][1][2][1],f[n+1][1][0][1]));
    print(ans);putchar('\n');
    return 0;
}