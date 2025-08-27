#include<iostream>

using namespace std;
int t,n,s,m,a[10086],ans;
void dfs(int deep,int sum){
	if(deep==m+1){
		if(sum==s)ans++;
		return;
	} 
	for(int i=1;i<=n;i++){
		dfs(deep+1,sum+a[i]);
	}
}
int main(){
	cin >> t;
	while(t--){
		ans=0;
		cin >> m >> s >> n;
		for(int i=1;i<=n;i++)cin >> a[i];
		dfs(1,0);
		cout << ans%2;
	}
	return 0;
}
