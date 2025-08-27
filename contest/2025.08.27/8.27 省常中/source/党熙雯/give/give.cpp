#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int m,s,n;
int a[100];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ans=0;
void dfs(int k,int sum)
{
	if(k==m)
	{
		if(sum==s) ans^=1;
		return ;
	}
	if(sum>s) return ;
	for(int i=1;i<=n;i++)
	{
		dfs(k+1,sum+a[i]);
	}
}
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	int T=fread();
	while(T--)
	{
		m=fread(),s=fread(),n=fread();
		for(int i=1;i<=n;i++) a[i]=fread();
		if(n==1)
		{
			if(m*a[1]==s) cout<<1<<endl;
			else
			cout<<0<<endl;
		}
		else
		{
			dfs(0,0);
			cout<<ans<<endl;
		}
		ans=0;
		memset(a,0,sizeof(a));
	}
	return 0;
}


