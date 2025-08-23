// 这就是你的 NOIplus 模拟赛？
// 这题事实上比 t1t2 还 easy 吧。
// 二次扫描换根 dp 即可。
// 1e7 个 vector /oh
// 前向星即可。
// 会不会爆栈啊？
// 啊，要开人工栈？
// 这就是你们的高质量模拟赛？
// 资源限制合理？指输入将近 200mb？
// 你们这害人不浅啊！

// 哦输入输出格式更新啦！
// 只好重新来吧。

#include <algorithm>
#include <unordered_map>
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
namespace Fread{
const int SIZE= 1 << 16;
	char buf[SIZE],*S,*T;
	inline char getchar(){if(S==T){T=(S=buf)+
	fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}
} // namespace Fread
#define getchar() Fread::getchar()
uint Last[10000005],End[10000005],Fath[10000005],Val[10000005],F[10000005],Siz[10000005];
ullt Ans[10000005],Ans2[10000005],User[10000005];
uint Stack[10000005],tp;
uint Cnt[10000005],Cnt2[10000005];
inline uint read(){
    uint ans=0;chr c;do c=getchar();while(c>'9'||c<'0');
    do ans=ans*10+(c^'0'),c=getchar();while(c>='0'&&c<='9');return ans;
}
std::unordered_map<ullt,uint>M;
int main(){
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
#else
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
#endif
    uint n=read();
    for(uint i=0;i<n;i++)End[i]=-1;
    for(uint i=1;i<n;i++)Last[i]=End[Fath[i]=read()-1],End[Fath[i]]=i,Val[i]=read();
    for(uint i=n-1;i;i--)Siz[Fath[i]]+=Siz[i]+=1,_max(Ans[Fath[i]],Ans2[i]=std::max(Ans[i],(ullt)Siz[i]*Val[i]));
    for(uint p=0;p<n;p++){
        tp=0;
        for(uint s=End[p];~s;s=Last[s])Stack[tp++]=s;
        _max(Ans2[p],(ullt)(n-Siz[p])*Val[p]);
        ullt ans=Ans2[p],user;
        for(uint i=0;i<tp;i++)User[Stack[i]]=ans,_max(ans,Ans2[Stack[i]]);
        ans=0;
        for(uint i=tp-1;~i;i--)user=Ans2[Stack[i]],Ans2[Stack[i]]=std::max(User[Stack[i]],ans),_max(ans,user);
    }
    // for(uint i=0;i<n;i++)
    //     printf("%llu %llu\n",Ans[i],Ans2[i]);
    for(uint i=0;i<n;i++)Cnt[i]=Ans[i]>=Ans2[i],Cnt2[i]=Ans[i]<=Ans2[i];
    for(uint p=1;p<n;p++)if(Ans[p]==Ans[Fath[p]])Cnt[p]+=Cnt[Fath[p]];
    for(uint p=n-1;p;p--){
        if(Ans[Fath[p]]==(ullt)Siz[p]*Val[p])F[p]+=Cnt[Fath[p]];
    }
    // for(uint i=1;i<n;i++)printf("%u%c",F[i]," \n"[i==n-1]);
    for(uint p=1;p<n;p++)if(Ans2[p]==Ans2[Fath[p]])Cnt2[p]+=Cnt2[Fath[p]];
    for(uint p=n-1;p;p--)if(Ans2[Fath[p]]==(ullt)Siz[p]*Val[p])F[p]-=Cnt2[Fath[p]];
    for(uint i=0;i<n;i++)Cnt2[i]=Ans[i]<=Ans2[i];
    for(uint p=n-1;p;p--)if(Ans2[p]==Ans2[Fath[p]])Cnt2[Fath[p]]+=Cnt2[p];
    for(uint p=n-1;p;p--){
        if(Ans2[p]==(ullt)Siz[p]*Val[p])F[p]-=Cnt2[p];
        if(Ans2[p]==(ullt)(n-Siz[p])*Val[p])F[p]+=Cnt2[p];
    }
    for(uint i=0;i<n;i++)if(Ans[i]<=Ans2[i])M[Ans2[i]]++;
    for(uint p=1;p<n;p++)if(M.count((ullt)Siz[p]*Val[p]))F[p]+=M[(ullt)Siz[p]*Val[p]];
    // for(uint i=1;i<n;i++)printf("%u\n",F[i]);
    uint ans=0;
    for(uint i=0;i<n;i++)ans^=F[i];
    printf("%u\n",ans);
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
