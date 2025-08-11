#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,m[1005][1005],p[1005];
priority_queue<int> q;
int init(int x){
	int ans=1;
	while(x){
		ans*=(x%10);
		x/=10;
	}
	return ans;
}
int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		p[i]=init(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			m[p[i]][p[j]]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			q.push(m[i][j]);
	int ans=0;
	for(int i=0;i<k;i++){
		ans+=q.top();
		q.pop();
	}
	cout<<ans;
	return 0;
}

