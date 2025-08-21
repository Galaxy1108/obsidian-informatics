// 那就是希望。
// 即便需要取模，也是光明。

// 自然幂和？

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
const ullt Mod=1e9+7;
typedef ConstMod::mod_ullt<Mod>modint;
typedef std::vector<modint>modvec;
modint P[5005],Q[5005],B[5005];
modint Sum(modint n,uint k){
    modint ans,v(1);for(uint i=0;i<=k;i++)ans+=B[k-i]*Q[k-i]*(v*=n)*Q[i+1];
    ans*=P[k];return ans;
}
ullt A[5005];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
#endif
    P[0]=1;for(uint i=1;i<=5000;i++)P[i]=P[i-1]*i;
    Q[5000]=P[5000].inv();for(uint i=5000;i;i--)Q[i-1]=Q[i]*i;
    B[0]=1;for(uint i=1;i<=5000;i++)for(uint j=0;j<i;j++)B[i]-=P[i]*Q[j]*Q[i-j+1]*B[j];
    uint n;scanf("%u",&n);
    for(uint i=0;i<n;i++)scanf("%llu",A+i);
    std::sort(A,A+n+1);
    modint ans=A[n]+1,v(1);
    for(uint i=n;i;i--)ans-=(Sum(A[i]+1,n-i+1)-Sum(A[i-1]+1,n-i+1))/(v*=A[i]);
    ans.println();
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
