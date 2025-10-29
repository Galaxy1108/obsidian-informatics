#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,a[100],op,vis[50];
char ch[50][100];
void dfs(register int p)
{
	if(p==(n<<1)+1)
	{
		for(register int i=1;i<=(n<<1);++i)
		{
			cout<<(ch[a[i]]+1)<<'\n'; 
		}
		op=1;
		return;
	}
	if(a[p])
	{
		dfs(p+1);
		return ;
	}
	for(register int i=n;i;--i)
	{
		if(!vis[i])
		{
			if(!a[p+i+1]&&p+i+1<=(n<<1))
			{
				vis[i]=1;
				a[p]=a[p+i+1]=i;
				dfs(p+1);
				if(op)return ;
				a[p]=a[p+i+1]=0;
				vis[i]=0;
			}
		}
	}
	return ;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	n=qread();
	for(register int i=1;i<=n;++i)cin>>(ch[i]+1);
	dfs(1);
	return 0;
}
