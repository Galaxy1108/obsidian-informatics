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

int n,s,t,x,y;

void work()
{
	n=read(),s=read(),t=read(),x=read(),y=read();
	// [t-x,t+y-1]
	if(s>t+y-1){
		int o=(s-(t+y-1));
		o=(o+x-1)/x;
		if(n<o){
			cout<<s-n*x<<"\n";
			return;
		}
		n-=o;
		s-=x*o;
	}
	if(s<t-x){
		int o=(t-x)-s;
		o=(o+y-1)/y;
		if(n<o){
			cout<<s+n*y<<'\n';
			return;
		}
		n-=o;
		s+=y*o;
	}
	if(n){
		int r=s-(t-x);
		assert(r>=0&&r<x+y);
		int d=(__int128)y*n%(x+y);
		r=(r+d)%(x+y);
		s=(t-x)+r;
	}
	cout<<s<<"\n";
}

signed main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	int T=read();
	while(T--)work();
	return 0;
}
 