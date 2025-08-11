#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
	return (*iS++);
}
inline int read()
{
	int x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
const int MAXN = 1100 + 12;
int n,psum;
int sta[MAXN],c[MAXN];
int f[MAXN][MAXN];
bool check()
{
	for (int i=0;i<(1<<n);i++)
		if (c[i]>0) return 0;
	return 1;
}
int ans;
int cal(int l,int r)
{
	if (l==r) return 0;
	int md = (l+r)>>1;
	int res = cal(l,md) + cal(md+1,r);
	int na=0,nb=0;
	for (int i=l;i<=r;i++)
		if (sta[i]==0) na++;
		else nb++;
	int suma=0,sumb=0;
	for (int i=l;i<=md;i++)
		for (int j=md+1;j<=r;j++)
			if (sta[i]==0&&sta[j]==0) suma += f[i][j];
			else if (sta[i]==1&&sta[j]==1) sumb += f[i][j];
	if (na<nb) res += suma - sumb;
	else res += sumb - suma;
	return res;
}
void dfs(int i,int sum)
{
	if (i>=(1<<n))
	{
		ans = min(ans,sum+cal(0,(1<<n)-1));
		return ;
	}
	dfs(i+1,sum);
	sta[i] ^= 1;
	dfs(i+1,sum+c[i]);
	sta[i] ^= 1;
}
int main()
{
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	n = read();
	for (int i=0;i<(1<<n);i++)
		sta[i] = read();
	for (int i=0;i<(1<<n);i++)
		c[i] = read();
	for (int i=0;i<(1<<n);i++)
		for (int j=i+1;j<(1<<n);j++)
			f[i][j] = read(),psum += f[i][j];
	if (check()) printf("0");
	else 
	{
		ans = 2e9;
		dfs(1,0);
		printf("%d",ans+psum);
	}
	return 0;
}
