#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[100];
char name[50][20];

void dfs(int x)
{
	if (x==0)
		{
			for (int i=1; i<=2*n; i++)
				printf("%s\n",name[a[i]]);
			exit(0);
		}
	for (int i=1; i<2*n-x; i++)
		if ((!a[i])&&(!a[i+x+1]))
			a[i]=a[i+x+1]=x,dfs(x-1),a[i]=a[i+x+1]=0;
}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%s",name[i]);
	dfs(n);
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	work();
	return 0;
}
