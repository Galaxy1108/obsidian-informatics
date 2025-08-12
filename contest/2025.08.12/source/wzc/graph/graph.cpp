#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[1000001],head[1000001],x[200001],y[200001],ans[200001],t,tot,cnt;
struct dcz{
	int nex,to;
}a[4000001];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
bool check(int mid,int i){
	int fx=gf(x[i]+(mid-1)*n),fy=gf(y[i]+(mid-1)*n);
	return fx!=fy;
}
void merge(int x,int y){
	int fx=gf(x),fy=gf(y);
	if(fx!=fy) fa[fy]=fx;
}
void add(int x,int y){
	a[++cnt].nex=head[x];
	a[cnt].to=y;
	head[x]=cnt;
}
bool dfs(int u,int fa,int ed){
	if(u==ed){ans[++tot]=u;return 1;}
	bool ff=0;
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].to;
		if(v==fa) continue;
		ff|=dfs(v,u,ed);
	}
	if(ff) ans[++tot]=u;
	return ff;
}
signed main(){
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
//		memset(fa,0,sizeof fa);
		cnt=0;
		cin>>n>>m;k=(m+n-2)/(n-1);
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=k*n;i++){
			fa[i]=i;head[i]=0;
		}
		int u=0,v=0;
		for(int i=1;i<=m;i++){
			int l=1,r=k,ans=0;
			while(l<=r){
				cout<<'-'<<l<<' '<<r<<endl;
				int mid=l+r>>1;
				if(check(mid,i)) ans=mid,r=mid-1;
				else l=mid+1;
			}
//			cout<<t<<" "<<ans<<" "<<x[i]<<" "<<y[i]<<' '<<gf(x[i])<<" "<<gf(y[i])<<"\n";
			merge(x[i]+(ans-1)*n,y[i]+(ans-1)*n);
			add(x[i]+(ans-1)*n,y[i]+(ans-1)*n);
			add(y[i]+(ans-1)*n,x[i]+(ans-1)*n);
			if(ans==k){
				u=x[i],v=y[i];
				break;
			}
		}
		if(!u){cout<<-1<<"\n";continue;}
		cout<<u<<' '<<v<<"\n";
		for(int i=1;i<=k;i++){
			tot=0;
			dfs(u+(i-1)*n,0,v+(i-1)*n);
			cout<<tot<<' ';
			for(int j=tot;j>=1;j--) cout<<ans[j]-(i-1)*n<<' ';
			cout<<"\n";
		}
	}
	return 0;
} 
