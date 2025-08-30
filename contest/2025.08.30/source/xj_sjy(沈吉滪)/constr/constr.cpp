// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
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

#define maxn 4000005
#define inf 0x3f3f3f3f

int n,m;
vi p[maxn],o;

int mx,now;
vi res[maxn];
bool ok(vi a,vi b){
	For(i,0,n-1)if(abs(a[i]-b[i])>1)return 1;
	return 0;
}
void print(vi a){
	For(i,0,9)cout<<a[i]<<" ";
	puts("");
}
void dfs(int u){
	if(now>mx) mx=now;//cout<<now<<"\n";
	mx=max(mx,now);
	if(mx==630) return;
	if(u==m+1)return;
	bool can=1;
	For(i,1,now){
		if(!ok(res[i],p[u])){
			can=0;
			break;
		}
	}
	if(can){
		res[++now]=p[u];
		dfs(u+1);
		if(mx==630)return;
		--now;
	}
	dfs(u+1);
}

int len;
vi q[maxn];
bool chk(){
	For(j,1,len-1)if(!ok(q[j],q[len]))return 0;
	return 1;
}
void wk()
{
	For(i,1,mx){
		For(j,0,n)
			For(k,j,n){
				++len; q[len].clear();
				For(x,0,j-1) q[len].pb(p[i][x]);
				q[len].pb(n+1);
				For(x,j,k-1) q[len].pb(p[i][x]);
				q[len].pb(n+2);
				For(x,k,n-1) q[len].pb(p[i][x]);
				if(!chk())--len;
				if(len%1000==0){
					cout<<len<<"\n";
					For(_,1,len)print(q[_]);exit(0);
				}
			}
	}
	n+=2;For(i,1,len)p[i]=q[i];
	mx=len;
}

signed main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	n=8;
	o.resize(n);
	For(i,0,n-1)o[i]=i+1;
	do p[++m]=o;while(next_permutation(o.begin(),o.end()));
	res[++now]=p[1],mx=1;
	dfs(2);
	m=mx;
	For(i,1,m) p[i]=res[i];
//	For(i,1,m) For(j,i+1,m) assert(ok(p[i],p[j])); exit(0);
	wk();
	cout<<mx<<"\n";
	return 0;
}