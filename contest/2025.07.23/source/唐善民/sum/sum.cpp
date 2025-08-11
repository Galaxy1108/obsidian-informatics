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
constexpr const int N=100,M=100,K=100;
int n,m,k,P;
int ans,a[N+1][M+1];
int f(int x,int y){
	int Min=2147483647;
	for(int i=1;i<=m;i++){
		Min=min(Min,a[x][i]);
	}
	for(int i=1;i<=n;i++){
		Min=min(Min,a[i][y]);
	}
	return Min;
}
void make(int i,int j){
	if(j>m){
		make(i+1,1);
		return;
	}
	if(i>n){
		int pl=1;
		for(int x=1;x<=n;x++){
			for(int y=1;y<=m;y++){
				pl=1ll*pl*f(x,y)%P;
			}
		}
		ans=(ans+pl)%P;
		return;
	}
	for(a[i][j]=1;a[i][j]<=k;a[i][j]++){
		make(i,j+1);
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k>>P;
	make(1,1);
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
