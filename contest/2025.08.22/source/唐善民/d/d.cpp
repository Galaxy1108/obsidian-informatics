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
constexpr const int N=1e5,X=1e9;
int n,x[N+1],y[N+1];
struct line{
	int c,a,b;
};
bool operator <(line a,line b){
	if(a.c!=b.c){
		return a.c<b.c;
	}else if(a.a!=b.a){
		return a.a<b.a;
	}else{
		return a.b<b.b;
	}
}
bool check(line pl,int k){
	for(int i=0;i<k;i++){
		if(y[i]!=(pl.a*i+pl.b)/pl.c){
			return false;
		}
	}
	return true;
}
line query(int l,int r){
	int k=r-l+1;
	for(int i=0;i<k;i++){
		y[i]=x[i+l];
	}
	if(k==1){
		return {1,0,y[0]};
	}
	for(int c=1;c<=10;c++){
		for(int a=0;a<=10;a++){
			for(int b=0;b<=10;b++){
				if(check({c,a,b},k)){
					return {c,a,b};
				}
			}
		}
	}
	return {1,y[1]-y[0],y[0]};
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int q;
		cin>>q;
		while(q--){
			int l,r;
			cin>>l>>r;
			line ans=query(l,r);
			cout<<ans.a<<' '<<ans.b<<' '<<ans.c<<'\n';
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
c=1
2
5
1 1 2 2 2
3
1 1
3 5
2 3
5
1 2 3 4 6
1
2 4


0 1 1
0 2 1
1 1 1

1 2 1

*/
/*
3
5
1 1 2 2 2
4
1 5
1 1
3 5
2 3
5
1 2 3 4 6
3
1 5
2 4
3 5
3
0 3 5
1
1 3

1 4 3
0 1 1
0 2 1
1 1 1
5 4 4
1 2 1
3 6 2
5 1 2

*/
