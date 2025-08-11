#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1.5e5 + 12,SIZE = 1<<21;
char buf[SIZE],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin);
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
int x[MAXN],y[MAXN],z[MAXN],ans=-1;
int n;
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	n = read();
	for (int i=1;i<=n;i++)
		x[i] = read(),y[i] = read(),z[i] = read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
			{
				if (x[i]>x[j]&&x[i]>x[k]&&y[j]>y[i]&&y[j]>y[k]&&z[k]>z[i]&&z[k]>z[j])
					ans = max(ans,x[i]+y[j]+z[k]);
			}
	printf("%d",ans);
	return 0;
}
