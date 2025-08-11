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
#define int long long
using namespace std;
constexpr const int N=1e5,P=1e9+7,inv2=500000004;
int n,h[N+1],w[N+1];
int f(int x){
	return 1ll*x*(x+1)%P*inv2%P;
}
main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int ans=0;
	vector<int>s{0};
	for(int i=1;i<=n+1;i++){
		int pl=0;
		while(h[s.back()]>h[i]){
			int x=s.back();
			s.pop_back();
			pl=(1ll*pl+w[x])%P;
			ans=(1ll*ans + (1ll*f(h[x]) - f(max(h[i],h[s.back()])))%P*f(pl)%P)%P;
		}
		w[i]=(1ll*w[i]+pl)%P;
		s.push_back(i);
	}
	if(ans<0){
		ans+=P;
	}
	cout<<ans<<'\n';
	
	cout.flush(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
