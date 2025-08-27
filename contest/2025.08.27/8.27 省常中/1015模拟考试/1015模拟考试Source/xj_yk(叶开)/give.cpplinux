// 出题人不创做题人。

#include <algorithm>
#include <bitset>
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
typedef std::bitset<5005>BIT;
uint A[205];
BIT B,User;
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
#endif
    uint t;scanf("%u",&t);
    while(t--){
        uint n;ullt m,S;scanf("%llu%llu%u",&m,&S,&n);
        for(uint i=0;i<n;i++)scanf("%u",A+i);
        if(A[0]*m>S){puts("0");continue;}
        S-=A[0]*m;for(uint i=n-1;~i;i--)A[i]-=A[0];
        B=BIT();B[0]=1;
        for(ullt i=1;i<=m&&i<=S;i<<=1)if(m&i){
            User=B;
            for(uint j=1;j<n&&A[j]<=S/i;j++)User^=B<<(i*A[j]);
            B=User;
        }
        puts(B[S]?"1":"0");
    }
    return 0;
}
