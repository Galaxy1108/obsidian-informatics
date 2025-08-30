#include <bits/stdc++.h>
using namespace std;
#define mycnt 50521
int n,cnt,a[15];
bool book[15];
void dfs(int x){
	if(x==n+1){
		cnt++;
		for(int i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
		return ;
	}
	int l=-1;
	for(int i=1;i<=n;i++){
		if(book[i])continue;
		if(i-l>=2){
			a[x]=i;
			book[i]=1;
			dfs(x+1);
			book[i]=0;
			l=i;
		}
	}
}
int main(){
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cout<<mycnt<<'\n';
	dfs(1);
	assert(mycnt==cnt);
	// cerr<<cnt;
	return 0;
}