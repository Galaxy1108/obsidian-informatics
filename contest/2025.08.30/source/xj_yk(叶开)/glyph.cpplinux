// 那就是希望。
// 即便需要取模，也是光明。

// 二维分治。

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
ullt A[305][305],Dis[305][305],Ans[200005];
uint X1[200005],X2[200005],Y1[200005],Y2[200005];
const ullt inf=3e15;
voi solve(uint l,uint r,uint u,uint d,std::vector<uint>&Q){
    if(l>=r||u>=d||Q.empty())return;
    if(l+1==r){
        for(uint i=u;i<d;i++)Dis[l][i+1]=Dis[l][i]+A[l][i];
        for(auto q:Q)Ans[q]=Dis[X2[q]][Y2[q]+1]-Dis[X1[q]][Y1[q]];
        return;
    }
    if(u+1==d){
        for(uint i=l;i<r;i++)Dis[i+1][u]=Dis[i][u]+A[i][u];
        for(auto q:Q)Ans[q]=Dis[X2[q]+1][Y2[q]]-Dis[X1[q]][Y1[q]];
        return;
    }
    if(r-l>d-u){
        uint mid=(l+r)>>1;
        std::vector<uint>L,R,Now;
        for(auto q:Q)if(X2[q]<mid)L.push_back(q);
        else if(X1[q]>=mid)R.push_back(q);
        else Now.push_back(q);
        solve(l,mid,u,d,L),solve(mid,r,u,d,R);
        for(uint p=u;p<d;p++){
            Dis[mid-1][p]=A[mid-1][p],Dis[mid][p]=A[mid][p];
            for(uint j=p;j<d;j++)for(uint i=mid+(j==p);i<r;i++)
                Dis[i][j]=A[i][j]+std::min(i>mid?Dis[i-1][j]:inf,j>p?Dis[i][j-1]:inf);
            for(uint j=p;j>=u&&~j;j--)for(uint i=mid-1-(j==p);i>=l&&~i;i--)
                Dis[i][j]=A[i][j]+std::min(i<mid-1?Dis[i+1][j]:inf,j<p?Dis[i][j+1]:inf);
            for(auto q:Now)if(Y1[q]<=p&&Y2[q]>=p)
                _min(Ans[q],Dis[X2[q]][Y2[q]]+Dis[X1[q]][Y1[q]]);
        }
    }
    else{
        uint mid=(u+d)>>1;
        std::vector<uint>L,R,Now;
        for(auto q:Q)if(Y2[q]<mid)L.push_back(q);
        else if(Y1[q]>=mid)R.push_back(q);
        else Now.push_back(q);
        solve(l,r,u,mid,L),solve(l,r,mid,d,R);
        for(uint p=l;p<r;p++){
            Dis[p][mid-1]=A[p][mid-1],Dis[p][mid]=A[p][mid];
            for(uint j=p;j<r;j++)for(uint i=mid+(j==p);i<d;i++)
                Dis[j][i]=A[j][i]+std::min(i>mid?Dis[j][i-1]:inf,j>p?Dis[j-1][i]:inf);
            for(uint j=p;j>=l&&~j;j--)for(uint i=mid-1-(j==p);i>=u&&~i;i--)
                Dis[j][i]=A[j][i]+std::min(i<mid-1?Dis[j][i+1]:inf,j<p?Dis[j+1][i]:inf);
            for(auto q:Now)if(X1[q]<=p&&X2[q]>=p)
                _min(Ans[q],Dis[X2[q]][Y2[q]]+Dis[X1[q]][Y1[q]]);
        }
    }
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("glyph.in","r",stdin);
    freopen("glyph.out","w",stdout);
#endif
    uint n,q;scanf("%u%u",&n,&q);for(uint i=0;i<n;i++)for(uint j=0;j<n;j++)scanf("%llu",A[i]+j);
    std::vector<uint>Q;
    for(uint i=0;i<q;i++)
        Q.push_back(i),scanf("%u%u%u%u",X1+i,X2+i,Y1+i,Y2+i),
        X1[i]--,X2[i]--,Y1[i]--,Y2[i]--,Ans[i]=inf;
    solve(0,n,0,n,Q);
    for(uint i=0;i<q;i++)printf("%llu\n",Ans[i]);
    return 0;
}

// 那就是希望。
// 即便需要取模，也是光明。
