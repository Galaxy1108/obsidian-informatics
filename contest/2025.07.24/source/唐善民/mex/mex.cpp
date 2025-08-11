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
constexpr const int N=5000,M=1e9,P=998244353;
int n,m,s[N+1];
namespace judge1{
	int ans,a[N+1];
	bool vis[N+1];
	void dfs(int p){
		if(p>n){
			ans++;
			return;
		}
		int mex=-1;
		for(int i=0;i<=m;i++){
			if(!vis[i]){
				mex=i;
				break;
			}
		}
		if(mex==-1){
			return;
		}
		if(s[p]){
			vis[mex]=true;
			dfs(p+1);
			vis[mex]=false;
		}else{
			for(a[p]=0;a[p]<=m;a[p]++){
				if(a[p]==mex){
					continue;
				}
				vis[a[p]]=true;
				dfs(p+1);
				vis[a[p]]=false; 
			}
		}
	}
	int main(){
		dfs(1);
		cout<<ans<<'\n';
		return 0;
	}
} 
namespace judge2{
	int qpow(int base,int n){
		int ans=1;
		while(n){
			if(n&1){
				ans=1ll*ans*base%P;
			}
			base=1ll*base*base%P;
			n>>=1;
		}
		return ans;
	}
	int main(){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=s[i];
		}
		if(cnt>m){
			cout<<0<<endl;
		}else{
			cout<<qpow(m,n-cnt)<<'\n';
		}
	}
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n<=10){
		judge1::main();
	}else{
		judge2::main();
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
