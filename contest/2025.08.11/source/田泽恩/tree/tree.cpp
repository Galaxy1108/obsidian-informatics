#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to,nxt;
}e[514114];
const double E=1e-9;
int cnt,head[514114],n,f;
struct node{
	long long s,c,id;
	double ave;
}a[514114],b[514114],K;
void adde(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool cmp(node x,node y){
	if((1.0*(K.s+x.s))/(1.0*(K.c+x.c))-(1.0*(K.s+y.s))/(1.0*(K.c+y.c))>-E) return true;
	return false;
}
void dfs(int u){
	int now=0;
	for(int i=head[u];i;i=e[i].nxt){
		dfs(e[i].to);
	}
	for(int i=head[u];i;i=e[i].nxt){
		b[++now]=a[e[i].to];
	}
	K=a[u];
	sort(b+1,b+now+1,cmp);
	//puts("----------");
	//cout<<u<<endl;
	for(int i=1;i<=now;++i){
		if((1.0*(b[i].s+a[u].s))/(1.0*(b[i].c+a[u].c))-a[u].ave>-E){
			//cout<<b[i].id<<" ";
			a[u].c+=b[i].c;
			a[u].s+=b[i].s;
			a[u].ave=(1.0*a[u].s)/(1.0*a[u].c);
		}
	}
	//cout<<endl;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d",&f);
		adde(f,i);
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i].s);
		a[i].ave=a[i].s;
		a[i].c=1;
		a[i].id=i;
	}
	dfs(1);
	for(int i=1;i<=n;++i){
		printf("%.9lf\n",a[i].ave);
	}
	return 0;
}
