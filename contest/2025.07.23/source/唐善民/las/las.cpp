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
constexpr const int N=1e6;
int n,c[N+1];
namespace judge1{
	bool is(){
		if(n<=20){
			return true;
		}
		return false;
	}
	bool mode[N+1];
	bool check(){
		static int get[N+1];
		mode[0]=mode[n];
		mode[n+1]=mode[1];
		c[n+1]=c[1];
		for(int i=1;i<=n;i++){
			//i-1Ñ¡ÓÒ±ß,iÑ¡×ó±ß 
			if(mode[i]){
				if(!mode[i+1]){
					get[i]=(c[i+1]>>1);
				}else{
					get[i]=c[i+1];
				}
			}else{
				if(mode[i-1]){
					get[i]=(c[i]>>1);
				}else{
					get[i]=c[i];
				}
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			int pl=0;
			if(!mode[i]){
				if(!mode[i+1]){
					pl=(c[i+1]>>1);
				}else{
					pl=c[i+1];
				}
			}else{
				if(mode[i-1]){
					pl=(c[i]>>1);
				}else{
					pl=c[i];
				}
			}
			if(get[i]<pl){
				flag=false;
				break;
			}
		}
		return flag;
	}
	void dfs(int p){
		if(clock()>=1.95*CLOCKS_PER_SEC){
			cout<<"NIE"<<endl;
			exit(0);
		}
		if(p>n){
			if(check()){
				for(int i=1;i<=n;i++){
					int ans=i+mode[i];
					if(ans==n+1){
						ans=1;
					}
					cout<<ans<<' ';
				}
				cout<<endl; 
				exit(0);
			}
			return;
		}
		mode[p]=0;
		dfs(p+1);
		mode[p]=1;
		dfs(p+1);
	}
	int main(){
		dfs(1); 
		cout<<"NIE\n";
		return 0;
	} 
}
namespace judge2{
	int dp[N+1][4];
	void move(int a,int b){
		if(dp[a][2]!=-1&&c[a]>=c[b]){
			dp[b][0]=2;
		}else if(dp[a][3]!=-1&&c[a]>=2ll*c[b]){
			dp[b][0]=3;
		}
		if(dp[a][0]!=-1&&c[b]>=c[a]){
			dp[b][1]=0;
		}else if(dp[a][1]!=-1&&2ll*c[b]>=c[a]){
			dp[b][1]=1;
		}
		
		if(dp[a][2]!=-1&&2ll*c[a]>=c[b]){
			dp[b][2]=2;
		}else if(dp[a][3]!=-1&&c[a]>=c[b]){
			dp[b][2]=3;
		}
		if(dp[a][0]!=-1&&c[b]>=2ll*c[a]){
			dp[b][3]=0;
		}else if(dp[a][1]!=-1&&c[b]>=c[a]){
			dp[b][3]=1;
		}
	}
	bool solve(int x){
		memset(dp,-1,sizeof(dp));
		dp[1][x]=4;
		for(int i=2;i<=n;i++){
			move(i-1,i);
		}
		move(n,1);
		return dp[1][x]!=4;
	}
	void print(int x){
		x=dp[1][x];
		static int ans[N+1];
		for(int i=n;i>=1;i--){
			if(x==2||x==3){
				ans[i]=i;
			}
			if(x==1||x==3){
				int p=i-1;
				if(!p){
					p=n;
				}
				ans[p]=i;
			}
			x=dp[i][x]; 
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
	int main(){
		if(solve(0)){
			print(0);
		}else if(solve(1)){
			print(1);
		}else if(solve(2)){
			print(2);
		}else if(solve(3)){
			print(3);
		}else{
			cout<<"NIE\n";
		}
		return 0;
	}
}
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		c[i]<<=1;
	}
	if(judge1::is()){
		judge1::main();
	}else{
		judge2::main();
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
