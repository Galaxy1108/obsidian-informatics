#include <bits/stdc++.h>
using namespace std;
#define N 205
#define V (N*N)
#define MOD mod
int n,mod;
long long ans=0;
int a[N];
bitset<N>book;
class{
    #define lowbit(x) ((x)&(-(x)))
public:
    int v[V],mx;
    void update(int x,int k){
        x++;
        for(;x<=mx;x+=lowbit(x)){
            // cerr<<x<<" ";
            v[x]+=k;
        }
    }
    int query(int x){
        x++;
        int res=0;
        for(;x>=1;x-=lowbit(x)){
            // cerr<<x<<" ";
            res+=v[x];
        }
        return res;
    }
    #undef lowbit
}bit;
void add(long long &x,long long y){
    x+=y;
    (x>=MOD)&&(x-=MOD);
}
int calc(){
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j])res++;
        }
    }
    return res;
}
void dfs(int x){
    // cerr<<x<<' ';
    if(x==n+1){
        int t=calc();
        add(ans,bit.query(bit.mx)-bit.query(t));
        bit.update(t,1);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(book[i])continue;
        book[i]=1;
        a[x]=i;
        dfs(x+1);
        book[i]=0;
    }
}
int main(){
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>mod;
    bit.mx=n*n+1;
    dfs(1);
    cout<<ans;
    return 0;
}