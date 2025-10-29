#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y); 
} 
int ans[N][N];
bool g[N][N];
int depth = 0;
int r[N][N];
#define fi first
#define se second
queue<pair<int,int>>q;
vector<int>e[N];
pair<int,int> add(int x,int y,int q,int p){
	int up = x*p+y*q;
	int down = y*p;
	int tmp = gcd(up,down);
	up/=tmp;
	down/=tmp;
	return make_pair(up,down); 
}
int a,b;
void bfs(){
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		if(ans[u.fi][u.se]!=0)continue;
		for(auto v:e[u.se]){
			auto w = add(1,v,u.fi,u.se);
			if(w.fi>1000)continue;
			if(ans[w.fi][w.se]!=0)continue;
			ans[w.fi][w.se] = ans[u.fi][u.se]+1;
			q.push(w); 
		}
	}
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout); 
	cin>>a>>b;
	for(int i = 1;i<=1000;i++){
		for(int j = 1;j<=1000;j++){
			int k = i*j/gcd(i,j);
			if(k<=1000){
				g[i][j] = 1;
				r[i][j] = k;
				e[i].push_back(j);
			}
		}
	}
	//for(auto v:e[2])cout<<v<<" ";
	for(int i = 1;i<=1000;i++){
		ans[1][i] = 1;
		q.push({1,i});
	} 
	if(ans[a][b]){
		cout<<ans[a][b];
		return 0;
	}
	bfs(); 
	cout<<ans[a][b];
	return 0;
} 
