// 总得被创死吧。
// 很 Exciting 啊，出题人。
// 硬要出 O(n^2/log n) 的做法是吧。

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
namespace AnyMod
{
    ullt Mod=-1;
    inline voi ChgMod(ullt v){Mod=v;}
    struct ModInt
    {
        private:
            ullt v;inline ullt chg(ullt w){return(w<Mod)?w:w-Mod;}
            inline ModInt _chg(ullt w){ModInt ans;ans.v=(w<Mod)?w:w-Mod;return ans;}
        public:
            ModInt():v(0){}
            ModInt(ullt v):v(v%Mod){}
            bol empty(){return!v;}
            inline ullt val(){return v;}
            friend bol operator<(ModInt a,ModInt b){return a.v<b.v;}
            friend bol operator>(ModInt a,ModInt b){return a.v>b.v;}
            friend bol operator<=(ModInt a,ModInt b){return a.v<=b.v;}
            friend bol operator>=(ModInt a,ModInt b){return a.v>=b.v;}
            friend bol operator==(ModInt a,ModInt b){return a.v==b.v;}
            friend bol operator!=(ModInt a,ModInt b){return a.v!=b.v;}
            inline friend ModInt operator+(ModInt a,ModInt b){return a._chg(a.v+b.v);}
            inline friend ModInt operator-(ModInt a,ModInt b){return a._chg(a.v+a.chg(Mod-b.v));}
            inline friend ModInt operator*(ModInt a,ModInt b){return a.v*b.v;}
            friend ModInt operator/(ModInt a,ModInt b){return b._power(Mod-2)*a.v;}
            friend ModInt operator^(ModInt a,ullt b){return a._power(b);}
            inline ModInt operator-(){return _chg(Mod-v);}
            ModInt sqrt()
            {
                if(power(v,(Mod-1)>>1,Mod)!=1)return 0;
                ModInt b=1;do b++;while(b._power((Mod-1)>>1)==1);
                ullt t=Mod-1,s=0,k=1;while(!(t&1))s++,t>>=1;
                ModInt x=_power((t+1)>>1),e=_power(t);
                while(k<s)
                {
                    if(e._power(1llu<<(s-k-1))!=1)x*=b._power((1llu<<(k-1))*t);
                    e=_power(Mod-2)*x*x,k++;
                }
                return _min(x,-x),x;
            }
            ModInt inv(){return _power(Mod-2);}
            ModInt _power(ullt index){ModInt ans(1),w(v);while(index){if(index&1)ans*=w;w*=w,index>>=1;}return ans;}
            voi read(){v=0;chr c;do c=getchar();while(c>'9'||c<'0');do v=(c-'0'+v*10)%Mod,c=getchar();while(c>='0'&&c<='9');v%=Mod;}
            voi print()
            {
                static chr C[20];uint tp=0;
                ullt w=v;do C[tp++]=w%10+'0',w/=10;while(w);
                while(tp--)putchar(C[tp]);
            }
            voi println(){print(),putchar('\n');}
            ModInt operator++(int){ModInt ans=*this;return v=chg(v+1),ans;}
        public:
            inline ullt&operator()(){return v;}
            inline ModInt&operator+=(ModInt b){return*this=_chg(v+b.v);}
            inline ModInt&operator-=(ModInt b){return*this=_chg(v+chg(Mod-b.v));}
            inline ModInt&operator*=(ModInt b){return*this=v*b.v;}
            ModInt&operator^=(ullt b){return*this=_power(b);}
            ModInt&operator/=(ModInt b){return*this=b._power(Mod-2)*v;}
            ModInt&operator++(){return v=chg(v+1),*this;}
    };
}
typedef AnyMod::ModInt modint;
uint Prime[20005],tp;bol Gone[20005];
ullt Ans[20005];
modint W[300005];
uint Cnt[20005];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
#endif
    uint n;ullt Mod;scanf("%u%llu",&n,&Mod);
    // n=20000;
    for(uint i=2;i<=n;i++)if(!Gone[i]){Prime[tp++]=i;for(uint j=i<<1;j<=n;j+=i)Gone[j]=true;}
    for(uint i=0;i<=n;i++)Ans[i]=1;
    for(auto p:Prime)if(p){
        AnyMod::ChgMod((p-1)*Mod);
        for(uint i=0;i<=n;i++)Cnt[i]=1;
        for(ullt x=p;x<=n;x*=p)for(uint i=x;i<=n;i++)Cnt[i]+=(i/x)*(x-1-i%x);
        uint v=0;
        for(uint i=0;i<=n;i++)_max(v,Cnt[i]);
        // printf("%u\n",v);
        W[0]=1;for(uint i=1;i<=v;i++)W[i]=W[i-1]*p;
        for(uint i=0;i<=n;i++)Ans[i]=Ans[i]*((W[Cnt[i]]-1)()/(p-1))%Mod/* ,modint((W[Cnt[i]]-1)/(p-1)).println() */;
    }else break;
    ullt ans=0;
    for(uint i=1;i<=n;i++)ans+=Ans[i];
    ans%=Mod;
    printf("%llu\n",ans);
    return 0;
}
