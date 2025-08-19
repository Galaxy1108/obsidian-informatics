#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e18;
const double eps=1e-9;

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

int f[N],x[N],p[N],c[N],s1[N],s2[N],n,st[N],l,r;

long double calc(int x,int y){
    return (long double)(f[y]+s2[y]-f[x]-s2[x])/(s1[y]-s1[x]);
}

signed main(){
    freopen("storage.in","r",stdin);
    freopen("storage.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        x[i]=read();
        p[i]=read();
        c[i]=read();
        s1[i]=s1[i-1]+p[i];
        s2[i]=s2[i-1]+p[i]*x[i];
        f[i]=inf;
    }
    f[0]=0;l=1,r=1;st[1]=0;
    for(int i=1;i<=n;++i){
        while(l<r&&calc(st[l],st[l+1])-x[i]<eps)++l;
        f[i]=c[i]+f[st[l]]+(s1[i]-s1[st[l]])*x[i]-(s2[i]-s2[st[l]]);
        while(l<r&&calc(st[r-1],st[r])>calc(st[r],i))--r;
        st[++r]=i;
        // for(int j=0;j<i;++j){
            // f[i]=min(f[i],c[i]+f[j]+(s1[i]-s1[j])*x[i]-(s2[i]-s2[j]));
            // f[i]=min(f[i],c[i]-s2[i]+f[j]+s2[j]-s1[j]*x[i]+s1[i]*x[i]);
        // }
    }
    print(f[n]);putchar('\n');
    return 0;
}