#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int n=10,N=15;
int b[N];
bool del[N];
int ans[113400][11],cnt,vec[90][11];
void dfs(int x){
	if(x==n+1){
		cnt++;
		for(int i=1;i<=n;i++)vec[cnt][i]=b[i];
		return;
	}
	if(!del[x-1]&&x!=1){
		del[x-1]=1;b[x]=x-1;
		dfs(x+1);
		del[x-1]=0;
	}
	if(!del[x]){
		del[x]=1;b[x]=x;
		dfs(x+1);
		del[x]=0;
	}
	if(!del[x+1]&&x!=n){
		del[x+1]=1;b[x]=x+1;
		dfs(x+1);
		del[x+1]=0;
	}
}
typedef long long ll;
const int mod=1e7+9;
int h[mod],ne[mod],tot;
ll e[mod];
ll f(ll x){
	return (x<<11)^(x>>7);
}
bool check(ll v){
	int u=v%mod;
	for(int i=h[u];i;i=ne[i])if(e[i]==v)return 1;
	return 0;
}
void insert(ll v){
	if(check(v))return;
	int u=v%mod;
	e[++tot]=v,ne[tot]=h[u],h[u]=tot;
}
ll get(int*x){
	ll ans=0;
	for(int i=1;i<=10;i++)ans=ans*11+x[i];
	return f(ans);
}
int tmp[N],siz;
void solve(int x){
	if(x==n+1){
		ll id=get(b);
		if(check(id))return;
		siz++;
		for(int i=1;i<=n;i++)ans[siz][i]=b[i];
		for(int i=1;i<=89;i++){
			for(int j=1;j<=n;j++)tmp[j]=vec[i][b[j]];
			ll id=get(tmp);
			insert(id);
		}
		return;
	}
	for(int i=x+1;i<=n;i++)if(!del[i]){
		del[i]=1;b[x]=i;
		solve(x+1);
		del[i]=0;
	}
	for(int i=x;i>=1;i--)if(!del[i]){
		del[i]=1;b[x]=i;
		solve(x+1);
		del[i]=0;
	}
}
int main(){
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	dfs(1);solve(1);
	printf("%d\n",siz);
	for(int i=1;i<=siz;i++){
		for(int j=1;j<=10;j++){
			if(ans[i][j]==10)putchar('1'),putchar('0');
			else putchar(ans[i][j]+'0');
			putchar(' ');
		}puts("");
	}
	return 0;
}
/*
10!/113400=32=2^5
一个排列对应着几乎相等的排列有89个 
*/
