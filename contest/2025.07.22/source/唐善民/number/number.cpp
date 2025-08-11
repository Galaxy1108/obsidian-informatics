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
//#define int long long 
using namespace std;
typedef long long ll;
constexpr const int N=3e5,M=3e5,V=1e9;
int n,m;
ll a[N+1],x[M+1];
ll ans=-1ll*M*V-1;
void dfs(int p){
	if(p>m){
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		ll tmp=a[i];
		a[i]=x[p]-a[i];
		dfs(p+1);
		a[i]=tmp;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>x[i];
		}
		ans=-1ll*M*V-1;
		dfs(1);
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
2 7
10 3 7 1 4 6 3

18
*/
