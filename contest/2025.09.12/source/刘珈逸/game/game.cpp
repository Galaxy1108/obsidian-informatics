#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,val[N];
void read(int&x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
}
int solve(){
    read(n),read(m);
    for(int i=1;i<=n;i++)val[i]=0;
    while(m--){
        int u,v,w;read(u),read(v),read(w);
        val[u]+=w,val[v]+=w;
    }
    int ans=0;
    sort(val+1,val+1+n,greater<int>());
    for(int i=1;i<=n;i++)
        if(i&1)ans+=val[i];
        else ans-=val[i];
    printf("%lld\n",ans/2);
    return 0;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int t;scanf("%lld",&t);
    while(t--)solve();
    return 0;
}