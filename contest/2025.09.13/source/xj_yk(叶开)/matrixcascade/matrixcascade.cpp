// 那就是希望。
// 即便需要取模，也是光明。

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
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("matrixcascade.in","r",stdin);
    freopen("matrixcascade.out","w",stdout);
#endif
    uint t;scanf("%u",&t);
    while(t--){
        uint n,x,y;scanf("%u%u%u",&n,&x,&y);
        uint w=(n*(n-1)/2);w*=w;
        if((x-y+w)&1||(ullt)x+w<y)puts("NO");
        else{
            ullt t=(x-y+w)/2;
            if(t>x){puts("NO");continue;}
            ullt base=x-t;
            if(base>y){puts("NO");continue;}
            // fprintf(stderr,"%llu %llu\n",base,t);
            puts("YES");
            for(uint i=0,cnt=1;i<n;i++)for(uint j=0;j<n;j++)
                printf("%u%c",cnt++," \n"[j==n-1]);
        }
    }
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
