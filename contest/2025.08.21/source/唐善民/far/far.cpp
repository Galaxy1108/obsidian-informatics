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
typedef long long ll;
constexpr const int N=40,M=60,P=998244353;
int n,m,k,ans;
ll l[N+1],r[N+1],a[N+1];
bool check(){
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans^=a[i];
	}
	string a="",b="";
	for(int i=1;i<=m;i++){
		a+='0'+(ans&1);
		ans>>=1;
	}
	b=a;
	reverse(a.begin(),a.end());
	return a==b;
}
void dfs(int p){
	if(p>k){
		ans+=check();
		if(ans>=P){
			ans-=P;
		}
		return;
	}
	for(a[p]=l[p];a[p]<=r[p];a[p]++){
		dfs(p+1);
	}
}
int main(){
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	for(k=1;k<=n;k++){
		ans=0;
		dfs(1);
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
