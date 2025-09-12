#include<bits/stdc++.h>
using namespace std;
int T,n,tot,ans,x,y,mxdeg;
int a[200010],dep[200010],tag[200010],deg[200010];
vector<int> line[200010];
void dfs(int x,int fa,int &rt){
	if(rt==0||dep[x]>dep[rt]) rt=x;
	for(auto v:line[x]){
		if(tag[v]||v==fa) continue;
		dep[v]=dep[x]+1;
		dfs(v,x,rt);
	}
	return;
}
int Getpath(int x,int fa,int y){
	if(x==y) {a[++tot]=x;return 1;}
	for(auto v:line[x]){
		if(tag[v]||v==fa) continue;
		if(Getpath(v,x,y)) {a[++tot]=x;return 1;}
	}
	return 0;
}
int Getdis(int x){
	int p=0,q=0;
	dep[x]=0;dfs(x,0,p);
	dep[p]=0;dfs(p,0,q);
	return dep[q];
}
void solve(int x,int D){
	ans=max(ans,D);
	int p=0,q=0;
	dep[x]=0;dfs(x,0,p);
	dep[p]=0;dfs(p,0,q);
	tot=0;Getpath(p,0,q);
	if(tot&1){
		int y=a[(tot+1)/2];
		tag[y]=1;
		for(auto v:line[y]){
			if(tag[v]) continue;
			solve(v,D+1);
		}
	}
	else{
		int y=a[tot/2],ansy=0;
		int z=a[tot/2+1],ansz=0;
		tag[y]=1;
		for(auto v:line[y]){
			if(tag[v]) continue;
			ansy=max(ansy,Getdis(v));
		}
		tag[y]=0;

		tag[z]=1;
		for(auto v:line[z]){
			if(tag[v]) continue;
			ansz=max(ansz,Getdis(v));
		}
		tag[z]=0;

		if(ansy>ansz) swap(y,z);
		tag[y]=1;
		for(auto v:line[y]){
			if(tag[v]) continue;
			solve(v,D+1);
		}
	}
}
namespace N20{
	int T,fa[20010],f[(1<<20)|5];
	void DFS(int x,int fa){
		N20::fa[x]=fa;
		for(auto v:line[x]){
			if(v==fa) continue;
			DFS(v,x);
		} 
	}
	void Get(int x,int fa,int S){
		if(S>>(x-1)&1){
			T|=(1<<(x-1));
			for(auto v:line[x]){
				if(fa==v) continue;
				Get(v,x,S);
			}
		}
		return;
	}
	void solve(){
		DFS(1,0);
		f[0]=0;
		for(int S=1;S<(1<<n);++S){
			f[S]=n+10;
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(S>>(i-1)&1){
					if(fa[i]==0) ++cnt;
					else if((S>>(fa[i]-1)&1)==0) ++cnt;
				}
			}
			if(cnt>1) continue;
			for(int i=1;i<=n;++i){
				if(S>>(i-1)&1){
					int ans=0;
					for(auto v:line[i]){
						T=0;
						Get(v,i,S);
						ans=max(ans,f[T]);
					}
					f[S]=min(f[S],ans+1);
				}
			}
		}
		cout<<f[(1<<n)-1]<<'\n';
	}
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;

	while(T--){
		cin>>n;
		for(int i=1;i<n;++i){
			cin>>x>>y;
			line[x].push_back(y);
			line[y].push_back(x);
			++deg[x],++deg[y];
			mxdeg=max(mxdeg,deg[x]);
			mxdeg=max(mxdeg,deg[y]);
		}
		if(mxdeg<=2){
			for(int k=1;k<=25;++k){
				if((1<<k)-1>=n){
					cout<<k<<'\n';
					break;
				}
			}
		}
		else if(n<=20) N20::solve();
		else{
			solve(1,1);
			cout<<ans<<'\n';
		}

		ans=mxdeg=0;
		for(int i=1;i<=n;++i){
			line[i].clear();
			tag[i]=deg[i]=0;
		}
	}
	return 0;
}
