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
#define int ll
typedef long long ll;
constexpr const int N=1e5,M=1e5,P=1e9+9;
int n;
struct PersistentSegTree{
	int size,root[M+1];
	struct node{
		int l,r;
		int lChild,rChild;
		int value,tag;
		int size(){
			return r-l+1;
		}
	}t[80*N+1];
	PersistentSegTree(){
		size=0;
	}
	int create(node x){
		t[++size]=x;
		return size;
	}
	int build(int l,int r){
		t[++size]={l,r};
		return size;
	}
	int clone(int p){
		t[++size]=t[p];
		return size; 
	}
	void down(int p){
		int mid=t[p].l+t[p].r>>1;
		if(!t[p].lChild){
			t[p].lChild=create({t[p].l,mid});
		}else{
			t[p].lChild=clone(t[p].lChild);
		}
		if(!t[p].rChild){
			t[p].rChild=create({mid+1,t[p].r});
		}else{
			t[p].rChild=clone(t[p].rChild);
		}
		if(t[p].tag){
			t[t[p].lChild].value=(t[t[p].lChild].value + 1ll*t[t[p].lChild].size()*t[p].tag)%P;
			t[t[p].lChild].tag=(t[t[p].lChild].tag + t[p].tag)%P;
			t[t[p].rChild].value=(t[t[p].rChild].value + 1ll*t[t[p].rChild].size()*t[p].tag)%P;
			t[t[p].rChild].tag=(t[t[p].rChild].tag + t[p].tag)%P;
			t[p].tag=0;
		}
	}
	void up(int p){
		t[p].value=(t[t[p].lChild].value + t[t[p].rChild].value)%P;
	}
	int add(int p,int l,int r,int k){
		p=clone(p);
//		cerr<<"add("<<p<<"["<<t[p].l<<","<<t[p].r<<"],"<<l<<","<<r<<","<<k<<")\n";
		if(l<=t[p].l&&t[p].r<=r){
			t[p].value=(t[p].value + 1ll*t[p].size()*k)%P;
//			cerr<<"t["<<p<<"].value="<<t[p].value<<endl;
			t[p].tag=(t[p].tag+k)%P;
			return p;
		}
		down(p);
		if(l<=t[t[p].lChild].r){
			t[p].lChild=add(t[p].lChild,l,r,k);
		}
		if(t[t[p].rChild].l<=r){
			t[p].rChild=add(t[p].rChild,l,r,k);
		}
		up(p);
		return p;
	}
	void add(int v,int i,int l,int r,int k){
		root[i]=add(root[v],l,r,k);
//		cerr<<"root["<<i<<"]="<<root[i]<<endl;
	}
	int query0(int p,int l,int r){
		p=clone(p);
		if(l<=t[p].l&&t[p].r<=r){
//			cerr<<"p="<<p<<"["<<t[p].l<<","<<t[p].r<<"]"<<endl;
//			cerr<<"return "<<t[p].value<<endl;
			return t[p].value;
		} 
		down(p);
		int ans=0;
		if(l<=t[t[p].lChild].r){
			ans=query0(t[p].lChild,l,r);
		}
		if(t[t[p].rChild].l<=r){
			ans=(ans + query0(t[p].rChild,l,r))%P;
		}
		return ans;
	}
	int query(int v,int l,int r){
		int ans=query0(root[v],l,r);
//		cerr<<"query("<<v<<","<<l<<","<<r<<")="<<ans<<endl;
		return ans;
	}
}t;
main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int m,q;
	cin>>n>>m>>q;
	t.root[0]=t.build(1,n);
	for(int i=1;i<=m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		t.add(i-1,i,l,r,x);
	}
	while(q--){
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		int ans=0;
		for(int i=u;i<=d;i++){
			ans=(ans + t.query(i,l,r))%P;
		}
//		cerr<<"::";
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10 9 1
3 10 1
2 8 1
1 10 1
2 7 1
2 9 1
2 9 1
2 6 1
2 6 1
3 10 1
5 9 2 6

169
*/
