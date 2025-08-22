#include<bits/stdc++.h>
using namespace std;
int a[2002][2002],dis[2002];
vector<pair<int,int>>g[2002];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			cin>>a[i][j];
			g[i].push_back({a[i][j],j});
			g[j].push_back({a[i][j],i});
		}
	}
	int valch=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		a[i][i]=0x3f3f3f3f;
	}
	for(int i=2;i<n;i++){
		for(int j=n-i+1;j<=n;j++){
			if(i==j){
				a[i][j]=0x3f3f3f3f;
				continue;
			}
			if(a[i][j]==0)a[i][j]=a[j][i];
			cout<<a[i][j]<<' ';
			valch=min(valch,a[i][j]);
		}cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		int mini=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			mini=min(mini,a[i][j]);
		}
		dis[i]=min((mini-valch)*2,0x3f3f3f3f);
		cout<<"i "<<dis[i]<<'\n';
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++){
		if(dis[i]==0){
			q.push({0,i});
		}
	}
	while(!q.empty()){
		auto tmp=q.top();q.pop();
		int pt=tmp.second;
		for(auto x:g[pt]){
			int to=x.second,val=x.first;
			if(dis[to]>dis[pt]+val){
				dis[to]=dis[pt]+val;
				q.push({dis[to],to});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<(valch)*(n-1)+dis[i]<<'\n';
	}
	return 0;
}
