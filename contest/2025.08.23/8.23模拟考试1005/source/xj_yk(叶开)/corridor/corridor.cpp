// 和棋局莫名相似……
// 倍增暴力。

#include <algorithm>
#include <map>
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
uint A[2][21][1000005],tp;
uint X[1000005],Y[1000005];
std::map<uint,uint>R[50005],C[50005];
uint n,m;
voi insert(uint x,uint y){
    X[tp]=x,Y[tp]=y;
    R[X[tp]][Y[tp]]=tp;
    C[Y[tp]][X[tp]]=tp;
    tp++;
}
voi build(){
    for(uint i=0;i<tp;i++){
        if(i<(n+m)*2&&i>=n+m)A[0][0][i]=A[1][0][i]=i;
        else
            A[0][0][i]=R[X[i]].upper_bound(Y[i])->second,
            A[1][0][i]=C[Y[i]].upper_bound(X[i])->second;
    }
    for(uint i=1;i<=20;i++)for(uint p=0;p<tp;p++)
        A[0][i][p]=A[i==1][i-1][A[0][i-1][p]],
        A[1][i][p]=A[i!=1][i-1][A[1][i-1][p]];
}
int main(){
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
#endif
    uint q;scanf("%*u%u%u%u",&n,&m,&q);
    for(uint i=1;i<=n;i++)insert(i,0);
    for(uint i=1;i<=m;i++)insert(0,i);
    for(uint i=1;i<=n;i++)insert(i,m+1);
    for(uint i=1;i<=m;i++)insert(n+1,i);
    while(q--){uint x,y;scanf("%u%u",&x,&y),insert(x,y);}
    build();
    scanf("%u",&q);
    while(q--){
        uint op;scanf("%u",&op);
        if(op==1){
            uint x,y;scanf("%u%u",&x,&y);insert(x,y);build();
        }else{
            uint x,y,t;scanf("%u%u%u",&x,&y,&t);
            uint p=R[x][y];
            bol op=y;
            for(uint i=20;~i;i--)if(t>=(1u<<i))p=A[op][i][p],t-=1u<<i;
            printf("%u %u\n",X[p],Y[p]);
        }
    }
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
