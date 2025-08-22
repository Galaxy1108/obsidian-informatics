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
#include<random>
using namespace std;
constexpr const int N=5000;
int n,a[N+1][N+1];
namespace gen{
	int seed;
	void gen(int n,int seed){
	    std::mt19937 rng(seed);
	    for(int i=1;i<=n;++i){
	        for(int j=1;j<=n+1;++j){
	            a[i][j]=j;
	            std::swap(a[i][j],a[i][rng()%j+1]);
	        }
	    }
	}
}
bool mode[N+1+1];
void dfs(int p,int &id,int &ans){
	if(p>n){
		dfs(1,id,ans);
		return;
	}
	if(p==id){
		for(int i=1;i<=n+1;i++){
			if(mode[i]){
				if(a[id][i]>a[id][ans]){
					ans=i;
				}
				return;
			}
		}
	}
	for(int i=1;i<=n+1;i++){
		if(mode[i]){
			mode[i]=false;
			dfs(p+1,id,ans);
			mode[i]=true;
		}
	} 
}
int query(int id){
//	cerr<<"------------------------------------\n";
//	cerr<<"query("<<id<<"):\n";
	memset(mode,1,sizeof(mode));
	int ans=0;
	for(int i=1;i<=n+1;i++){
		mode[i]=false;
		dfs(id+1,id,ans);
		mode[i]=true;
	}
	return ans;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>gen::seed;
	switch(gen::seed){
		case 0:
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n+1;j++){
					cin>>a[i][j];
				}
			}
			break;
		default:
			gen::gen(n,gen::seed);
	}
	for(int i=1;i<=n;i++){
		cout<<query(i)<<' ';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
