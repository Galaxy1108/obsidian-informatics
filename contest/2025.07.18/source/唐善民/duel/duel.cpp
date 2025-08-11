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
constexpr const int N=200000;
int n,a[N+1];
ll query(int l,int k){
	static ll q[N*__lg(N+1)+1];
	int front=0,rear=0;
	ll sum=0;
	for(int i=l;i<l+(1<<k);i++){
		q[rear++]=a[i];
		sum+=a[i];
	}
	while(rear-front>1){
		if(!sum){
			return 0;
		}
		int tmp=abs(q[front]-q[front+1]);
		sum-=q[front]+q[front+1];
		front+=2;
		q[rear++]=tmp;
		sum+=tmp;
	}
	return q[front];
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		switch(op){
			case 1:
				a[x]=y;
				break;
			case 2:
				cout<<query(x,y)<<'\n';
				break;
		}
	}
	
	cout.flush(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
9 1 
1 0 2 0 4 1 3 2 8
2 2 3
*/ 
