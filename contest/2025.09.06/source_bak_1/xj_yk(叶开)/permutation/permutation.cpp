// 那就是希望。
// 即便需要取模，也是光明。

// h : i->j
// p(h(z)) = h(q(z))
// p(j) = h(q(i))
// h: q(i) -> p(j)
// that is
// i->j
// q(i)->p(j)
// q(q(i))->p(p(j))
// ...
// so the cycle length of p and q should be same.
// then got finished.

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
uint P[100005],Q[100005],R[100005];
std::vector<uint>Vp[100005],Vq[100005],Lenp[100005],Lenq[100005];
bol Gonep[100005],Goneq[100005];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    // freopen("QAQ.out","w",stdout);
#else
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
#endif
    uint n;scanf("%u",&n);
    for(uint i=0;i<n;i++)scanf("%u",P+i),P[i]--;
    for(uint i=0;i<n;i++)scanf("%u",Q+i),Q[i]--;
    for(uint i=0;i<n;i++)if(!Gonep[i]){
        uint p=i;
        do Gonep[p]=1,Vp[i].push_back(p),p=P[p];while(!Gonep[p]);
        Lenp[Vp[i].size()].push_back(i);
    }
    for(uint i=0;i<n;i++)if(!Goneq[i]){
        uint p=i;
        do Goneq[p]=1,Vq[i].push_back(p),p=Q[p];while(!Goneq[p]);
        Lenq[Vq[i].size()].push_back(i);
    }
    for(uint i=0;i<n;i++)if(Lenp[i].size()!=Lenq[i].size()){
        return puts("NO"),0;
    }else{
        for(uint j=0;j<Lenp[i].size();j++){
            uint p=Lenp[i][j],q=Lenq[i][j];
            for(uint k=0;k<Vq[q].size();k++)
                R[Vq[q][k]]=Vp[p][k];
        }
    }
    for(uint i=0;i<n;i++)
        printf("%u%c",R[i]+1," \n"[i==n-1]);
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
