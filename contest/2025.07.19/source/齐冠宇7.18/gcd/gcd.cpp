#include <bits/stdc++.h>
#define int long long 
#define pb emplace_back
using namespace std;
namespace OIfast{
	
	char buf[1<<21],*p1,*p2,*top, buffer[1<<21];
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?0:*p1++)
	inline int read(){
		register int n=0;
		register short f=1;
		register char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			n=(n<<1)+(n<<3)+(c^48);
			c=getchar();
		}
		return n*(int)f;
	}
	
	inline void prt(register int n){
		register short sta[20];
		register short top=0;
		if(n<0)n=~n+1,putchar('-');
		do{
			sta[top++]=n%10;
			n/=10;
		}while(n);
		while(top)putchar(sta[--top]^48);
		return ;
	}
	
	inline void wr(register int n,register char c){
		prt(n),putchar(c);
		return ;
	}
	#undef getchar
	
}using namespace OIfast;
constexpr int N=1e6+5;
int n;
vector<int>pr;
bitset<N>vis;
int mu[N];
inline void init()
{
	mu[1]=1;
	for(int i=2;i<=N-5;i++)
	{
		if(!vis[i])
			pr.pb(i),mu[i]=-1;
		for(auto v:pr)
		{
			if(v*i>N-5)
				break;
			vis[v*i]=1;
			if(i%v==0)
			{
				mu[i*v]=0;
				break;
			}
			mu[i*v]=-mu[i];
		}
	}
	for(int i=2;i<=N-5;i++)
		mu[i]+=mu[i-1];
}
inline int get(int n,int m,int k)
{
	int res=0,lim=min(n/k,m/k);
	for(int l=1,r;l<=lim;l=r+1)
		r=min(n/(n/l),m/(m/l)),res+=(n/l/k)*(m/l/k)*(mu[r]-mu[l-1]);
	return res;
}
signed main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	init();
	n=read(); 
	while(n--)
	{
		int a=read(),b=read(),c=read(),d=read(),k=read();
		int res1=get(b,d,k)-get(b,c-1,k);
		int res2=get(a-1,d,k)-get(a-1,c-1,k);
		wr(res1-res2,'\n');
	}
	return 0;
}
