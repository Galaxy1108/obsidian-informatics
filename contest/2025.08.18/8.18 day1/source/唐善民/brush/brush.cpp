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
using namespace std;
constexpr const int N=10000,M=100;
int n,m,a[N+1];
int ans=2147483647;
void dfs(int p,int step,int cnt){
	static bool mode[N+1];
	if(step>=ans){
		return;
	}
	if(p>n){
		if(cnt<2){
			return;
		}
		ans=step;
		return;
	}
	if(p>m){
		cnt-=mode[p-m];
		if(cnt>=2){
			mode[p]=false;
			dfs(p+1,step,cnt);
		}
		mode[p]=true;
		dfs(p+1,step+a[p],cnt+1);
	}else{
		mode[p]=false;
		dfs(p+1,step,cnt);
		mode[p]=true;
		dfs(p+1,step+a[p],cnt+1);
	}
}
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
8 3
6 7 10 1 7 8 5 6

30
*/
