// 那就是希望。
// 即便需要取模，也是光明。

// 摆了，怎么都是异或卷积大师。
// 这个数据范围（40）怎么 容斥 + meet in the middle + 异或卷积科技。
// 而且还有这种奇葩限制。
// 真是不由得令我大受震撼。

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
namespace FWT_MODINT
{
    template<const ullt p>
    class FWT_Mod
    {
        public:
            typedef ConstMod::mod_ullt<p>modint;
            typedef std::vector<modint>modvec;
        private:
            uint n;
        public:
            FWT_Mod():n(0){}
            voi bzr(uint len){n=1;while(n<len)n<<=1;}
            uint size(){return n;}
            voi OR(modvec&x,bol op)
            {
                if(x.size()<n)x.resize(n);
                for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
                    op?x[i+j+k]-=x[j+k]:x[i+j+k]+=x[j+k];
            }
            voi AND(modvec&x,bol op)
            {
                if(x.size()<n)x.resize(n);
                for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
                    op?x[j+k]-=x[i+j+k]:x[j+k]+=x[i+j+k];
            }
            voi XOR(modvec&x,bol op)
            {
                if(x.size()<n)x.resize(n);
                for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
                {
                    modint u=x[j+k],t=x[i+j+k];x[j+k]=u+t,x[i+j+k]=u-t;
                }
                if(op){modint v=modint(n).inv();for(uint i=0;i<n;i++)x[i]*=v;}
            }
    };
}
const ullt Mod=998244353,g=3;
typedef ConstMod::mod_ullt<Mod>modint;
typedef std::vector<modint>modvec;
typedef FWT_MODINT::FWT_Mod<Mod>FWT;
typedef std::pair<bol,modint>Pair;
typedef std::vector<Pair>vec;
uint m;
modint Len[65];
modvec User(vec A){
    modvec U(m+1);for(uint i=m;i;i--)U[i-1]=U[i]+A[i].second*Len[i];
    return U;
}
vec mul(vec A,vec B){
    vec Ans(m+1);modvec UserA=User(A),UserB=User(B);
    for(uint i=0;i<m;i++){
        Ans[i].first=A[i].first==B[i].first;
        Ans[i+1].second+=Ans[i].second+A[i].second*B[i].second*Len[i];
        Ans[i].second+=A[i].second*UserB[i]+B[i].second*UserA[i];
    }
    Ans[m].second+=A[m].second*B[m].second;
    return Ans;
}
vec get(ullt r){
    vec Ans(m+1);
    for(uint i=0;i<m;i++)
        if(r>=(1llu<<(m-i-1)))Ans[i].first=0,Ans[i].second=1,r-=1llu<<(m-i-1);
        else Ans[i].first=1,Ans[i].second=0;
    Ans[m].second=r;
    return Ans;
}
modint get(vec A){
    modint ans;
    for(uint i=0;i<m;i++){
        if(i<(m+1)/2){
            ans+=A[i].second*(1llu<<((m+1)/2-i-1));
            continue;
        }
        if(A[i].first!=A[m-i-1].first){ans+=A[i].second;return ans;}
    }
    ans+=A[m].second;
    return ans;
}
ullt Rev[1u<<16|1],L[45],R[45];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
#endif
    for(uint i=1;i<(1u<<16);i++)Rev[i]=Rev[i>>1]>>1|(i&1?1u<<15:0);
    uint n;scanf("%u%u",&n,&m);
    auto Reverse=[&](ullt v){
        if(m<=16)return Rev[v]>>(16-m);
        if(m<=32)return Rev[v&65535]<<(m-16)|Rev[v>>16]>>(32-m);
        if(m<=48)return Rev[v&65535]<<(m-16)|Rev[v>>16&65535]<<(m-32)|Rev[v>>32]>>(48-m);
        return Rev[v&65535]<<(m-16)|Rev[v>>16&65535]<<(m-32)|Rev[v>>32&65535]<<(m-48)|Rev[v>>48]>>(64-m);
    };
    if(m<=20){
        FWT s;s.bzr(1u<<m);
        std::vector<modvec>A(n);
        for(auto&v:A){
            ullt l,r;
            scanf("%llu%llu",&l,&r);
            v.resize(1llu<<m);
            while(l<=r)v[l++]=1;
            s.XOR(v,0);
        }
        for(uint i=1;i<n;i++)for(uint j=0;j<(1u<<m);j++)A[i][j]*=A[i-1][j];
        for(auto&v:A){
            s.XOR(v,1);
            modint ans;
            for(uint j=0;j<(1u<<m);j++)if(j==Reverse(j))ans+=v[j];
            ans.println();
        }
        return 0;
    }
    bol op=1;
    for(uint i=0;i<n;i++)scanf("%llu%llu",L+i,R+i),op&=!L[i]&&((++R[i])>>m);
    if(op){
        for(uint i=1;i<=n;i++)(modint(2)^(m*(i-1)+(m+1)/2)).println();
        return 0;
    }
    Len[m]=Len[m-1]=1;for(uint i=m-2;~i;i--)Len[i]=Len[i+1]*2;
    for(uint i=1;i<=n;i++){
        modint ans;
        for(ullt S=0;S<(1llu<<i);S++){
            vec v=get(1);
            modint wil(1);
            for(uint j=0;j<i;j++)(S>>j&1)?(wil=-wil,v=mul(v,get(L[j]))):v=mul(v,get(R[j]));
            ans+=wil*get(v);
        }
        ans.println();
    }
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
