#include<cstdio>
#include<algorithm>
#include<iostream>
#define ri register int
#define il inline
#define gc getchar()
using namespace std;
il int read()
{
	int ans=0,f=1;char ch=gc;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=gc;}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc;
	return ans*f; 
}
const int mm=11000;
int cnt=0,a,b,flag,step[mm];
il void check(int resa,int resb)
{
	if(1LL*resa*b==1LL*resb*a) 
	{
		printf("%d\n",cnt);
		for(ri i=1;i<=cnt;i++) printf("%d ",step[i]);
		exit(0);
	}
}
il void dfs(int x,int resa,int resb,int last)
{
	if(x>cnt) {check(resa,resb);return ;}
	int now=last+1;
	while(true)
	{
		int d=__gcd(resb,now),tmpa=resa*now/d+resb/d,tmpb=resb*now/d;
		if(1.0*tmpa/tmpb>1.0*a/b) {now++;continue;}
		if(1.0*(tmpa+resb*(cnt-x)/d)/tmpb<1.0*a/b) return ;
		step[x]=now,dfs(x+1,tmpa,tmpb,now),now++;
	 } 
}
il void file()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
}
int main()
{
	file();
	a=read(),b=read(),flag=false;
	if(a==0) {puts("0");return 0;}
	while(!flag) ++cnt,dfs(1,0,1,0);
	return 0;
}
