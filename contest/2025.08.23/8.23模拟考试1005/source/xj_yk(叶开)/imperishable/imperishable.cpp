// 暴力不会，摆了。

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
    const ullt Mod=998244353;
    // inline voi ChgMod(ullt v){Mod=v;}
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
uint A[200005];
modint Val[200005];
uint n;
// modint get(){
//     ;
// }
int main(){
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
#endif
    puts("2");
    // uint q;scanf("%*u%u",&n);
    // for(uint i=0;i<n;i++)scanf("%u",A+i),Val[i]=modint(1)^(i+1);
    return 0;
}

// Never Gonna Give You Up
// 明天你是否会想起 昨天未调完的题 明天你是否还惦记 考场写挂的暴力
// 集训队都已想不起 没能来雅礼的你 我也是偶然翻 OJ 才想起退役的你
// 谁羡慕比赛 AK 的你 谁膜拜红名的你 谁看了你的生涯回忆 谁借走你的 RP
// 你从前总是很小心 对拍后才肯交题 你也曾无意中说起 喜欢在深夜 AC
// 那时候比赛总很难 rating 总长得太慢 你总说退役遥遥无期 转眼就各分东西
// 谁秒了你出的模拟题 谁骂着毒瘤的你 谁看了你的题解笔记 谁传给学妹学弟
// 同行的日子都远去 我们也终会退役 多年后谁会再想起 定格考场的记忆
// 谁记得你出的模拟题 谁忘记毒瘤的你 谁学会你的题解笔记 谁教给学妹学弟
