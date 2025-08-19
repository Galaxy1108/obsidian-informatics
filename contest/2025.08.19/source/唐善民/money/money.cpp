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
constexpr const int N=2000;
int n,cost;
double w[N+1],c[N+1],d[N+1];
double ans;
void dfs(int p){
	if(clock()>=0.95*CLOCKS_PER_SEC){
		cout<<ans<<endl;
		exit(0);
	}
	static int mode[N+1];
	if(p>n){
		double dollar=0,cny=0;
		for(int i=1;i<=n;i++){
			cny+=w[i];
			switch(mode[i]){
				case 0:
					dollar+=cny*c[i];
					cny=0;
					break;
				case 1:
					cny+=dollar*d[i]-cost;
					dollar=0;
					break;
			}
		}
		ans=max(ans,cny);
		return;
	}
	mode[p]=0;
	dfs(p+1);
	mode[p]=1;
	dfs(p+1);
	mode[p]=2;
	dfs(p+1);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>cost;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>c[i]>>d[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 1
10 0.1 9
10 0.01 20
10 0.1 9
*/
