// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
//#define int long long
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

#define maxn 505
#define inf 0x3f3f3f3f

bool mbe;
int n,k,a[maxn];
vi e[maxn];
int sz[maxn];

int f[505][505][243],val[505][243],cnt[505],id[1000005],tmp[505][243],gc[243][243];
int fc[505],cf[505],tot;
void fact(int x){
	tot=0;
	For(i,2,x)
		if(x%i==0){
			fc[++tot]=i,cf[tot]=0;
			while(x%i==0)x/=i,++cf[tot];
		}
	if(x>1) fc[++tot]=x,cf[tot]=1;
}
void get(int x,int now,int u){
//	cout<<"get "<<x<<" "<<now<<" "<<u<<"\n";
	if(x==tot+1){
		++cnt[u];
		val[u][cnt[u]]=now;
		return;
	}
	get(x+1,now,u);
	For(i,1,cf[x])
		now*=fc[x],get(x+1,now,u);
}
void dfs(int u,int pa){
	sz[u]=0;
	for(int v:e[u])if(v!=pa)dfs(v,u);
	fact(a[u]);
	get(1,1,u);
	For(i,1,cnt[u]) id[val[u][i]]=i;
	
	f[u][0][id[a[u]]]=0;
	for(int v:e[u])
		if(v!=pa){
			For(i,0,sz[u])For(j,1,cnt[u])
				if(f[u][i][j]>=0){
					For(jj,1,cnt[v]) gc[j][jj]=id[__gcd(val[u][j],val[v][jj])];
					For(x,0,sz[v])For(y,1,cnt[v])if(f[v][x][y]>=0){
						tmp[i+x][gc[j][y]]=max(tmp[i+x][gc[j][y]],f[u][i][j]+f[v][x][y]);
						tmp[i+x+1][j]=max(tmp[i+x+1][j],f[u][i][j]+f[v][x][y]+val[v][y]);
					}
				}
			sz[u]+=sz[v]+1;
			For(i,0,sz[u])For(j,1,cnt[u])f[u][i][j]=tmp[i][j],tmp[i][j]=-1;
		//	if(u==1)cout<<"DP: "<<f[u][id[a[u]]][k]<<"\n";
		}
//	For(i,0,min(sz[u],k))For(j,1,cnt[u])if(f[u][i][j]>=0)cout<<"u: "<<u<<" "<<i<<" "<<val[u][j]<<" "<<f[u][i][j]<<"\n";puts("---------");
}

bool med;

signed main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
//	fprintf(stderr,"%.5lf\n",(&mbe-&med)/1024576.0);
	n=read(),k=read();
	memset(f,-1,sizeof f);
	memset(tmp,-1,sizeof tmp);
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	For(i,1,n)a[i]=read();
	dfs(1,0);
//	For(i,1,n){
//		For(j,1,cnt[i])cout<<val[i][j]<<" ";
//		puts("");
//	}
	int res=0;
	For(i,1,cnt[1]) if(f[1][k][i]>=0) res=max(res,f[1][k][i]+val[1][i]);
	cout<<res;
	return 0;
}
