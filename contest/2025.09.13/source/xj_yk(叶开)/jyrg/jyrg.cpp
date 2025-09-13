// 那就是希望。
// 即便需要取模，也是光明。

// 设 A_i  = C_i + i。
// 容易发现每次操作就是交换 C_i。
// 然后最后要使得 C_i 单调减。
// 如果有相等的 C_i，直接输出 -1。
// 证明很简单。
// 写成一次函数的形式，即 R^2/span{(1,1)}
// 然后证明若 C_i <= C_{i+1}，则 A 不可能单调不增。
// 然后反之整个序列单调减，此时又容易证明必然可行。

// 考虑对于一般情况，如何快速求解。
// 。。。
// 二分答案显然不方便。
// 考虑维护前缀单调减序列，每次操作把末尾元素按插入排序的方法插进前面。
// 容易证明，这么做可以保持最优性。
// 关键在于如何找到最大解在哪里被贡献到。
// 这个东西随便整个平衡树 / 权值线段树维护一下就完了。
// 值得注意的是，权值线段树最开始初值应为 -inf，而且应资瓷区间加、区间最大值、单点修改。
// 记得要离散化。

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
const llt inf=2e18;
struct Seg{
    Seg*L,*R;uint len;llt tag,v;
    Seg(uint n):L(NULL),R(NULL),len(n),tag(0),v(-inf){if(n>1)L=new Seg(n>>1),R=new Seg(n-(n>>1));}
    ~Seg(){
        if(L)delete L;
        if(R)delete R;
        L=R=NULL;
    }
    voi pushdown(){if(tag)L->add(0,len>>1,tag),R->add(0,len-(len>>1),tag),tag=0;}
    voi pushup(){v=std::max(L->v,R->v);}
    voi add(uint l,uint r,llt w){
        if(l>=r)return;
        if(!l&&r==len){v+=w;tag+=w;return;}
        pushdown();
        if(l<(len>>1))
            if(r<=(len>>1))L->add(l,r,w);
            else L->add(l,len>>1,w),R->add(0,r-(len>>1),w);
        else R->add(l-(len>>1),r-(len>>1),w);
        pushup();
    }
    voi chg(uint p,llt w){
        if(len==1){v=w+tag;return;}
        pushdown();
        p<(len>>1)?L->chg(p,w):R->chg(p-(len>>1),w);
        pushup();
    }
    llt find(uint l,uint r){
        if(l>=r)return-inf;
        if(!l&&r==len)return v;
        pushdown();
        if(l<(len>>1))
            if(r<=(len>>1))return L->find(l,r);
            else return std::max(L->find(l,len>>1),R->find(0,r-(len>>1)));
        else return R->find(l-(len>>1),r-(len>>1));
    }
};
llt C[100005],P[100005];
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("jyrg.in","r",stdin);
    freopen("jyrg.out","w",stdout);
#endif
    uint t;scanf("%u",&t);
    while(t--){
        uint n;scanf("%u",&n);
        for(uint i=0;i<n;i++)scanf("%lld",C+i),P[i]=C[i]-=i;
        std::sort(P,P+n);if(std::unique(P,P+n)!=P+n){puts("-1");continue;}
        Seg*S=new Seg(n);
        llt ans=0;
        for(uint i=0;i<n;i++){
            uint p=std::lower_bound(P,P+n,C[i])-P;
            _max(ans,C[i]+S->find(0,p));
            S->add(0,p,2);
            S->chg(p,C[i]+1);
        }
        printf("%lld\n",ans);
        fflush(stdout);
        delete S;
    }
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
