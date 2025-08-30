#include<cstdio>
using namespace std;
int a[20],vis[20],n=10;
void output(int a)
{
	if(a==10) putchar('1'),putchar('0');
	else putchar(a|48);
	putchar(' ');
}
void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++) output(a[i]);
		putchar('\n');
		return;
	}
	for(int i=1;i<=n/2;i++)
	{
		int y=2*i-(x&1);
		if(!vis[y])
		{
			vis[y]=1;
			a[x]=y;
			dfs(x+1);
			vis[y]=0;
		}
	}
}
int main()
{
	freopen("constr.out","w",stdout);
	printf("%d\n",120*120);
	dfs(1);
}