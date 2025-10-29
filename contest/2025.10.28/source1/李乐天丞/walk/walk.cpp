#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int INF=1e9;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=x*10+(c^48);c=getchar();}
	return x*f;
}
int val[maxn],n,f[maxn],sum[maxn];
int minj=INF;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<=n;i++) val[i]%=2;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+val[i];
	int ans=n;
	for(int l=1;l<=n;l++)
	for(int r=l;r<=n;r++)
	{
		ans=min(ans,sum[l-1]+sum[n]-sum[r]+r-l+1-sum[r]+sum[l-1]);
	}
	printf("%d",ans);
	return 0;
}
