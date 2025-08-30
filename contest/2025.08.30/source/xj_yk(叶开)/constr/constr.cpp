// 那就是希望。
// 即便需要取模，也是光明。

// WTF?

#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

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
typedef std::vector<uint>vec;
const uint n=10;
vec Totol[4000001],now(n);
uint cnt,ok,Log2[1u<<10|1];
voi dfs(uint p){
    if(p==n){Totol[cnt++]=now;return;}
    for(uint S=ok,t=lowbit(ok);S;t=lowbit(S-=t))now[p]=Log2[t],ok^=t,dfs(p+1),ok^=t;
}
bol check(vec&a,vec&b){
    for(uint i=0;i<n;i++)if(a[i]>b[i]+1||a[i]+1<b[i])return 1;
    return 0;
}
bol check(uint i,uint j){return check(Totol[i],Totol[j]);}
std::vector<uint>V;
bol check(uint p){
    for(auto s:V)if(!check(s,p))return 0;
    return 1;
}
const uint Fac[]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
voi find(uint p,uint l){
    if(p==2){
        V.clear();
        uint r=l+Fac[n-p];
        for(uint i=l;i<r;i+=2)
            if(check(i))V.push_back(i);
            else if(check(i|1))V.push_back(i|1);
        return;
    }else{
        find(p+1,l);
        std::vector<uint>W;
        for(uint i=0;i<n-p;i+=2)for(auto s:V)
            W.push_back(s+Fac[n-p-1]*i);
        V=W;
        return;
    }
}
int main()
{
    freopen("constr.in","r",stdin);
    freopen("constr.out","w",stdout);
    for(uint i=0;i<n;i++)Log2[1u<<i]=i;
    ok=(1u<<n)-1,dfs(0);
    find(0,0);
    // for(uint i=0;i<362880;i+=2)
    //     if(check(i))V.push_back(i);
    //     else if(check(i|1))V.push_back(i|1);
    // for(uint i=0;i<10;i+=2)for(uint j=0;j<V.size();j++)
    //     W.push_back(V[j]+i*362880);
    printf("%u\n",(uint)V.size());
    // for(auto s:V)printf("%u,",s);
    // puts("");
    for(auto s:V)for(uint i=0;i<n;i++)
        printf("%u%c",Totol[s][i]+1," \n"[i==n-1]);
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
