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
constexpr const int N=2e5,P=998244353;
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
//testId=1
namespace judge1{
	constexpr const int N=1;
	bool is(){
		return n<=N;
	}
	int query(){
		return 2;
	} 
	int main(){
		cout<<query()<<'\n';
		int q;
		cin>>q;
		while(q--){
			int x,y;
			cin>>x>>y;
			a[x]=y;
			cout<<query()<<'\n';
		}
		return 0;
	}
}
//2<=testId<=5
namespace judge2{
	constexpr const int N=5,M=10,inf=0x3f3f3f3f;
	bool is(){
		return n<=N;
	}
	int size,s[M+1],id[M+1],cnt[N+1][N+1];
	void dfs(int p,int &ans){
		if(p>size){
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=size;i++){
				cnt[id[i]][s[i]]++;
			}
			int pl=0;
			for(int i=1;i<=n;i++){
				int Max=-inf,x=-1; 
				for(int j=1;j<=n;j++){
					if(!cnt[i][j]){
						continue;
					}
					if(cnt[i][j]>Max){
						Max=cnt[i][j];
						x=j;
					}
				}
				if(x==-1){
					continue;
				}
				pl+=1ll<<x;
			}
			ans=min(ans,pl);
			return;
		}
		for(id[p]=1;id[p]<=n;id[p]++){
			dfs(p+1,ans);
		}
	} 
	int query(){
		int ans=inf;
		size=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s[++size]=i;
			}
		}
		dfs(1,ans);
		return ans;
	}
	int main(){
		cout<<query()<<'\n';
		int q;
		cin>>q;
		while(q--){
			int x,y;
			cin>>x>>y;
			a[x]=y;
			cout<<query()<<'\n';
		}
		return 0;
	}
}
//18<=testId<=20
namespace judge3{
	bool is(int id){
		return 18<=id&&id<=20;
	}
	int query(){
		int Max=a[1],x=1;
		for(int i=2;i<=n;i++){
			if(a[i]>Max){
				Max=a[i];
				x=i;
			}
		}
		return qpow(2,x);
	}
	int main(){
		cout<<query()<<'\n';
		int q;
		cin>>q;
		while(q--){
			int x,y;
			cin>>x>>y;
			a[x]=y;
			cout<<query()<<'\n';
		}
		return 0;
	}
}
int main(){
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int testId;
	cin>>testId>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(judge1::is()){
		judge1::main();
	}else if(judge2::is()){
		judge2::main();
	}else if(judge3::is(testId)){
		judge3::main();
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
