#include<bits/stdc++.h>
using namespace std;
const int N=115,M=13,inf=1e9;

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

int s[N],f[N][M][M][M],a[N],b[N],c[N],n;

signed main(){
    freopen("worker.in","r",stdin);
    freopen("worker.out","w",stdout);
    n=read();
    char cc=getchar();
    for(int i=1;i<=n;++i){
        while(cc!='A'&&cc!='B'&&cc!='C')cc=getchar();
        s[i]=cc-'A';
        if(s[i]==0)++a[i];
        else if(s[i]==1)++b[i];
        else ++c[i];
        cc=getchar();
    }
    for(int i=1;i<=n;++i){
        a[i]+=a[i-1];b[i]+=b[i-1];c[i]+=c[i-1];
    }
    for(int i=n+1;i<=n+11;++i){
        a[i]=a[i-1],b[i]=b[i-1],c[i]=c[i-1];
    }
    if(n<=10){
        int ans=(a[n]>0)+(b[n]>0)+(c[n]>0);
        print(ans);putchar('\n');return 0;
    }
    memset(f,0x3F,sizeof(f));
    f[10][a[10]][b[10]][c[10]]=0;
    for(int i=10;i<=n+10;++i){
        for(int j=0;j<=min(a[i],10);++j){
            for(int k=0;k<=min(b[i],10);++k){
                for(int l=0;l<=min(c[i],10);++l){
                    if(f[i][j][k][l]>n)continue;
                    int _i=i+j,_j=a[_i]-a[i],_k=k+b[_i]-b[i],_l=l+c[_i]-c[i];
                    f[_i][_j][_k][_l]=min(f[_i][_j][_k][_l],f[i][j][k][l]+1);
                    _i=i+k,_j=j+a[_i]-a[i],_k=b[_i]-b[i],_l=l+c[_i]-c[i];
                    f[_i][_j][_k][_l]=min(f[_i][_j][_k][_l],f[i][j][k][l]+1);
                    _i=i+l,_j=j+a[_i]-a[i],_k=k+b[_i]-b[i],_l=c[_i]-c[i];
                    f[_i][_j][_k][_l]=min(f[_i][_j][_k][_l],f[i][j][k][l]+1);
                }
            }
        }
    }
    int ans=inf;
    for(int i=n;i<=n+10;++i)ans=min(ans,f[i][0][0][0]);
    print(ans);putchar('\n');
    return 0;
}