// 那就是希望。
// 即便需要取模，也是光明。

// Lemma.
// for any connected graph, its answer for this problem is floor(|E|/2).
// especially, for any 2\nmid|E|, it's possible for any node to have one edge unpaused.
//
// Proof.
// to do math ref on |E|.
// if |E| = 1, it's obviously true.
// if 2\mid|E|, then think of E/{e} whose left nodes are still connected, and we can choose one node of the edge e in the graph of E/{e},
// take its one edge in E/{e} unpaused, just as the floor(|E|/2) can get 1 uplifted.
// if 2\nmid|E|, we need only to prove that it's possible for any node to have one edge unpaused,
// which can be easily proved on one spanning tree of the graph with another math ref.
// QED.

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
std::vector<uint>Way[100005];
uint Dfn[100005],cnt;
uint dfs(uint p){
    Dfn[p]=cnt++;
    uint ans=0;
    for(auto s:Way[p]){
        ans+=Dfn[s]>Dfn[p];
        if(!~Dfn[s])ans+=dfs(s);
    }
    return ans;
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    // freopen("QAQ.out","w",stdout);
#else
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
#endif
    uint n,m;scanf("%u%u",&n,&m);
    while(m--){uint u,v;scanf("%u%u",&u,&v);Way[--u].push_back(--v),Way[v].push_back(u);}
    for(uint i=0;i<n;i++)Dfn[i]=-1;
    uint ans=0;
    for(uint i=0;i<n;i++)if(!~Dfn[i])ans+=dfs(i)/2;
    printf("%u\n",ans);
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
