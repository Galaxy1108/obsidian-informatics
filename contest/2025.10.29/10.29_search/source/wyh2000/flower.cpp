#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define N 85
using namespace std;
int n,p[N]; char st[N][N];
void dfs(int t)
{
	int i;
	if(!t){
		for(i=1;i<=2*n;i++)
			printf("%s\n",st[p[i]]+1);
		exit(0);
	  }
	for(i=1;i<=2*n-t-1;i++)
		if(!p[i]&&!p[i+t+1]){
			p[i]=p[i+t+1]=t;
			dfs(t-1);
			p[i]=p[i+t+1]=0;
		  }
}
int main()
{
	int i;
	freopen("flower.in","r" , stdin);
	freopen("flower.out","w",stdout);
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
		scanf("%s",st[i]+1);
	dfs(n);
	return 0;
}
