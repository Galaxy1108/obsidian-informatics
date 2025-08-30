#include <bits/stdc++.h>
using namespace std;
#define N 505
int n,k,a[N],ts[N];
long long siz[N];
vector<int>e[N];
map<int,int>f[N][N],nf[N];
void getmax(map<int,int>& mp,int to,int val){
	if(!mp.count(to))mp[to]=val;
	else mp[to]=max(mp[to],val);
}
void dfs(int x,int come){
	ts[x]=1;
	for(auto v:e[x]){
		if(v==come)continue;
		dfs(v,x);
		ts[x]+=ts[v];
	}
	ts[x]=min(ts[x],k+1);
	sort(e[x].begin(),e[x].end(),[&](int x,int y)->bool{return siz[x]>siz[y];});
	f[x][0][a[x]]=0;
	for(auto v:e[x]){
		if(v==come)continue;
		for(int i=0;i<ts[x];i++)nf[i].clear();
		for(int i=0;i<ts[x];i++){
			for(int j=0;j<ts[v];j++){
				//delete v-x
				if(j<i){
					for(auto el:f[x][i-j-1]){
						for(auto em:f[v][j]){
							getmax(nf[i],el.first,el.second+em.first+em.second);
						}
					}
				}
				//not delete
				for(auto el:f[x][i-j]){
					for(auto em:f[v][j]){
						getmax(nf[i],__gcd(el.first,em.first),el.second+em.second);
					}
				}
			}
		}
		for(int i=0;i<ts[x];i++)f[x][i]=nf[i];
	}
	for(int i=0;i<ts[x];i++)siz[x]+=f[x][i].size();
	// cerr<<"NODE "<<x<<":\n";
	// for(int i=0;i<=k;i++){
	// 	cerr<<i<<":";
	// 	for(auto v:f[x][i]){
	// 		cerr<<"("<<v.first<<","<<v.second<<") ";
	// 	}
	// 	cerr<<'\n';
	// }
}
int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int _u,_v;
	for(int i=1;i<n;i++){
		cin>>_u>>_v;
		e[_u].emplace_back(_v);
		e[_v].emplace_back(_u);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	int ans=0;
	for(auto el:f[1][k]){
		ans=max(ans,el.first+el.second);
	}
	cout<<ans;
	/*test code
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			cnt+=f[i][j].size();
		}
	}
	cerr<<cnt;
	*/
	return 0;
}