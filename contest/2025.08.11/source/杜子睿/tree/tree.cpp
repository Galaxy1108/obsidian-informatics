#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,f[500005],w[500005];
pair<long long,long long> dp[500005];
vector<int> e[500005];
bool check(long long x,long long y){
	return(dp[x].se*y<=dp[x].fi)?true:false;
}
void checko(int x){
	long long t=dp[x].fi/dp[x].se;
	double tt=1.0*(dp[x].fi-dp[x].se*t)/dp[x].se;
	int k=t%10;
	tt+=k;
	cout<<t/10<<tt<<endl;
}
void dfs(int x){
	dp[x]={w[x],1};
	for(int i:e[x]){
		dfs(i);
		if(check(i,w[x])){
			dp[x].fi+=dp[i].fi;
			dp[x].se+=dp[i].se;
		}
	} 
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		f[i]=x;
		e[x].push_back(i);
	} 
	for(int i=1;i<=n;i++)
		cin>>w[i]; 
	dfs(1);
	for(int i=1;i<=n;i++)
		checko(i);
	return 0;
}

