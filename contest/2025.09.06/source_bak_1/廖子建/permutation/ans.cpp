#include<bits/stdc++.h>
#define int long long 
#define N 100000
using namespace std;
int n,p[N+5],q[N+5],h[N+5],f[N+5],f2[N+5],g[N+5],vis[N+5];
bool flag,ansf;
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
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
			if(g[p[h[i]]]!=q[i])return;
		}
		cout<<"YES\n";
//		flag=0;
		for(int i=1;i<=n;i++)print(h[i]),putchar(' '); 
		cout<<"\n";
		exit(0);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		f[i]=1,h[x]=i,g[i]=x;
		dfs(x+1),f[i]=0;
	}
	return;
}
void dfs2(int x){
//	if(x>n){
//		for(int i=1;i<=n;i++){
//			cout<<q[i]<<" ";
//		}
//		cout<<":\n";
//		flag=1;
	dfs(1);
//	if(flag)
	cout<<"NO\n";
	return;
//	}
	for(int i=1;i<=n;i++){
		if(f2[i])continue;
		f2[i]=1,q[x]=i,
		dfs2(x+1),f2[i]=0;
	}
	return;
}
main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.ans","w",stdout);
	n=read(),flag=ansf=1;
//	n=5;
	for(int i=1;i<=n;i++){
		p[i]=read();
		if(p[i]!=(i%n)+1)flag=0;
	}
//	p[1]=2,p[2]=3,p[3]=4,p[4]=5,p[5]=1;
	for(int i=1;i<=n;i++){
		q[i]=read(),vis[q[i]]++;
		if(vis[q[i]]>1)ansf=0;
	}
//	if(flag){
////		cout<<"flag\n";
//		if(!ansf){
//			cout<<"NO\n";
//			return 0;
//		}
//		h[1]=1;
//		int i=1,cnt=0;
//		do{
//			h[q[i]]=h[i]%n+1;
//			i=q[i],cnt++;
//		}while(i!=1);
//		if(cnt!=n){
//			cout<<"NO\n";
//			return 0;
//		}
//		cout<<"YES\n";
//		for(int i=1;i<=n;i++){
//			cout<<h[i]<<" ";
//		}
//		cout<<"\n";
//		return 0;
//	}
	dfs2(1);
	return 0;
}
//#include<bits/stdc++.h>
//#define int long long 
//#define N 100000
//using namespace std;
//int n,p[N+5],q[N+5],h[N+5],f[N+5],g[N+5];
//int read(){
//	int f=1,g=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		if(ch=='-')f=-1;
//		ch=getchar();
//	}
//	while('0'<=ch&&ch<='9'){
//		g=g*10+ch-'0';
//		ch=getchar();
//	}
//	return f*g;
//}
//void print(int x){
//	if(x<0){
//		putchar('-');
//		x*=-1;
//	}
//	if(x>9)print(x/10);
//	putchar(x%10+'0');
//	return;
//}
//main(){
//	return 0;
//}
