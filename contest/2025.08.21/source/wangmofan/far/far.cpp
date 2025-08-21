#include<iostream>

using namespace std;
int n,m,l[86],r[86],mem[10],ans[10];
bool check(int x){
	for(int i=1;i<=9;i++)mem[i]=0;
	int k=m;
	for(int i=m;i>=1;i--)mem[i]=x%2,x/=2;
	for(int i=1;i<=m/2;i++){
		if(mem[i]!=mem[i+(m+1)/2])return 0;
	}
	return 1;
}
void dfs(int s,int now){
	if(check(now))ans[s]++;
	if(s==n+1)return;
	
	for(int i=l[s];i<=r[s];i++){
		dfs(s+1,now^i);
	}
}
int main(){
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> l[i] >> r[i];
	dfs(1,0);
	for(int i=2;i<=n+1;i++)cout << ans[i] << endl;
	return 0; 
} 
