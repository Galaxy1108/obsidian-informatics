#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int dp[510][510],val[510][510],size[510],a[510];
int n,u,v,k;
vector<int> tree[510];
int gcd(int a,int b){
	if(a==0){
		return b;
	}
	else return gcd(b%a,a); 
}
void dfs(int x,int f){
//	cout << x << endl;
	size[x]=1;
	for(int i:tree[x]){
		if(i==f)continue;
		dfs(i,x);
		size[x]+=size[i];
	}
	val[x][size[x]]=a[x];
	for(int i:tree[x]){
		if(i==f)continue;
		val[x][1]+=val[i][1];
	}
}
void solve(int x,int f){
	dp[x][1]=val[x][1];
	for(int i:tree[x]){
		if(i==f)continue;
		solve(i,x);
//		dp[x][size[x]]+=dp[i][size[i]];
	}
	for(int i:tree[x]){
		if(i==f)continue;
		if(x==9){
			cout << '!';		
		}
		for(int j=1;j<=size[x];j++){
			for(int k=1;k<=j;k++){
				if(x==4){
					cout << j << ' ' << k << ' ' << i <<' '<<dp[x][j+k] << ' ' << dp[i][k] << ' '<<val[x][j+k]<<' '<< val[i][k] << endl;
				}
				if(dp[x][j]<dp[x][j-k]+dp[i][k]){
					dp[x][j]=dp[x][j-k]+dp[i][k]-val[x][j-k]-val[i][k]+gcd(val[x][j-k],val[i][k]);
					val[x][j]=gcd(val[x][j-k],val[i][k]);
				}
			}
		}
	}
}
int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0);
	memset(dp,-0x3f,sizeof dp);
	solve(1,0);
	for(int i=1;i<=n;i++){
		cout << i << "  " ;
		for(int j=1;j<=n;j++){
			if(dp[i][j]<-1e8)cout << 0 << ' ';
			else cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
} 
/*
10 4 
2 1 
3 1 
4 2 
5 2 
6 1 
7 3 
8 5 
9 4 
10 9 
8 9 4 6 6 9 6 9 8 6  
*/
