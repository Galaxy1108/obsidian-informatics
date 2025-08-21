// 那就是希望。
// 即便需要取模，也是光明。

// 按某经典状压题的技巧，整出 2,3 同构类，建 Young 表，取 Young 表外侧紧贴的结点为权，连成链状，容易分析出节点数是 1n 级别的，同时可以保证正确性。
// 值域也是 3n 内的。
// 问题是，这样子对于 n mod 18 = 1,2,5,7,8,11,13,14,17 的答案节点数是恰好不够用 1 个的。
// 考虑怎么压掉那一个点的贡献。
// 。。。
// 直觉上，很大概率有如下事实：
// min{lcm(x,y)|x,y 对应 Young 表只有单点} 在 n 很大时趋于在 3.5v - 4v 间。
// 感性证明很简单，取 5v,7v 在比 n/2 略大一小点位置上的情况，用 3 个节点合并 2 个元素即可。
// 。。。
// 似乎在 n 较大时都是对的？
// 对于 n 比较小的情况，对剩余部分直接使用 lcm(a,b,c,d,...) - a,b,c,d,... 的暴力值域做法压位，减小节点个数，应该就可以了。 
// 即：特别的，对于 n=5 时，此做法要作特判。

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
const uint Lim=11000;
bol Gone[2505];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
#endif
    uint n;scanf("%u",&n);
    if(n==5){puts("10 15 6 8 4"),puts("1 2"),puts("2 3"),puts("3 4"),puts("4 5");return 0;}
    std::vector<uint>Ps,Lines,Ans;
    for(uint i=1;i<=n;i++)if(!Gone[i]){
        if(i>n/2)Ps.push_back(i),Gone[i]=1;
        else if(i>n/3)Lines.push_back(i),Gone[i]=Gone[i<<1]=1;
        else{
            uint v=i;
            while(v<=n){
                uint t=v;while(t<=n)Gone[t]=1,t*=3;
                Ans.push_back(t),v<<=1;
            }
            Ans.push_back(v);
        }
    }
    if(Ps.size()*2+Lines.size()*3+Ans.size()==n){
        // fprintf(stderr,"qwq\n");
        for(auto s:Ps)Ans.push_back(s),Ans.push_back(s*2);
        for(auto s:Lines)Ans.push_back(s),Ans.push_back(s*2),Ans.push_back(s*2);
        for(uint i=0;i<n;i++)printf("%u%c",Ans[i]," \n"[i==n-1]);
        for(uint i=1;i<n;i++)printf("%u %u\n",i,i+1);
        return 0;
    }
    for(uint i=0;i<Ps.size();i++)for(uint j=i+1;j<Ps.size();j++)if(lcm(Ps[i],Ps[j])<=Lim){
        for(auto s:Ps)if(s!=Ps[i]&&s!=Ps[j])Ans.push_back(s),Ans.push_back(s*2);
        for(auto s:Lines)Ans.push_back(s),Ans.push_back(s*2),Ans.push_back(s*2);
        Ans.push_back(Ps[i]),Ans.push_back(lcm(Ps[i],Ps[j])),Ans.push_back(Ps[j]);
        for(uint i=0;i<n;i++)printf("%u%c",Ans[i]," \n"[i==n-1]);
        for(uint i=1;i<n;i++)printf("%u %u\n",i,i+1);
        return 0;
    }
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
