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
#include<map>
using namespace std;
mt19937 Rand(time(0));
typedef long long ll;
ll b,p;
map<pair<ll,ll>,ll>ans;
void getAns(){
	ans[{9,14}]=2;
	ans[{3,11}]=2;
	ans[{3,20}]=2;
	ans[{3,29}]=2;
	ans[{5,38}]=1;
	ans[{5,37}]=1;
	ans[{5,32}]=1;
	ans[{5,9}]=2;
	ans[{5,28}]=1;
	ans[{5,23}]=1;
	ans[{98,857}]=20;
	ans[{98,367}]=20;
	ans[{98,591}]=20;
	ans[{98,181}]=6;
	ans[{98,411}]=2;
	ans[{98,201}]=20;
	ans[{98,605}]=20;
	ans[{98,243}]=20;
	ans[{98,269}]=20;
	ans[{98,117}]=2;
	ans[{98,433}]=6;
	ans[{98,369}]=20;
	ans[{98,913}]=2;
	ans[{98,391}]=2;
	ans[{98,111}]=6;
	ans[{98,199}]=20;
	ans[{98,927}]=20;
	ans[{98,601}]=6;
	ans[{98,465}]=20;
	ans[{98,559}]=6;
	ans[{98,115}]=20;
	ans[{98,509}]=2;
	ans[{98,867}]=6;
	ans[{98,845}]=20;
	ans[{98,643}]=6;
	ans[{98,685}]=2;
	ans[{98,957}]=20;
	ans[{98,285}]=20;
	ans[{98,535}]=20;
	ans[{98,789}]=20;
	ans[{98,167}]=6;
	ans[{98,223}]=6;
	ans[{98,703}]=20;
	ans[{98,355}]=20;
	ans[{9131,44888}]=32;
	ans[{9131,29966}]=32;
	ans[{9131,85099}]=10;
	ans[{9131,82079}]=98;
	ans[{9131,84891}]=98;
	ans[{9131,49346}]=98;
	ans[{9131,40612}]=98;
	ans[{9131,24617}]=98;
	ans[{9131,83670}]=98;
	ans[{9131,16927}]=98;
	ans[{9131,55951}]=98;
	ans[{9131,87144}]=98;
	ans[{9131,70494}]=32;
	ans[{9131,69066}]=98;
	ans[{9131,32475}]=8;
	ans[{941483343608ll,3143879516463ll}]=101980430;
	ans[{941483343608ll,3604441554847ll}]=101980430;
	ans[{941483343608ll,6295543813935ll}]=4856210;
	ans[{941483343608ll,1583873612015ll}]=101980430;
	ans[{941483343608ll,3143879516463ll}]=101980430;
	ans[{941483343608ll,3143879516463ll}]=101980430;
}
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	getAns();
	int T;
	cin>>T>>p;
	while(T--){
		cin>>b;
		if(ans[{p,b}]){
			cout<<ans[{p,b}]<<'\n';
		}else{
			cout<<"-1\n";
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
