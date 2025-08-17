//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;
constexpr const int N=1e6,M=N,P=998244353;
int n,m,a[N+1],b[M+1];
int ans=1;
set<vector<int>>s;
void dfs(int p){
	static bool mode[N+1];
	if(p>n){
		vector<int>c; 
		for(int i=1;i<=n;i++){
			if(mode[i]){
				c.push_back(a[i]);
			}
		}
		if(!c.size()){
			return;
		}
		if(s.count(c)){
			return;
		}
		s.insert(c);
		for(int i=1;i<=min((int)c.size(),m);i++){
			if(b[i]<c[i-1]){
				return;
			}else if(b[i]>c[i-1]){
				ans++;
				return;
			}
		}
		if(c.size()>=m){
			return;
		}
		ans++;
		return;
	}
	mode[p]=0;
	dfs(p+1);
	mode[p]=1;
	dfs(p+1);
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
