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
constexpr const int N=2e5,Q=1e6;
struct question{
	int t,i,id;
}a[Q+1];
int n,q,p[N+1],ans[Q+1];
void solve(){
	static int left[N+1]/*,right[N+1]*/,backup[N+1];
	static bool stop=false;
	if(stop){
		return;
	}
	for(int i=1;i<=n;i++){
		backup[i]=p[i];
	}
	for(int i=1;i<=(n>>1);i++){
		left[i]=p[i];
	}
	int i=1,j=(n>>1)+1,pos=0;
	for(;i<=(n>>1)&&j<=n;){
		if(left[i]<p[j]){
			p[++pos]=left[i++];
		}else{
			p[++pos]=p[j++]; 
		}
	}
	while(i<=(n>>1)){
		p[++pos]=left[i++];
	}
	for(int i=1;i<=n;i++){
		if(backup[i]!=p[i]){
			return;
		}
	}
	stop=true;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a[i].t>>a[i].i;
		a[i].id=i;
	}
	sort(a+1,a+q+1,[](question a,question b){
		return a.t<b.t;
	});
	for(int i=1;i<=q;i++){
		for(int j=a[i-1].t+1;j<=a[i].t;j++){
			solve();
		}
		ans[a[i].id]=p[a[i].i];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6 3
1 5 6 2 3 4
1 2
0 4
1 5
*/
