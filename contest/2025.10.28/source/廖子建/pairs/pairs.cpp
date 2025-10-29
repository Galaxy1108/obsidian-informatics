#include<bits/stdc++.h>
#define int long long
#define N 200
#define M 10000000
#define lowbit(x) (x&-x)
#define Mod p
using namespace std;
int n,p,dp[N+5][N+5],tree[M+5],cnt[M+5],ans=0,tot,ksum;
bool vis[N+5];
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
void modify(int x,int v){
	while(x<=N){
		tree[x]=(tree[x]+v)%Mod;
		x+=lowbit(x);
	}
	return;
}
void modify2(int x,int v){
	while(x<=M){
//		cout<<x<<"\n"; 
		tree[x]=(tree[x]+v)%Mod;
		x+=lowbit(x);
	}
	return;
}
int query(int x){
	int sum=0;
	while(x){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
void dfs(int x,int sum){
	if(x>n){
//		cout<<sum<<"\n";
		cnt[++tot]=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		modify(i,1),vis[i]=1;
		dfs(x+1,sum+query(n)-query(i));
		modify(i,-1),vis[i]=0;
	}
	return;
}
main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=read(),p=read();
	dfs(1,0);
//	cout<<tot<<" h2euiewuygfweiuf\n";
	for(int i=1;i<=tot;i++){
		modify2(cnt[i]+1,1);
		ksum++;
//		cout<<i<<"\n";
		ans=(ans+ksum-query(cnt[i]+1)+Mod)%Mod;
	}
	print(ans);
	return 0;
}
