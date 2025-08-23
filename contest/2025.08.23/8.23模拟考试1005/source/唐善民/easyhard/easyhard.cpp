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
constexpr const int N=3000,M=3000;
int n,m,P; 
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
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>P;
	cout<<qpow(2,n+m)<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
