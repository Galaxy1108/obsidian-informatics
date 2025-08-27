// 方便起见，T=0,y>=x。
// 显然问题等效；否则讨论一下翻转即可。
// 首先一轮暴力，跳跃过 -1/0 分界。
// 如果过不去则已经结束。
// 否则，接下来始终只在 [-x,y) 移动。
// 不妨 x,y 互质。不互质则除法、取余，最后回复即可。
// 我们考虑暴力让 P 跳到 [-x,0) 的位置。
// 接下来肯定是向右跳，但先别急。
// 我们指出，假设当前在 $k$，向右跳后跳回此区间要 (y+k)/x+1 步，总计 (y+k)/x+2 步。
// 下 t 轮会从 ((k+yt)mod x)-x 开始。
// 于是跳回当前点只用 x+y 步。
// 跳到 ((k+ya)mod x)-x 要 a+(k+ya)/x-k/x 步。
// 于是先把前面跳回当前点的部分做完，然后二分答案找到合适的 a。
// 于是就完了。

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
typedef __uint128_t ulllt;
typedef __int128_t lllt;
lllt div(lllt a,lllt b){
    lllt c=a/b;while(c*b>a)c--;
    return c;
}
lllt solve(lllt n,lllt x,lllt y,lllt S,lllt T){
    if(x>y)return-solve(n,y,x,-S,1-T);
    if(T)return solve(n,x,y,S-T,0)+T;
    if(gcd(x,y)>1){
        lllt g=gcd(x,y);lllt s=div(S,g);
        return solve(n,x/g,y/g,s,0)*g+(S-s*g);
    }
    if(S<-x){
        if(-x-S>=n*y)return S+n*y;
        n-=(-x-S)/y+1,S+=((-x-S)/y+1)*y;
    }
    if(S>=0){
        if(S>=n*x)return S-n*x;
        n-=S/x+1,S-=(S/x+1)*x;
    }
    n%=x+y;
    lllt l=0,r=x+y-1;
    while(l<r){
        lllt mid=(l+r+1)>>1;
        lllt step=mid+div(S+y*mid,x)-div(S,x);
        if(step>n)r=mid-1;else l=mid;
    }
    n-=l+div(S+y*l,x)-div(S,x),S=(S+x+y*l)%x-x;
    if(!n)return S;
    n--,S+=y;
    S-=n*x;
    return S;
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
#endif
    uint t;scanf("%u",&t);
    while(t--){
        ullt n,x,y;llt s,t;
        scanf("%llu%lld%lld%llu%llu",&n,&s,&t,&x,&y);
        printf("%lld\n",(llt)solve(n,x,y,s,t));
    }
    return 0;
}
