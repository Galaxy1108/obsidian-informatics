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
ll solve(ll s,ll k){
	if(k>(s-1>>1)){
		return -1;
	}
	if(s&1){
		return k<<1;
	}else{
		return -1;
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		ll s,k;
		cin>>s>>k;
		cout<<solve(s,k)<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6
3 1
3 2
7 1
7 2
7 3
7 4

2
-1
2
4
6
-1
*/
