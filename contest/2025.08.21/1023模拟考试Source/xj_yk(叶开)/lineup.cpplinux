// 那就是希望。
// 即便需要取模，也是光明。

// TopCoder.
// 每个节点移动到自己最合适的位置，总是可以取到。

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
std::pair<uint,uint>A[55];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
#endif
    uint n;scanf("%u",&n);
    for(uint i=0;i<n;i++)scanf("%u",&A[i].first),A[i].second=i;
    std::sort(A,A+n);
    uint ans=0;
    for(uint i=0;i<n;i++)ans+=A[i].second<i?i-A[i].second:A[i].second-i;
    printf("%u\n",ans);
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
