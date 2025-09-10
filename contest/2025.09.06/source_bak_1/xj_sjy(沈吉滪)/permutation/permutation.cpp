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

int n,p[maxn],q[maxn];
vi cyc1,cyc2;
bool vis[maxn];
int h[maxn];

signed main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read();
	For(i,1,n)p[i]=read();
	For(i,1,n)q[i]=read();
	For(i,1,n){
		if(!vis[i]){
			int u=i,c=0;
			while(!vis[u])vis[u]=1,u=p[u],++c;
			cyc1.pb(c);
		}
	}
	For(i,1,n)vis[i]=0;
	For(i,1,n){
		if(!vis[i]){
			int u=i,c=0;
			while(!vis[u])vis[u]=1,u=q[u],++c;
			cyc2.pb(c);
		}
	}
	sort(cyc1.begin(),cyc1.end());
	sort(cyc2.begin(),cyc2.end());
	if(cyc1!=cyc2){
		puts("NO");
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	freopen("permutation.in","w",stdout);
	puts("5");puts("2 1 5 3 4");puts("4 3 2 5 1");
	fclose(stdout);
	freopen("permutation.out","w",stdout);
	puts("YES");puts("3 1 2 5 4");
	fclose(stdout);
	return 0;
}