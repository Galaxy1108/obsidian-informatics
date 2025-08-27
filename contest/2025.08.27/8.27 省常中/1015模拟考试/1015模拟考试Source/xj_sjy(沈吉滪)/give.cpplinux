// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
#define inf 0x3f3f3f3f

int n,s,k,a[666];
bitset<200005>f,g;
void work()
{
	n=read(),s=read(),k=read();
	For(i,1,k)a[i]=read();
	f.reset(),f.set(0);
	For(i,0,59){
		if(n>>i&1){
			g.reset();
			For(j,1,k)g^=(f<<a[j]);
			f=g;
		}
		For(j,0,100000) f[j]=f[(j<<1)|(s>>i&1)];
		For(j,100001,200004) f.reset(j);
	}
	int res=f.test(0);
	cout<<res<<"\n";
}

signed main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	int T=read();
	while(T--)work();
	return 0;
}
 