#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
constexpr int N=50005,inf=1e9;
namespace OIfast{
	
	char buf[1<<21],*p1,*p2,*top, buffer[1<<21];
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?0:*p1++)
	#define ri register
template<typename T>
	inline void rd(T& x)
	{
		x=0;
		ri short f=1;
		ri char c=gc();
		while(c<'0' || c>'9'){if(c=='-')f=-1;c=gc();}
		while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc();
		x*=f;
	}
template<typename T,typename ...Args>
	inline void rd(T& x,Args& ...args)
	{
		rd(x),rd(args...);
	}
template<typename T>
	inline void prt(ri T n)
	{
		ri short sta[20];
		ri short top=0;
		if(n<0)n=~n+1,putchar('-');
		do{
			sta[top++]=n%10;
			n/=10;
		}while(n);
		while(top)putchar(sta[--top]^48);
		return ;
	}
template<typename T>
	inline void wr(ri T n,ri char c)
	{	
		prt(n),putchar(c);
		return ;
	}
	#undef gc
	#undef ri
}using namespace OIfast;
int n,k,m;
int a[N];
bitset<35>s;
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	rd(n,k,m);
	for(int i=1;i<=n;i++)rd(a[i]);
	while(m--)
	{
		int opt,x,y;
		rd(opt);
		if(opt==1)
			rd(x,y),a[x]=y;
		else
		{
			int ans=inf;
			for(int i=1;i+k-1<=n;i++)
			{
				s.reset();
				int cnt=0;
				for(int j=i;j<=i+k-1;j++)
					if(!s[a[j]])
						cnt++,s[a[j]]=1;
				if(cnt==k)
				{
					ans=min(ans,k);
					continue;
				}
				for(int j=i+k;j<=n;j++)
				{
					if(!s[a[j]])
						cnt++,s[a[j]]=1;
					if(cnt==k)
					{
						ans=min(ans,j-i+1);
						break;
					}
				}
			}
			wr(ans==inf?-1:ans,'\n');
		}
	}
	return 0;
}
