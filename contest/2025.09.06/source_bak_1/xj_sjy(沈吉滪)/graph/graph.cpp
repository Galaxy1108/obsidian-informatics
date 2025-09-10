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

#define maxn 200005
#define inf 0x3f3f3f3f

int n,m;
vi e[maxn];

int cv,ce;
bool vis[maxn];
void dfs(int u){
	if(vis[u])return;
	ce+=e[u].size();vis[u]=1;
	for(int v:e[u])dfs(v);
}

signed main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	int res=0;
	For(i,1,n)
		if(!vis[i]){
			cv=ce=0;
			dfs(i);
			ce/=2;
			res+=ce/2*2;
		}
	cout<<res/2;
	return 0;
}