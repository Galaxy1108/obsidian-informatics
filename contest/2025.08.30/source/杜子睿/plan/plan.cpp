#include<bits/stdc++.h>
using namespace std;
int n,a[205],k,ans,f,ss[205][205],dp[205][205];
vector<int> e[205];
int b[205];
struct node{
	int u,v;
}s[205];
int book[205][205];
int bfs(int x,int fa){
	b[x]=1;
	for(int i:e[x]){
		if(i==fa)
			continue;
		node tt={x,i};
		if(x>i)
			swap(tt.u,tt.v);
		if(book[tt.u][tt.v])
			continue;
		f=__gcd(f,a[i]);
		bfs(i,x);
	}
} 
void check(){
	int tt=0;
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		if(b[i])
			continue;
		f=a[i];
		bfs(i,i);
		tt+=f;
	}
	ans=max(ans,tt);
}
void dfs(int x,int cnt){
	if(cnt==k){
		check();
		return;
	}
	if(x==n)
		return;
	dfs(x+1,cnt);
	book[s[x].u][s[x].v]++;
	dfs(x+1,cnt+1);
	book[s[x].u][s[x].v]--;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>s[i].u>>s[i].v;
		if(s[i].u>s[i].v)
			swap(s[i].u,s[i].v);
		e[s[i].u].push_back(s[i].v);
		e[s[i].v].push_back(s[i].u);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=10){
		dfs(1,0);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				ss[i][j]=a[i];
				for(int kk=i+1;kk<=j;kk++)
					ss[i][j]=__gcd(a[kk],ss[i][j]);	
			}
		k++;
		memset(dp,-0x3f3f3f3f,sizeof dp);
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>=0;j--)
				for(int kk=0;kk<k;kk++)
					dp[i][kk+1]=max(dp[i][kk+1],dp[j][kk]+ss[j+1][i]);
		cout<<dp[n][k];
	}
	return 0;
}

