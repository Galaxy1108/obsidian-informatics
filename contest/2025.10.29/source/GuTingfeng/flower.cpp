/*
  Program: flower
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

int n;
int used[45],ans[105];

bool dfs(int x)
{
    if (x==n*2+1) return 1;
    if (ans[x]) return dfs(x+1);
    int i;
    for (i=n;i>=1;i--) {
        if (used[i]) continue;
        if (x+i+1>2*n) return 0;
        if (ans[x+i+1]) continue;
        ans[x]=i;ans[x+i+1]=i;used[i]=1;
        if (dfs(x+1)) return 1;
        ans[x]=0;ans[x+i+1]=0;used[i]=0;
    }
    return 0;
}

string S[45];

int main()
{
    File("flower");
    n=getint();
    for (int i=1;i<=n;i++) cin>>S[i];
    memset(used,0,sizeof(used));
    memset(ans,0,sizeof(ans));
    dfs(1);
    for (int i=1;i<=n*2;i++) cout<<S[ans[i]]<<endl;
    printf("\n");
    return 0;
}
