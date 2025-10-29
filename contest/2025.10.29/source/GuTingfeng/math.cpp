/*
  Program: math
  Copyright by G10
  Please do not copy it
  Or Mr.Xiang will invite you with a cup of tee
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define File(S) freopen(S".in","r",stdin);freopen(S".out","w",stdout);
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;

typedef long long LL;

const int INF=2147483647;

LL getint()
{
    LL res=0,p=1;
    char ch=getchar();
    while ((ch<'0'||ch>'9') && ch!='-') ch = getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

inline int gcd(int a,int b)
{
    int r;
    while (b) { r=a%b;a=b;b=r; }
    return a;
}

struct REAL
{
    int a,b;
    REAL(){}
    REAL(int A,int B){a=A,b=B;int g=gcd(a,b);a/=g,b/=g;}
    bool operator < (const REAL R) const {
        return (a*R.b<R.a*b);
    }
    REAL operator + (const REAL R) const {
        REAL S;
        S.a=a*R.b+R.a*b;
        S.b=b*R.b;
        int g=gcd(S.a,S.b);
        S.a/=g,S.b/=g;
        return S;
    }
    REAL operator - (const REAL R) const {
        REAL S;
        S.a=a*R.b-R.a*b;
        S.b=b*R.b;
        int g=gcd(S.a,S.b);
        S.a/=g,S.b/=g;
        return S;
    }
    REAL operator += (const REAL R) {
        *this=*this+R;
        return *this;
    }
    REAL operator -= (const REAL R) {
        *this=*this-R;
        return *this;
    }
}tar,res;

int ans[1050];
int Lim;

bool dfs(int x,int st)
{
    if (x==Lim) {
        if (res.a!=1) return 0;
        else {
            ans[x]=res.b;
            return 1;
        }
    }
    int i;
    for (i=st;res<REAL(Lim-x+1,i);i++) {
        if (!(res<REAL(1,i))) {
            res-=REAL(1,i);
            ans[x]=i;
            if (dfs(x+1,i+1)) return 1;
            res+=REAL(1,i);
            ans[x]=0;
        }
    }
    return 0;
}

int main()
{
    File("math");
    tar.a=getint();tar.b=getint();
    res=tar;
    int i;
    for (Lim=1;;Lim++) {
        if (dfs(1,1)) {
            printf("%d\n",Lim);
            for (i=1;i<=Lim;i++) printf("%d ",ans[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}


