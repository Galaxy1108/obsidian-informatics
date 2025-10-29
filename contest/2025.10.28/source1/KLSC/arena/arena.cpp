#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,k=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')k=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*k;
}
int n,x,ans,a[505];
inline bool check()
{
	int delta=0,k=0;
	while(k!=n)
	{
		if(k==n-1)return false;
		delta+=n-k-1;
		k=0;
		for(int i=1;i<=n;++i)if(delta>=a[i])++k;
	}
	return true;
}
void dfs(int k,int pre)
{
	if(k==n+1)
	{
		if(check())++ans;
		return;
	}
	for(int i=pre;i<=x;++i)
	{
		a[k]=i;
		dfs(k+1,i);
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),x=read();
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
