// 那就是希望。
// 即便需要取模，也是光明。

// NOIp 出筛法？
// 新概念 NOIp。

#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <algorithm>
#include <stdio.h>
#include <unordered_map>
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
namespace ConstMod
{
    template<const ullt p>
    class mod_ullt
    {
        private:
            ullt v;
            inline ullt chg(ullt w){return(w<p)?w:w-p;}
            inline mod_ullt _chg(ullt w){mod_ullt ans;ans.v=(w<p)?w:w-p;return ans;}
        public:
            mod_ullt():v(0){}
            mod_ullt(ullt v):v(v%p){}
            bol empty(){return!v;}
            inline ullt val(){return v;}
            friend bol operator<(mod_ullt a,mod_ullt b){return a.v<b.v;}
            friend bol operator>(mod_ullt a,mod_ullt b){return a.v>b.v;}
            friend bol operator<=(mod_ullt a,mod_ullt b){return a.v<=b.v;}
            friend bol operator>=(mod_ullt a,mod_ullt b){return a.v>=b.v;}
            friend bol operator==(mod_ullt a,mod_ullt b){return a.v==b.v;}
            friend bol operator!=(mod_ullt a,mod_ullt b){return a.v!=b.v;}
            inline friend mod_ullt operator+(mod_ullt a,mod_ullt b){return a._chg(a.v+b.v);}
            inline friend mod_ullt operator-(mod_ullt a,mod_ullt b){return a._chg(a.v+a.chg(p-b.v));}
            inline friend mod_ullt operator*(mod_ullt a,mod_ullt b){return a.v*b.v;}
            friend mod_ullt operator/(mod_ullt a,mod_ullt b){return b._power(p-2)*a.v;}
            friend mod_ullt operator^(mod_ullt a,ullt b){return a._power(b);}
            inline mod_ullt operator-(){return _chg(p-v);}
            mod_ullt sqrt()
            {
                if(power(v,(p-1)>>1,p)!=1)return 0;
                mod_ullt b=1;do b++;while(b._power((p-1)>>1)==1);
                ullt t=p-1,s=0,k=1;while(!(t&1))s++,t>>=1;
                mod_ullt x=_power((t+1)>>1),e=_power(t);
                while(k<s)
                {
                    if(e._power(1llu<<(s-k-1))!=1)x*=b._power((1llu<<(k-1))*t);
                    e=_power(p-2)*x*x,k++;
                }
                return _min(x,-x),x;
            }
            mod_ullt inv(){return _power(p-2);}
            mod_ullt _power(ullt index){mod_ullt ans(1),w(v);while(index){if(index&1)ans*=w;w*=w,index>>=1;}return ans;}
            voi read(){v=0;chr c;do c=getchar();while(c>'9'||c<'0');do v=(c-'0'+v*10)%p,c=getchar();while(c>='0'&&c<='9');v%=p;}
            voi print()
            {
                static chr C[20];uint tp=0;
                ullt w=v;do C[tp++]=w%10+'0',w/=10;while(w);
                while(tp--)putchar(C[tp]);
            }
            voi println(){print(),putchar('\n');}
            mod_ullt operator++(int){mod_ullt ans=*this;return v=chg(v+1),ans;}
        public:
            inline ullt&operator()(){return v;}
            inline mod_ullt&operator+=(mod_ullt b){return*this=_chg(v+b.v);}
            inline mod_ullt&operator-=(mod_ullt b){return*this=_chg(v+chg(p-b.v));}
            inline mod_ullt&operator*=(mod_ullt b){return*this=v*b.v;}
            mod_ullt&operator^=(ullt b){return*this=_power(b);}
            mod_ullt&operator/=(mod_ullt b){return*this=b._power(p-2)*v;}
            mod_ullt&operator++(){return v=chg(v+1),*this;}
    };
}
const ullt Mod=998244353;
typedef ConstMod::mod_ullt<Mod>modint;
ullt V[30000005];uint cnt;
const ullt Lim=3e6;
bol Gone[Lim+5];modint Mu[Lim+5];
ullt Prime[Lim+5];uint tp;
std::unordered_map<ullt,modint>M;
modint S(ullt n){
    if(n<=Lim)return Mu[n];
    if(M.count(n))return M[n];
    modint ans(1);
    for(ullt l=2,r;l<=n;l=r+1)r=n/(n/l),ans-=S(n/l)*(r-l+1);
    return M[n]=ans;
}
std::unordered_map<ullt,modint>M2;
modint get(ullt n){
    if(M2.count(n))return M2[n];
    return M2[n]=std::upper_bound(V,V+cnt,n)-V;
}
modint UserA[Lim+5];
modint A(ullt n){
    if(n<=Lim)return UserA[n];
    modint last,wil,ans;
    for(uint l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l),wil=get(r);
        ans+=(wil-last)*S(n/l);
        last=wil;
    }
    return ans;
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    // freopen("QAQ.out","w",stdout);
#else
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
#endif
    Gone[1]=1,Mu[1]=1;
    for(ullt i=2;i<=Lim;i++){
        if(!Gone[i]){
            Prime[tp++]=i,UserA[i]=Mu[i]=-modint(1);
            for(ullt j=i;j<=Lim;j*=i)Gone[j]=1;
        }
        for(auto p:Prime)if(i%p&&i*p<=Lim)
            for(ullt j=p;i*j<=Lim;j*=p)Mu[i*j]=Mu[i]*Mu[j],Gone[i*j]=1;
        else break;
    }
    for(uint i=2;i<=Lim;i++)Mu[i]+=Mu[i-1];
    ullt n;uint w;scanf("%llu%u",&n,&w);
    V[0]=1;cnt=1;UserA[1]=1;
    while(w--){
        ullt p;uint a;scanf("%llu%u",&p,&a);
        if(p<=Lim){
            UserA[p]=0;
            ullt t=1;for(uint i=0;i<=a;i++)t*=p;
            if(t<=Lim)UserA[t]=-modint(1);
        }
        for(uint j=cnt-1;~j;j--){
            ullt v=V[j];for(uint k=1;k<=a&&(v*=p)<=n;k++)V[cnt++]=v;
        }
    }
    std::sort(V,V+cnt);
    for(ullt i=2;i<=Lim;i++){
        for(auto p:Prime)if(i%p&&i*p<=Lim)
            for(ullt j=p;i*j<=Lim;j*=p)UserA[i*j]=UserA[i]*UserA[j];
        else break;
    }
    for(uint i=2;i<=Lim;i++)UserA[i]+=UserA[i-1];
    // printf("%u\n",cnt);
    modint ans(1),last=1,wil;
    for(ullt l=2,r;l<=n;l=r+1){
        r=n/(n/l);wil=A(r);
        ans+=(wil-last)/(1-modint(n)/(n/l));
        last=wil;
    }
    ans.println();
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
