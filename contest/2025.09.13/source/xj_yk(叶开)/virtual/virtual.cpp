// 那就是希望。
// 即便需要取模，也是光明。

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
chr C[2000005];bol Op[2000005];
uint Ans[2000005],P[2000005];
std::vector<uint>Way[2000005];
voi dfs(uint p,uint v){
    if(~Ans[p])return;
    Ans[p]=v;for(auto s:Way[p])dfs(s,v);
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    // freopen("QAQ.out","w",stdout);
#else
    freopen("virtual.in","r",stdin);
    freopen("virtual.out","w",stdout);
#endif
    uint n,l,r,q,cnt=0;
    scanf("%u%u%u%s%u",&n,&l,&r,C,&q);
    for(uint i=0;i<n;i++){
        Op[i]=C[i]=='a',Ans[i]=-1;
        if(Op[i])P[cnt++]=i;
    }
    for(uint i=0;i+l<=cnt;i++){
        for(uint j=i?P[i-1]+1:0;j<P[i];j++)Way[j].push_back(j+1),Way[j+1].push_back(j);
        for(uint j=P[i+l-1]+1;j<(i+l==cnt?n:P[i+l]);j++)Way[j-1].push_back(j),Way[j].push_back(j-1);
        Way[P[i]].push_back(P[i+l-1]),Way[P[i+l-1]].push_back(P[i]);
    }
    if(l<r){
        l++;
        for(uint i=0;i+l<=cnt;i++){
            for(uint j=i?P[i-1]+1:0;j<P[i];j++)Way[j].push_back(j+1),Way[j+1].push_back(j);
            for(uint j=P[i+l-1]+1;j<(i+l==cnt?n:P[i+l]);j++)Way[j-1].push_back(j),Way[j].push_back(j-1);
            Way[P[i]].push_back(P[i+l-1]),Way[P[i+l-1]].push_back(P[i]);
        }
    }
    for(uint i=0;i<n;i++)dfs(i,i);
    while(q--){
        uint u,v;
        scanf("%u%u",&u,&v),u--,v--;
        puts(Ans[u]==Ans[v]?"Yes":"No");
    }
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
