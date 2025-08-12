#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,m,Q,u,v,x,y,t;
long long S,w,c,st,lim,ans;
long long dis[110],Dis[110][110],E[110][110],Day[110][110],T[110][110];
int tag[110];
vector<pair<long long,long long> > D[110][110];
struct Line{
	int v;
	long long w,c;
};
vector<Line> line[110];
int main()
{
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>S>>Q;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w>>c;
		++u,++v;
		line[u].push_back((Line){v,w,c}); 
		line[v].push_back((Line){u,w,c}); 
	} 
	for(int k=1;k<=n;++k){
		cerr<<k<<' ';
		st=0,lim=inf;
		while(1){
			if(st>=S) break;
			for(int i=0;i<=n;++i) dis[i]=inf;
			for(int i=0;i<=n;++i) tag[i]=0;
			dis[k]=0;
			for(int t=1;t<=n;++t){
				int p=0;
				for(int i=1;i<=n;++i) if(tag[i]==0&&dis[i]<=dis[p]) p=i;
				tag[p]=1;
				for(auto l:line[p]){
					if(dis[l.v]<=dis[p]+l.w) continue;
					if(dis[p]+st+l.w>l.c) continue;
					dis[l.v]=dis[p]+l.w;
					lim=min(lim,l.c-l.w-dis[p]);
				}
			}
			if(st==0){
				for(int i=1;i<=n;++i){
					E[k][i]=dis[i];
					if(dis[i]<inf) Day[k][i]=1;
					else Day[k][i]=inf;
					if(i==k) Day[k][i]=0;
				}
			}
			for(int i=1;i<=n;++i){
				while(!D[k][i].empty()&&D[k][i].back().first>dis[i]) D[k][i].pop_back();
				while(!D[k][i].empty()&&D[k][i].back().first==dis[i]) D[k][i].pop_back();
				D[k][i].push_back(make_pair(dis[i],lim));
			}
			st=lim+1,lim=inf;
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			T[k][i]=-1;
			if(i==k){
				T[k][i]=inf;
				continue;
			}
			for(auto v:D[k][i]){
				if(v.first<inf) T[k][i]=v.second;
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				Day[i][j]=min(Day[i][j],Day[i][k]+Day[k][j]);
			}
		} 
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			Dis[i][j]=inf;
			if(E[i][j]<inf) Dis[i][j]=E[i][j];
			else{
				for(int k=1;k<=n;++k){
					Dis[i][j]=min(Dis[i][j],Day[i][k]*S+E[k][j]);
				}
			}
		}
	} 
	for(int i=1;i<=Q;++i){
		ans=inf;
		cin>>x>>y>>t;
		++x,++y;
		if(t<=D[x][y].back().second){
			int l=0,r=D[x][y].size()-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(t<=D[x][y][mid].second) r=mid;
				else l=mid+1;
			}
			ans=D[x][y][l].first;
		}
		for(int k=1;k<=n;++k){
			if(t<=T[x][k]) ans=min(ans,S-t+Dis[k][y]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
