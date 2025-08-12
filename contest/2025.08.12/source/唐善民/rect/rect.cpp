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
constexpr const int N=500,M=500;
int n,m;
bool a[N+1][M+1];
struct ans{
	int k,a[N+1][M+1];
	ans(){
		k=0;
		memset(a,0,sizeof(a));
	}
	int* operator [](int x){
		return a[x];
	}
}Min;
void dfs(int i,int j,ans &s){
	if(Min.k&&s.k>Min.k){
		return;
	}
	if(j>m){
		dfs(i+1,1,s);
		return;
	}
	if(i>n){
		Min=s;
		return;
	}
	if(!a[i][j]){
		dfs(i,j+1,s);
		return;
	}
	if(s[i][j]){
		dfs(i,j+1,s);
		return;
	}
//	if(s[i][j-1]){
//		s[i][j]=s[i][j-1];
//		dfs(i,j+1,s);
//	}
//	if(s[i-1][j]){
//		s[i][j]=s[i-1][j];
//		dfs(i,j+1,s);
//	}
	s.k++;
	s[i][j]=s.k;
	dfs(i,j+1,s);
	s[i][j]=0;
	s.k--;
}
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			a[i][j]=(ch=='C');
		}
	}
	ans pl;
	dfs(1,1,pl);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<Min[i][j]<<' ';
		}
		cout<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
