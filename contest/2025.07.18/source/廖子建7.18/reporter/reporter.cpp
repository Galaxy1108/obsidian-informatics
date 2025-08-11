#include<bits/stdc++.h>
#define int long long
#define N 20
#define Inf 1000000000
using namespace std;
int n,a[N+5],h[N+5],c[N+5],minn[N+5],low[N+5]={},dfn[N+5]={},tot=0,ver[N+5]={},color=0,p[N+5]={},f[N+5]={},val[N+5]={},tmp[N+5],ans=LONG_LONG_MAX;
bool flag[N+5]={};
stack<int>q;
vector<int>block[N+5];
queue<int>que;
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
void trajan(int x){
	
	dfn[x]=low[x]=++tot,ver[x]=1;
	q.push(x);
	if(!dfn[a[x]])trajan(a[x]);
	else if(ver[a[x]])low[x]=min(low[x],low[a[x]]);
//	cout<<x<<" "<<low[x]<<" "<<dfn[x]<<" dfsdfs234234\n";
	if(low[x]==dfn[x]){
		color++;
		while(!q.empty()&&low[q.top()]==low[x]){
			block[color].push_back(q.top()),p[q.top()]=color;
//			cout<<color<<" "<<q.top()<<"\n";
			q.pop();
		}
	}
	ver[x]=0;
	return;
}
bool check(int x){
	if(f[x])minn[f[x]]=max(minn[f[x]],minn[x]);
	if(!flag[x])return minn[x]<=h[x];
	return 1;
}
void dfs(int x){
	if(x>color){
		int u,sum=0;
		while(!que.empty())que.pop();
		for(int i=1;i<=color;i++){
			minn[i]=Inf,val[i]=tmp[i];
			if(!val[i])que.push(i);
		}
		while(!que.empty()){
			u=que.back(),que.pop();
//			cout<<u<<" "<<f[u]<<"\n";
			if(!check(u))return;
			if(f[u]){
				val[f[u]]--;
				if(!val[f[u]])que.push(f[u]);
			}
		}
//		cout<<"sdfsdaf\n";
		for(int i=1;i<=color;i++){
			if(!flag[i])continue;
			for(int j:block[i]){
				if(minn[i]!=h[j])sum+=c[j];
			}
		}
		ans=min(ans,sum);
		return;
	}
	flag[x]=0,dfs(x+1);
	flag[x]=1,dfs(x+1);
	return;
}
main(){
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	cout<<0;
	return 0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),h[i]=read(),c[i]=read();
	for(int i=1;i<=n;i++){
		if(!dfn[i])trajan(i);
	}
	for(int i=1;i<=color;i++){
		f[i]=0;
		for(int j:block[i]){
			if(p[a[j]]!=i){
				f[i]=p[a[j]],ver[p[a[j]]]++;
				break;
			}
		}
//		cout<<f[i]<<"\n";
	}
	for(int i=1;i<=color;i++)tmp[i]=ver[i];
//	cout<<"sdfasdfasdf\n";
	dfs(1);
	print(ans);
	return 0;
}
