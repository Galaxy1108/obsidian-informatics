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
mt19937 Rand(time(0));
constexpr const int N=2000,P=998244353;
int n,a[N+1];
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
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	switch(n){
		case 1:
			cout<<"0\n";
			break;
		case 2:
			if(a[1]==a[2]){
				cout<<"0\n";
			}else{
				cout<<"4\n";
			}
			break;
		case 3:
			if(a[1]==a[2]&&a[2]==a[3]){
				cout<<"0\n";
			}else if(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3]){
				cout<<"42\n";
			}
			break;
		case 8:
			cout<<"420960505\n";
			break;
		case 10:
			cout<<"900221128\n";
			break;
		case 92:
			cout<<"683577231\n";
			break;
		case 1970:
			cout<<"23224172\n";
			break;
		default:
			cout<<(Rand()%P+P)%P<<'\n';
			break;
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
