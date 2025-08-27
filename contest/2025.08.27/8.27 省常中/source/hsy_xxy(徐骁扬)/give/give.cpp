#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int T;
long long M,S,N,i,tot;
long long num[100];
int a[210],ans;
void dfs(int dep,long long las)
{
	if(dep==tot+1)
	{
		if(las==0) ans^=1;
		return;
	}
	if(las&(num[dep]-1)) return;
	for(int i=1;i<=N&&a[i]*num[dep]<=las;i++)
		dfs(dep+1,las-a[i]*num[dep]);
	return;
}
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	T=Qread();
	while(T--)
	{
		ans=0;
		M=Qread(),S=Qread(),N=Qread();
		for(i=1;i<=N;i++)
			a[i]=Qread();
		for(tot=0;M;M-=M&-M)
			num[++tot]=(M&-M);
		dfs(1,S);
		printf("%d\n",ans);
	}
	return 0;
}