#include<bits/stdc++.h>
using namespace std;
int m,s,n;
int a[210];
int cnt;
void dfs(int now,int sum){
	if(sum>s) return;
	if(now>m){
		if(sum!=s) return;
		cnt++;
		return; 
	}
	for(int i=1;i<=n;i++){
		dfs(now+1,sum+a[i]);
	}
}
int main(){
	//freopen("give.in","r",stdin);
	//freopen("give.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>m>>s>>n;
		cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1,0);
		cout<<cnt<<'\n';
	}	
	return 0;
}

