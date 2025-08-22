#include<iostream>
#include<cstdio>
using namespace std;
long long ans,n,m,p,t;
void dfs(int s,int l,int r){
	if(s==n){
		ans++;
		ans%=p;
		return;
	}
	for(int i=1;i<=r;i++){
		for(int j=max(l,i);j<=m;j++){
			dfs(s+1,i,j);
		}
	}
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
	cin >> n >> m >> p;
	if(n==1){
		cout << m*(m+1)/2;
		return 0;
	}
	if(m==1){
		cout << 1;
		return 0;
	}
	dfs(0,1,m);
	cout << ans%p;
	return 0;
} 
