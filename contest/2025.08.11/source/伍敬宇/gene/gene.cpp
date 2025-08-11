#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 12;
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
int n,L,R;
int a[MAXN],pre[MAXN],nxt[MAXN],fst[MAXN],scd[MAXN];
int pos[MAXN],ans = 1e7; 
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	n = read(),L = read(),R = read();
	for (int i=1;i<=n;i++) a[i] = read();
	for (int i=n;i>=1;i--)
		if (fst[a[i]]==0) fst[a[i]] = i;
		else if (scd[a[i]]==0) scd[a[i]] = i;
	for (int i=1;i<=n;i++) pre[i] = (i==fst[a[i]])?scd[a[i]]:fst[a[i]];
	for (int i=1;i<=1e6;i++) fst[i] = scd[i] = n+1;
	for (int i=1;i<=n;i++)
		if (fst[a[i]]==n+1) fst[a[i]] = i;
		else if (scd[a[i]]==n+1) scd[a[i]] = i;
	for (int i=1;i<=n;i++) nxt[i] = (i==fst[a[i]])?scd[a[i]]:fst[a[i]];
	for (int i=1;i<L;i++) pos[nxt[i]] = i;
	int mx = 0;
	for (int i=n;i>R;i--)
	{
		mx = max(mx,pos[i+1]);
		if (mx<=pre[i]) continue ;
		ans = min(ans,i-mx+1);
	}
	if (ans==1e7) printf("-1");
	else printf("%d",ans);
	return 0;
}
