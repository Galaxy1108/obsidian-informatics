#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=85;
int n;
string a[N];
int b[N];
int vis[N];
int id[N];
void dfs(int x){
	if(x==2*n+1){
		for(int i=1;i<=2*n;i++){
			cout<<a[b[i]]<<"\n";
		}
		exit(0);
	} 
	if(vis[x]){
		dfs(x+1);
		return;
	}
	for(int i=n;i;i--){
		if(!id[i]&&x+i+1<=2*n&&!vis[x+i+1]){
			id[i]=1;
			vis[x+i+1]=1;
			b[x]=i;
			b[x+i+1]=i;
			dfs(x+1); 
			id[i]=0;
			vis[x+i+1]=0; 
		}
	}
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	dfs(1);
	return 0;
}
