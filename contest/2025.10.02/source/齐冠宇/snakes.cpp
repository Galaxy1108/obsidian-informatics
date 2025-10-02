#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ps emplace
using namespace std;
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
constexpr int N=1e6+5;
int T;
int n,a[N];
set<pii>st;
int vis[N];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	rd(T);
	for(int _=1;_<=T;_++)
	{
		if(_==1)
		{
			rd(n);
			for(int i=1;i<=n;i++)
				rd(a[i]);
		}
		else
		{
			rd(n);
			for(int i=1,x,y;i<=n;i++)
				rd(x,y),a[x]=y;
		}
		st.clear();
		for(int i=1;i<=n;i++)
			st.ps(a[i],i),vis[i]=0;
		while(n>1)
		{
			pii nxt;
			if(vis[st.begin()->se])
			{
				n=vis[st.begin()->se];
				break;
			}
			vis[st.rbegin()->se]=n;
			nxt=mp(st.rbegin()->fi-st.begin()->fi,st.rbegin()->se);
			st.erase(prev(st.end()));
			st.erase(st.begin());
			st.insert(nxt);
			n--;
		}
		if(!(n&1))n-=1;
		wr(n,'\n');
	}
	return 0;
}
