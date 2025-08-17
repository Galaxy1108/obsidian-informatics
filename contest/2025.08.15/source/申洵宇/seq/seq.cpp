#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define V 100005
#define MOD 998244353ll
int n,m,a[N],b[N];
long long cnt;
vector<int>now;
set<vector<int>>st;
bool cmp(){
	for(int i=1;i<=min(m,(int)now.size());i++){
		if(now[i-1]<b[i])return true;
		else if(now[i-1]>b[i])return false;
	}
	if(now.size()<m)return true;
	return false;
}
void dfs(int x){
	if(cmp())st.emplace(now);
	else return ;
	if(x==n+1)return ;
	now.emplace_back(a[x]);
	dfs(x+1);
	now.pop_back();
	dfs(x+1);
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	dfs(1);
	cout<<st.size();
	return 0;
}
