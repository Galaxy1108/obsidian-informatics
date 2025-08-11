#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 12;
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
int n,c[MAXN];
int p[MAXN];
inline int l(int x)
{
	if (x==1) return n;
	return x-1;
}
inline int r(int x)
{
	if (x==n) return 1;
	return x+1;
}
int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	n = read();
	for (int i=1;i<=n;i++) c[i] = read();
	for (int i=1;i<=n;i++)
	{
		if (c[r(i)]>c[i]) p[i] = r(i);
		else p[i] = i;
	}
	for (int i=1;i<=n;i++)
	{
		if (p[l(i)]==i&&p[i]==i&&p[l(l(i))]!=l(i)&&c[i]<2*c[l(i)])
			p[l(i)] = l(i);
		if (p[i]==i&&p[l(i)]==i&&p[r(i)]!=r(i)&&c[i]<2*c[r(i)])
			p[i] = r(i);
	}
	for (int i=1;i<=n;i++)
		printf("%d ",p[i]);
	return 0;
}
