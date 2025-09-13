#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 2e6 + 12;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
int n,lk,rk,q;
char s[MAXN];
int cnta[MAXN];
int pre[MAXN],sz[MAXN];
int find(int x){return (x==pre[x])?x:pre[x]=find(pre[x]);}
void unite(int x,int y)
{
	x = find(x),y = find(y);
	if (x==y) return ;
	if (sz[x]>sz[y]) swap(x,y);
	pre[x] = y;
	sz[y] += sz[x];
}
int main()
{
    freopen("virtual.in","r",stdin);
    freopen("virtual.out","w",stdout);
    scanf("%d%d%d",&n,&lk,&rk);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++)
        cnta[i] = cnta[i-1] + (s[i]=='a'),pre[i] = i,sz[i] = 1;
    for (int i=1,lid=1,rid=0;i<=n;i++)
    {
        //int lid = lower_bound(cnta+1,cnta+n+1,cnta[i]+lk-(s[i]=='a')) - cnta;
        //int rid = upper_bound(cnta+1,cnta+n+1,cnta[i]+rk-(s[i]=='a')) - cnta - 1;
        while (cnta[lid]<cnta[i]+lk-(s[i]=='a')) lid ++;
        while (cnta[rid+1]<=cnta[i]+rk-(s[i]=='a')) 
		{
			rid ++;
			if (lid<rid) unite(rid-1,rid);
		}
        if(lid<=rid) unite(i,rid);
    }
    q = read();
    while (q--)
    {
        int x = read(),y = read();
        if (find(x)==find(y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
