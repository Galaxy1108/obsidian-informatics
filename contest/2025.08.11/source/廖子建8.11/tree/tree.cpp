#include<bits/stdc++.h>
#define int long long
#define N 500000
using namespace std;
struct Node{int a,b;}v[N+5],a[N+5],sum;
int n,w[N+5],tot,uf;
double u;
vector<int>edge[N+5];
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
bool cmp(Node x,Node y){
//	return x.a*1.0/x.b>y.a*1.0/y.b;
	return sum.a*(y.b-x.b)+sum.b*(x.a-y.a)>x.b*y.a-x.a*y.b;
}
void dfs(int x){
	for(int i:edge[x])dfs(i);
	tot=0;
	for(int i:edge[x])a[++tot]=v[i];
	sort(a+1,a+1+tot,cmp);
	v[x].a=w[x],v[x].b=1;
	for(int i=1;i<=tot&&v[x].a*a[i].b<v[x].b*a[i].a;i++)v[x].a+=a[i].a,v[x].b+=a[i].b;
//	cout<<v[x].a<<" "<<v[x].b<<" "<<x<<" "<<tot<<" "<<a[1].a<<" "<<a[1].b<<" "<<cmp(a[1],v[x])<<"\n";
	return;
}
//void dfs2(int x){
//	for(int i:edge[x]){
//		if((w[i]-sum.a*1.0/sum.b)*1.0/(sum.b+1)>0)sum.a+=w[i],sum.b+=w[i]
//	}
//	return;
//}
main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		uf=read();
		edge[uf].push_back(i+1);
	}
	for(int i=1;i<=n;i++)w[i]=read();
	dfs(1);
	for(int i=1;i<=n;i++){
		u=v[i].a*1.0/v[i].b;
		printf("%.6lf\n",u);
	}
	return 0;
}
