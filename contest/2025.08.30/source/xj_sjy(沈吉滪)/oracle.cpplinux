#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
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

int fa[maxn];
int gf(int x){
	while(x^fa[x])x=fa[x]=fa[fa[x]];
	return x;
}

int n,m,cnt,mxs,res;
pii e[maxn];

bool vis[maxn];
bool solve(int sta){
	For(i,1,n)vis[i]=0;
	For(i,1,cnt)
		if(sta>>(i-1)&1){
			vis[e[i].fi+1]=1;
			if(e[i].se==n)vis[1]=1;
			else vis[e[i].se+1]=1;
		}
	For(i,1,n)if(!vis[i])return 0;
	return 1;
}


bool brute(int sta){
	set<int>s;
	For(i,1,n){
		int k=0,S=0;
		For(j,1,cnt)
			if(sta>>(j-1)&1){
				int o=(e[j].fi<i&&i<=e[j].se);
				if(o)S|=(1<<k); ++k;
			}
		if(s.count(S))return 0;
		s.insert(S);
	//	cout<<i<<" "<<S<<"\n";
	}
	++res;
	return 1;
}

signed main()
{
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	n=read(),m=read();
	For(i,0,n)
		For(j,i+1,n)
			e[++cnt]=mkp(i,j);
//	cout<<cnt<<endl;
//	brute(9557),exit(0);
	For(i,0,(1<<cnt)-1)
		if(__builtin_popcount(i)==m)brute(i);
	cout<<res;
	return 0;
}