#include <bits/stdc++.h>
using namespace std;
int n,m,q,p,b,a[22],cnt[2],res[22],ans;
void dfs(int now,int cnt0,int cnt1){
	if(now==n+1){
		int r=0;
		for(int i=1;i<n;++i) r+=res[i]^res[i+1];
		ans=min(ans,r);
		return;
	}
	if(~res[now]){
		if((res[now]==1&&cnt1)||(res[now]==0&&cnt0)) dfs(now+1,cnt0-(!res[now]),cnt1-res[now]);
	}
	if(cnt0){
		res[now]=0;
		dfs(now+1,cnt0-1,cnt1);
	}
	if(cnt1){
		res[now]=1;
		dfs(now+1,cnt0,cnt1-1);
	}
	res[now]=-1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cnt[a[i]&1]++;
	}
	for(int i=1;i<=n;++i) res[i]=-1;
	for(int i=1;i<=m;++i){
		cin>>p>>b;
		res[p]=b&1;
	}
	while(q--){
		ans=114514;
		int opt;
		cin>>opt>>p;
		if(opt&1){
			res[p]=-1;
		}
		else{
			cin>>b;
			res[p]=b&1;
		}
		dfs(1,cnt[0],cnt[1]);
		cout<<ans<<endl;
	}
	return 0;
}
