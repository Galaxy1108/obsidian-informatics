#include<iostream>
#include<vector>
using namespace std;
int n,x,y,v,t,l,m,st[2086],ans=2e9,cnt,vis[2086];
struct edge{
	int to,val;
};
vector<edge> f[2086];
void dfs(int x,int fa,int w,int step){
	vis[x]++;
	if(cnt>=5e6)return;
	if(step==l){
		ans=min(ans,w);
		return;
	}
	for(edge i:f[x]){
		int to=i.to,v=i.val;
//		cout << step<< ' '<<x<<' ' <<to <<' '<<st[step+1]<< endl;
		if(to==fa)continue;
		if(to==st[step+1])dfs(to,x,w+v,step+1);
		else dfs(to,x,w+v,step);
	}
}
int main(){
	cin >> n >> m >> t >> l;
	for(int i=1;i<=m;i++){
		cin >> x >> y >> v;
		f[x].push_back(edge{y,v});
		f[y].push_back(edge{x,v});
	}
	for(int i=1;i<=l;i++)cin >> st[i];
	cin >> x >> y;
	st[x]=y;
	dfs(st[1],0,0,1);
	if(ans==2e9)cout << -1;
	else cout << ans;
	return 0;
}
