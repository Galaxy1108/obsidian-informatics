#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
long long h[2000005],le[2000005],ri[2000005],stk[2000005],st[2000005][30];
long long ans,top,maxn=-1;
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(int i=1;i<=n;i++)
	{
		st[i][0]=h[i];
	}
	for(int j=1;j<=29;j++)
	{
		for(int i=1;i+(1<<j)<=n+1;i++)
		{
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(h[stk[top]]>h[i]&&top)
		{
			ri[stk[top]]=i-1;
			top--;
		}
		stk[++top]=i;
	}
	while(top)
	{
		ri[stk[top]]=n;
		top--;
	}
	for(int i=n;i>=1;i--)
	{
		while(h[stk[top]]>h[i]&&top)
		{
			le[stk[top]]=i+1;
			top--;
		}
		stk[++top]=i;
	}
	while(top)
	{
		le[stk[top]]=1;
		top--;
	}
	for(int i=1;i<=n;i++)
	{
		long long k=log2(ri[i]-le[i]+1);
		long long currmaxn=max(st[le[i]][k],st[ri[i]-(1<<k)+1][k]);
		maxn=max(maxn,currmaxn*h[i]*(ri[i]-le[i]+1));
	}
	cout<<maxn;
	return 0;
}
