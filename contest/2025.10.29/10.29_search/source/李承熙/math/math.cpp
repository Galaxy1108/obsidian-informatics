#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
long long n,m,que[100010],ed,pos,t;
inline long long Lcm(register long long x,register long long y){return x*y/__gcd(x,y);}
inline void X(register long long az,register long long am)
{
	long long lcm=Lcm(am,m),p=am;
	az*=(lcm/am);
	am=lcm;
	n*=(lcm/m);
	m=lcm;
	if(az>n)
	{
		p=__gcd(n,m);
		n/=p;
		m/=p;
		return ;
	}
	que[++ed]=p;
	n-=az;
	if(!n)return ;
	p=__gcd(n,m);
	n/=p;
	m/=p;
	return ;
}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	n=qread();
	m=qread();
	while(n)
	{
		if(!n)break;
		pos=t=(m-1)/n+1;
		while((m-1)/n+1==pos)
		{
			X(1,t);
			++t;
			if(!n)break;
		}
	}
	printf("%lld\n",ed);
	for(register int i=1;i<=ed;++i)printf("%lld ",que[i]);
	return 0;
}
