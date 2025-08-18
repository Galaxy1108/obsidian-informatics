#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[110];
char ch;
int ans=999999999;
void dfs(int now,int A,int B,int C,int st)
{
	if(now==n+1)
	{
		if(A!=0)st++;
		if(B!=0)st++;
		if(C!=0)st++;
		ans=min(ans,st);
		return;
	}
	if(st>=ans)return;
	while(A+B+C<10&&now<=n)
	{
		if(a[now]==0)A++;
		if(a[now]==1)B++;
		if(a[now]==2)C++;
		now++;
	}
	if(A!=0)dfs(now,0,B,C,st+1);
	if(B!=0)dfs(now,A,0,C,st+1);
	if(C!=0)dfs(now,A,B,0,st+1);
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>ch;
		a[i]=ch-'A';
	}
	dfs(1,0,0,0,0);
	printf("%d",ans);
	return 0;
}
