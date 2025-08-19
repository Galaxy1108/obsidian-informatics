#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
long long n,s[maxn],p[maxn],c[maxn],f[maxn],dp[maxn],que[maxn],head,en;
double solve(int x,int y){return 1.0*(dp[y]-dp[x]-f[y+1]+f[x+1]+p[y]*s[y+1]-p[x]*s[x+1])/(p[y]-p[x]);}
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++)
	{
		s[i]=qread();
		p[i]=p[i-1]+qread();
		c[i]=qread();
		f[i]=f[i-1]+p[i-1]*(s[i]-s[i-1]);
	}
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(head<en&&solve(que[head],que[head+1])<s[i])head++;
		dp[i]=dp[que[head]]+f[i]-f[que[head]]-p[que[head]]*(s[i]-s[que[head]])+c[i];
		while(head<en&&solve(que[en-1],que[en])>=solve(que[en],i))en--;
		que[++en]=i;
	}
	cout<<dp[n];
	return 0;
}
