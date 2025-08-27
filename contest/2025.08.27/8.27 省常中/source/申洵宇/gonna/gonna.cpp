class barrett_reduction{
private:
    typedef unsigned long long ull;
    ull MOD,times;
public:
    inline void init(long long mod){
        MOD=mod;
        times=((__int128(1))<<64)/MOD;
    }
    template<typename T>
    inline friend T operator%(T x,const barrett_reduction& y){
        static ull q,r;
        q=((__int128(x)*y.times)>>64);
        r=x-q*y.MOD;
        while(r>=y.MOD)r-=y.MOD;
        return r;
    }
};
#include <bits/stdc++.h>
using namespace std;
constexpr int N=20005;
int n,mn[N];
long long mod;
barrett_reduction MOD;
vector<int>pr,fac[N];
bitset<N>book;
inline void init(){
    book[0]=book[1]=1;
    for(register int i=2;i<=n;i++){
        if(!book[i]){
            pr.emplace_back(i);
            mn[i]=(int)pr.size()-1;
        }
        for(auto v:pr){
            if(1ll*i*v>n)break;
            book[i*v]=1;
            if(i%v==0){
                mn[i*v]=mn[i];
                break;
            }
            mn[i*v]=mn[v];
        }
    }
    fac[0].resize(pr.size(),0);
    fac[1]=fac[0];
    for(register int i=2;i<=n;i++){
        fac[i]=fac[i-1];
        static int t;t=i;
        while(t>1){
            fac[i][mn[t]]++;
            t/=pr[mn[t]];
        }
        /*test code
        if(i!=20000)continue;
        cerr<<i<<":\n";
        for(int j=0;j<pr.size();j++){
            if(pr[j]>i)break;
            cerr<<pr[j]<<":"<<fac[i][j]<<'\n';
        }
        */
    }
}
inline long long mpow(long long base,long long p){
    static long long res;res=1;
    while(p){
        if(p&1)res=res*base%MOD;
        p>>=1;
        base=base*base%MOD;
    }
    return res;
}
inline long long getg(int x){
    static vector<int>res;
    res.resize(pr.size(),0);
    for(register int i=0;i<pr.size();i++){
        if(pr[i]>x)break;
        res[i]=fac[x][i]*(x-1);
    }
    for(register int i=1;i<x;i++){
        for(register int j=0;j<pr.size();j++){
            if(pr[j]>x)break;
            res[j]-=fac[i][j]+fac[x-i][j];
        }
    }
    static long long sum;sum=1;
    for(register int i=0;i<pr.size();i++){
        if(pr[i]>x)break;
        sum=sum*(mpow(pr[i],res[i]+1)-1+mod)%MOD*mpow(pr[i]-1+mod,mod-2)%MOD;
    }
    return sum;
}
int main(){
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>mod;
    MOD.init(mod);
    init();
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=getg(i);
        ans-=ans>=mod?mod:0;
    }
    cout<<ans;
    return 0;
}