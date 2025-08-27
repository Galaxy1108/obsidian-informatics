#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+10;
int c[N][N],pr[N][N],g[N],inv[N],ans,n,p,prim[N];
bool vis[N];
__int128 f[N];
int qp(int a,int b) 
{
  int ans = 1;
  a = (a % p + p) % p;
  for (; b; b >>= 1) 
  {
    if (b & 1) ans = (a * ans) % p;
    a = (a * a) % p;
  }
  return ans;
}
signed main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdin);
	inv[1]=1;
	for (int i=2;i<=n;++i) 
	{
  		inv[i]=(p-p/i)*inv[p%i]%p;
	}
	c[1][1]=1;
	if(n<=10)
	{
		for(int i=2;i<=n+1;i++)
		{
			g[i]=1;
			f[i]=1;
			for(int j=1;j<=i;j++)
			{
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				f[i]*=c[i][j];
			}
			int cnt=2;
			while(f[i]>1)
			{
				while(f[i]%cnt==0) f[i]/=cnt,pr[i][cnt]++;
				cnt++;
			}
			for(int j=2;j<=cnt;j++)  if(pr[i][j])g[i]*=(qp(j,pr[i][j]+1)-1)*inv[j-1]%p;
			ans+=g[i];
			ans%=p;
		}
	}
	cout<<ans;
	return 0;
} 
