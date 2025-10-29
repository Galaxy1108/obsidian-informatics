/*
  Program: disease
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

const int N=305;
int n,m,dep[N],deg[N];
int E[N*2],next[N*2],h[N],tot;
int q[N],t,end[N],MD;
int blo[N];
int sum,ans;

bool cmp(int a,int b)
{
    return deg[a]>deg[b];
}

void dfs(int x)
{
    int i,j,res;
    bool f=1;
    if (sum>=ans) return;
    if (x>MD) {
        ans=min(sum,ans);
        return;
    }
    res=sum;
    sum+=end[x]-end[x-1];
    for (i=end[x-1]+1;i<=end[x];i++) {
        if (blo[q[i]]) {
            for (j=h[q[i]];j;j=next[j]) {
                blo[E[j]]=1;
            }
            sum--;
        }
        else f=0;
    }
    if (f) { ans=min(sum,ans);return; }
    for (i=end[x-1]+1;i<=end[x];i++) {
        if (blo[q[i]]) continue;
        for (j=h[q[i]];j;j=next[j]) {
            blo[E[j]]=1;
        }
        sum--;
        dfs(x+1);
        sum++;
        for (j=h[q[i]];j;j=next[j]) {
            blo[E[j]]=0;
        }
    }
    sum=res;
    return;
}

int main()
{
    File("disease");
    n=getint();m=getint();
    int i,u,v;
    for (i=1;i<=m;i++) {
        u=getint();v=getint();
        E[++tot]=v;next[tot]=h[u];h[u]=tot;
        E[++tot]=u;next[tot]=h[v];h[v]=tot;
    }
    queue <int> Q;dep[1]=0;Q.push(1);
    while (!Q.empty()) {
        u=Q.front();Q.pop();q[++t]=u;end[dep[u]]=t;MD=dep[u];
        for (i=h[u];i;i=next[i]) {
            v=E[i];
            if (v!=1 && !dep[v]) {
                dep[v]=dep[u]+1;deg[u]++;
                Q.push(v);
            }
        }
    }
    for (i=1;i<=MD;i++) {
        sort(q+end[i-1]+1,q+end[i]+1,cmp);
    }
    ans=INF;
    sum=1;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
