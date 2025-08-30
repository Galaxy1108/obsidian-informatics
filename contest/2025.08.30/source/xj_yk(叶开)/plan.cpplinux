// 那就是希望。
// 即便需要取模，也是光明。

// f_{p,0,v} <- v
// f_{p,k,gcd(a,b)} <- f_{s,t,a} + f_{p,k-t,b}
// f_{p,k,b} <- f_{s,t-1,a} + a + f_{p,k-t,b}
// ...
// 考虑凸二分。
// f_{p,gcd(a,b)} <- f_{p,a} + f_{s,b}
// f_{p,a} <- f_{p,a} + f_{s,b} + (b-W,1)
// 然后比较 k。
// O(nd(v)^2log vlog d(v))
// 感觉不太跑得满。
// 考虑优化。
// 考虑定义 g_{p,d} = max(g_{p,v}| d|v).
// 则第一部分变为
// g_{p,d} <- g_{p,d} + g_{s,d}
// 第二部分变为
// g_{p,a} <- g_{p,a} + g_{s,b} + (b-W,1)
// O(nd(v)log v)
// 草凸性对不对啊。
// 还是直接 dp 吧。
// O(nk^2d(v))
// g_{p,k,d} <- g_{p,t,d} + g_{s,k-t,d}
// g_{p,k,a} <- g_{p,t-1,a} + g_{s,k-t,b} + b
// O(n^2d(v))

#include <algorithm>
#include <stdio.h>
#include <vector>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(b!=0){T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}else return y=0,x=1,a;}
template<typename T>T power(T base,T index,T mod)
{
    T ans=1%mod;
    while(index)
    {
        if(index&1)ans=ans*base%mod;
        base=base*base%mod,index>>=1;
    }
    return ans;
}
std::vector<uint>Way[505];
std::vector<uint>Fac[505];
uint A[505];
llt Dp[505][505][245],User[505][245];
uint Siz[505];
uint n,k;
voi dfs(uint p,uint f){
    Siz[p]=1;
    for(auto s:Way[p])if(s!=f){
        dfs(s,p);
        for(uint j=0;j<Siz[p];j++)for(uint i=0;i<Fac[p].size();i++)
            User[j][i]=Dp[p][j][i];
        for(uint j=0;j<Siz[p]+Siz[s];j++)for(uint i=0;i<Fac[p].size();i++)
            Dp[p][j][i]=-2e9;
        for(uint t=0;t<Siz[s];t++){
            llt v=0;for(uint i=0;i<Fac[s].size();i++)_max(v,Dp[s][t][i]+Fac[s][i]);
            for(uint q=0;q<Siz[p];q++)for(uint i=0;i<Fac[p].size();i++)
                _max(Dp[p][t+q+1][i],User[q][i]+v);
            for(uint q=0;q<Siz[p];q++)for(uint i=Fac[p].size()-1,j=Fac[s].size()-1;~i;i--){
                while(Fac[s][j]>Fac[p][i])j--;
                if(Fac[s][j]==Fac[p][i])
                    _max(Dp[p][t+q][i],User[q][i]+Dp[s][t][j]);
            }
        }
        Siz[p]+=Siz[s];
    }
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
#endif
    // static uint Cnt[1000005];
    // for(uint i=1;i<=1000000;i++)
    //     for(uint j=i;j<=1000000;j+=i)
    //         Cnt[j]++;
    // printf("%u\n",*std::max_element(Cnt,Cnt+1000001));
    // return 0;
    scanf("%u%u",&n,&k);
    for(uint i=1,u,v;i<n;i++)scanf("%u%u",&u,&v),Way[--u].push_back(--v),Way[v].push_back(u);
    for(uint i=0;i<n;i++){
        scanf("%u",A+i);
        for(uint j=1;j*j<=A[i];j++)if(A[i]%j==0){Fac[i].push_back(j);if(j*j!=A[i])Fac[i].push_back(A[i]/j);}
        std::sort(Fac[i].begin(),Fac[i].end());
    }
    dfs(0,-1);
    llt ans=0;
    for(uint i=0;i<Fac[0].size();i++)_max(ans,Dp[0][k][i]+Fac[0][i]);
    printf("%lld\n",ans);
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
