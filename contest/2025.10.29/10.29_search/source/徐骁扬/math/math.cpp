#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
long long ans[2010],nw[2010];
int top,tot=114514;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
void dfs(long long fz,long long fm,long long num)
{
	if(top+(fz*num/fm)>=tot) return;
	if(fz==0)
	{
		memcpy(ans,nw,sizeof(nw));
		tot=top;
		return;
	}
	long long xxy=gcd(fz,fm);
	fz/=xxy,fm/=xxy;
	if(fz*num>=fm)
	{
		nw[++top]=num;
		long long zsh=gcd(num,fm);
		dfs(num/zsh*fz-fm/zsh,num/zsh*fm,num+1);
		nw[top--]=num;
		dfs(fz,fm,num+1);
	}
	else if(fm/fz==num) dfs(fz,fm,num+1);
	else dfs(fz,fm,fm/fz);
	return;
}
int P,Q,gc;
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	P=Qread(),Q=Qread();
	gc=gcd(P,Q);
	P/=gc,Q/=gc;
	dfs(P,Q,1);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}
