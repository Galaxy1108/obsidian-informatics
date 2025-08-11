#include <cstdio>
using namespace std;
const int SIZE = 1<<21;
const int mod = 998244353;
const int MAXN = 5000 + 12;
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
int n,m,s[MAXN];
int f[MAXN][MAXN];
inline void upd(int&x,int y)
{
	x += y;
	if (x>=mod) x -= mod;
}
void work1()
{
	int ans = 1;
	for (int i=1;i<=n;i++)
		if (s[i]==0)
			ans = 1ll*ans*m%mod;
	printf("%d",ans);
}
void work2()
{
	f[0][0] = 1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=m+1;j++)
		{
			if (s[i+1]==1&&j<=m) upd(f[i+1][j+1],f[i][j]);
			if (s[i+1]==0)
			{
				upd(f[i+1][j],1ll*f[i][j]*j%mod);
				if(j<=m) upd(f[i+1][j+1],1ll*f[i][j]*(m-j)%mod);
			 } 
		 }
	int ans = 0;
	for (int j=0;j<=m+1;j++)
		upd(ans,f[n][j]);
	printf("%d",ans);
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n = read(),m = read();
	for (int i=1;i<=n;i++) s[i] = read();
	if (m>=n) work1();
	else work2();
	return 0;
}
