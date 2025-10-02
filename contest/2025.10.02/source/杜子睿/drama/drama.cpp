#include<bits/stdc++.h>
using namespace std;
int n;
long long h[2000005];
void pr(__int128 x){
	if(x==0){
		cout<<0;
		return;
	}
	stack<int> q;
	while(x){
		q.push(x%10);
		x/=10;
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	__int128 ans=0;
	for(int i=1;i<=n;i++){
		long long minn=h[i],maxx=h[i];
		ans=max(ans,(__int128)minn*maxx);
		for(int j=i+1;j<=n;j++){
			minn=min(minn,h[j]);
			maxx=max(maxx,h[j]);
			ans=max(ans,(__int128)minn*maxx*(j-i+1));
		}
	}
	pr(ans);
	return 0;
}
