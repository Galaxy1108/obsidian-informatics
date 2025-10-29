#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=20;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=x*10+(c^48);c=getchar();}
	return x*f;
}
inline int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}
struct num{
	int a,b;
	inline void work()
	{
		int f=1;
		if(a<0) {a=-a;f=-f;}
		if(b<0) {b=-b,f=-f;}
		int w=gcd(a,b);
		a=a/w;b=b/w;a=a*f;
	}
};
inline num operator +(const num &x,const num &y)
{
	int w=gcd(x.b,y.b);num res;
	res.a=x.a*y.b/w+y.a*x.b/w;
	res.b=x.b*y.b/w;
	res.work();
	return res;
}
inline num operator -(const num &x,const num &y)
{
	int w=gcd(x.b,y.b);num res;
	res.a=x.a*y.b/w-y.a*x.b/w;
	res.b=x.b*y.b/w;
	res.work();
	return res;
}
int maxdep,ans[maxn];
num t;
inline bool dfs(int dep,num res)
{
	if(dep==maxdep)
	{
		res.work();
		if(res.a==1) {ans[dep]=res.b;return 1;}
		else return 0;
	}
	int minfm=res.b/res.a;
	int maxfm=(res.b+res.a-1)/res.a*maxdep;
	for(int i=minfm;i<=maxfm;i++)
	{
		ans[dep]=i;
		res=res-(num){1,i};
		if(dfs(dep+1,res)) return 1;
		res=res+(num){1,i};
		ans[dep]=0;
	}
	return 0;
}
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	t.a=read();t.b=read();
	t.work();
	maxdep=1;
	while(!dfs(1,t)) maxdep++;
	printf("%lld\n",maxdep);
	for(int i=1;i<=maxdep;i++) printf("%lld ",ans[i]);
	return 0;
}
