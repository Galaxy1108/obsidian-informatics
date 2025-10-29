#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int qread()
{
	register int a=0,f=1;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,s,a[510],b[510];
long long ans;
void dfs(register int h)
{
	if(h==n+1)
	{
		int cnt=n-1;
		for(register int i=1;i<=n;++i)b[i]=a[i];
		sort(b+1,b+1+n);
		for(register int i=1;i<=n;++i)
		{
			if(b[i]>cnt)
			{
				if(i==n)return;
				cnt+=((b[i]-cnt-1)/(n-i)+1)*(n-i);
			}
		}
		++ans;
		return ;
	}
	for(register int i=1;i<=s;++i)
	{
		a[h]=i;
		dfs(h+1);
	}
	return ;
}
inline long long qpow(register long long x,register int y)
{
	long long cx=1;
	while(y)
	{
		(y&1)?(cx*=x)%=mod:1;
		(x*=x)%=mod;
		y>>=1;
	}
	return cx;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=qread();
	s=qread();
	if(s<=n)ans=qpow(s,n);
	if(n==2)ans=s;
	else dfs(1);
	printf("%lld",ans);
	return 0;
} 
