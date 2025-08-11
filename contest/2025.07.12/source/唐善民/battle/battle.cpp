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
constexpr const int N=150000;
struct node{
	int x,y,z;
}a[N+1];
int n,sufMax[N+1];
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	int ans=-1;
	sort(a+1,a+n+1,[](node a,node b){
		if(a.x!=b.x){
			return a.x>b.x;
		}else if(a.y!=b.y){
			return a.y>b.y;
		}
		return a.z>b.z;
	});
	int l=2;
	while(l<=n&&a[l].x==a[1].x){
		l++;
	}
	sort(a+l,a+n+1,[](node a,node b){
		if(a.y!=b.y){
			return a.y>b.y;
		}else if(a.x!=b.x){
			return a.x>b.x;
		}
		return a.z>b.z;
	});
	sufMax[n]=a[n].z;
	for(int i=n-1;i>=l+1;i--){
		sufMax[i]=max(sufMax[i+1],a[i].z); 
	} 
	for(int i=l;i<n;i++){
		if(sufMax[i+1]>a[i].z){
			ans=max(ans,a[1].x+a[i].y+sufMax[i+1]);
		}
		/*for(int j=i+1;j<=n;j++){
			if(a[j].z>a[i].z){
				ans=max(ans,a[1].x+a[i].y+a[j].z);
			}
		}*/
	}
	sort(a+l,a+n+1,[](node a,node b){
		if(a.z!=b.z){
			return a.z>b.z;
		}else if(a.y!=b.y){
			return a.y>b.y;
		}
		return a.x>b.x;
	});
	sufMax[n]=a[n].y;
	for(int i=n-1;i>=l+1;i--){
		sufMax[i]=max(sufMax[i+1],a[i].y); 
	}
	for(int i=l;i<n;i++){
		if(sufMax[i+1]>a[i].y){
			ans=max(ans,a[1].x+sufMax[i+1]+a[i].z);
		}
		/*for(int j=i+1;j<=n;j++){
			if(a[j].y>a[i].y){
				ans=max(ans,a[1].x+a[j].y+a[i].z);
			}
		}*/
	} 
	cout<<ans<<'\n'; 
	
	cout.flush(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
