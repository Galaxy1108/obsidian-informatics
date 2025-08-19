#include<bits/stdc++.h>
using namespace std;
#define int long long
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

int mu[N],Mu[N],prim[N],cnt;
bool vis[N];

void init(){
    mu[1]=1;
    for(int i=2;i<N;++i){
        if(!vis[i]){
            prim[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt&&i*prim[j]<N;++j){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)break;
            mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=1;i<N;++i)Mu[i]=Mu[i-1]+mu[i];
}

int work(int n,int m){
    if(n>m)swap(n,m);
    int ans=0;
    for(int l=1,r=0;l<=n;l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans+=(Mu[r]-Mu[l-1])*(n/l)*(m/l);
    }
    //cout<<" /work n:"<<n<<" m:"<<m<<" ans:"<<ans<<endl;
    return ans;
}

signed main(){
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    init();
    int n=read();
    while(n--){
        int a=read()-1,b=read(),c=read()-1,d=read(),k=read(),ans=0;
        ans=work(b/k,d/k)-work(a/k,d/k)-work(b/k,c/k)+work(a/k,c/k);
        print(ans);putchar('\n');
    }
    return 0;
}