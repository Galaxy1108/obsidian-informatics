#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mpr make_pair
const int N=2005,M=1e5+5,inf=1e18;

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())c=getchar();
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int ex[N],ey[N],ew[N],n,m,T,L,a[M],f[2][N];
vector<int> h[N];

int dis[N][2][N];
bool vis[N];

void dij(int di,int dj,int xx){
	memset(vis,0,sizeof(vis));
	dis[di][dj][xx]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(mpr(0,xx));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:h[u]){
			if(i==di)continue;
			int v=u==ex[i]?ey[i]:ex[i];
			if(dis[di][dj][v]>dis[di][dj][u]+ew[i]){
				dis[di][dj][v]=dis[di][dj][u]+ew[i];
				q.push(mpr(dis[di][dj][v],v));
			}
		}
	}
}

signed main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	n=read();m=read();T=read();L=read();
	for(int i=1;i<=m;++i){
		ex[i]=read();ey[i]=read();ew[i]=read();
		h[ex[i]].push_back(i);h[ey[i]].push_back(i);
	}
	for(int i=1;i<=L;++i)a[i]=read();
	memset(dis,0x3F,sizeof(dis));
	for(int i=1;i<=m;++i){
		dij(i,0,ex[i]);
		dij(i,1,ey[i]);
	}
	while(T--){
		int p=read(),pp=read();a[p]=pp;
		for(int i=0;i<h[a[2]].size();++i){
			int v=ex[h[a[2]][i]]==a[2]?ey[h[a[2]][i]]:ex[h[a[2]][i]];
			if(v==a[1])f[0][i]=ew[h[a[2]][i]];
			else f[0][i]=dis[h[a[2]][i]][ex[h[a[2]][i]]==a[2]][a[1]]+ew[h[a[2]][i]];
			//cout<<" i:"<<i<<" v:"<<v<<" f:"<<f[0][i]<<endl;
		}
		for(int i=3;i<=L;++i){
			int x=a[i],y=a[i-1];
			for(int j=0;j<h[x].size();++j)f[i&1][j]=inf;
			for(int j=0;j<h[y].size();++j){
				for(int k=0;k<h[x].size();++k){
					if(h[y][j]==h[x][k])continue;
					int dd=inf;
					int v=ex[h[x][k]]==x?ey[h[x][k]]:ex[h[x][k]];
					if(v==y)f[i&1][k]=min(f[i&1][k],f[i&1^1][j]+ew[h[x][k]]);
					for(int z=1;z<=n;++z){
						if(z==x||z==y)continue;
						dd=min(dd,dis[h[y][j]][ey[h[y][j]]==y][z]+dis[h[x][k]][ey[h[x][k]]==x][z]);
					}
					f[i&1][k]=min(f[i&1][k],f[i&1^1][j]+dd);
				}
			}
		}
		int ans=inf;
		for(int i=0;i<h[a[L]].size();++i){
			ans=min(ans,f[L&1][i]);
		}
		if(ans>=inf)puts("-1");
		else print(ans);putchar('\n');
	}
	return 0;
}





























