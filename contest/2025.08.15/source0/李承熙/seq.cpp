#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
inline void Mod(int &x)
{
	if(x<0)x+=mod;
	if(x>=mod)x-=mod;
	return ;
}
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,a[1000010],m,b[1000010],op[1000010],pw[1000010],c[1000010],ans,mx;
struct bit
{
	int val[1000010];
	inline void adds(int p,int x){for(;p<=n;p+=p&-p)Mod(val[p]+=x);return ;}
	inline int Q(int p){int an=0;for(;p;p-=p&-p)Mod(an+=val[p]);return an;}
}t;
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n=qread();pw[0]=1;
	for(int i=1;i<=n;++i)a[i]=qread(),pw[i]=(1ll*pw[i-1]<<1)%mod,mx=max(a[i],mx);
	m=qread();
	for(int i=1;i<=m;++i)b[i]=qread();
	for(int i=1;i<=n;++i)op[i]=m;
	op[0]=0;
	for(int i=1,p=1;i<=n;++i)if(a[i]==b[p])op[i]=p++;
	for(int i=n,x;~i;--i)
	{
		if(op[i]^m)Mod(ans+=t.Q(b[op[i]+1]-1)+1);
		if(i)
		{
			Mod(x=t.Q(mx)+1);
			t.adds(a[i],-c[a[i]]);
			c[a[i]]=x;
			t.adds(a[i],c[a[i]]);
		}
	}
	printf("%d",ans);
	return 0;	
}
