#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int id,step;
};
struct edge{
	int to,from,c;
}e[200086];
vector<edge> d[100086];
priority_queue<int> q;
bool vis[100086];
int n,m,q,c,p,s,t,x,y,flag;
void dfs(int x,int end,int step){
	if(flag)return;
	if(x==end){
		flag=1;
		return;	
	}
	for(edge i:d[x]){
		int to=i.to,c=i.c;
		
	}
}
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	cin >> n >> m >> q; 
	for(int i=1;i<=n-1)cin >> e[i].from >> e[i].to;
	for(int i=1;i<=m;i++)cin >> p >> c,e[p].c=c;
	for(int i=1;i<=n-1;i++){
		int to=e[i].to,from=e[i].from;
		d[from].push_back(e[i]);
		swap(e[i].from,e[i].to);
		d[from].push_back(e[i]);
	}
	for(int i=1;i<=q;i++){
		cin >> s >> t >> x >> y;
		cout << -1 << endl;
	}
	return 0;
}
