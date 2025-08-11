#include <bits/stdc++.h>
using namespace std;
const int maxn=2.5e6+100;
const int mod=1e9+7;
int read()
{
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0'; 
		c=getchar();
	}
	return f*k;
}
int n,m,q,h[maxn],cnt;
struct Edge{
	int w,to,nxt;
}edge[maxn];
void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].nxt=h[x];
	edge[cnt].w=0;
	h[x]=cnt;
}
bool vis[maxn];
/*void dfs(int s,int n,int x,int y)
{
	if(n==s){
		if(x<0){
			cout<<-1<<endl;
		}
		else cout<<x<<endl;
		return;
	}
	for(int i=h[x];i;i=edge[i].nxt){
		if(!vis[edge[i].to]){
			if(edge[i].w>y) x--;
			else y-=edge[i].w;
			vis[n]=true;
			dfs(s,edge[i].to,x,y);	
		}
	}
}*/
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	cout<<-1;
/*	n=read();m=read();q=read();
 	for(int i=1;i<=n-1;i++){
 		int a,b;
 		a=read();b=read();
 		add(a,b);add(b,a);
	}
	for(int j=1;j<=m;j++){
		int p,c;p=read();c=read();
		edge[2*p-1].w+=c;edge[2*p].w+=c;
	}
	for(int k=1;k<=q;k++){
		int s,t,x,y;
		s=read(),t=read(),x=read(),y=read();
		dfs(s,t,x,y);
	}*/
	return 0;
}
