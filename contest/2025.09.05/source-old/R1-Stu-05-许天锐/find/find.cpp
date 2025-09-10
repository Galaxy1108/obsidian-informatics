#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int n,k;
int cnt[1001][1001],maxn;
priority_queue<int>q;
int main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k=i,ans=1,ans1=1;
			while(k){
				ans*=(k%10);
				k/=10;
			}
			if(!ans)continue;
			k=j;
			while(k){
				ans1*=(k%10);
				k/=10;
			}
			if(!ans1)continue;
			cnt[ans][ans1]++;
			maxn=max(maxn,max(ans,ans1));
		}
	}
//	for(int i=1;i<=maxn;i++){
//		for(int j=1;j<=maxn;j++)cout<<cnt[i][j]<<" ";
//		cout<<endl;
//	}
	int ans=0;
	cout<<maxn<<endl;
	for(int i=1;i<=maxn;i++)for(int j=1;j<=maxn;j++)if(cnt[i][j])q.push(cnt[i][j]);
	for(int i=1;i<=k;i++)if(q.size())ans+=q.top(),q.pop();
	cout<<ans%p;
	return 0;
}
