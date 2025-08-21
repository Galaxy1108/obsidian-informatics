#include<cstdio>
#include<vector> 
#include<algorithm>
using namespace std;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
	int gc=gcd(x,y);
	return x*y/gc;
}
vector<int> e[5005];
vector<pair<int,int> > g;
void add(int u,int v){
	g.push_back({u,v});
	e[u].push_back(v);
	e[v].push_back(u);
}
int n,a[5005];
int b[5005];
bool check(int x,int y){
	int nw=lcm(a[x],y);
	for(int i=0;i<e[x].size();i++){
		if(gcd(a[x],a[e[x][i]])!=gcd(nw,a[e[x][i]])) return 0;
	}
	return 1;
}
int main(){
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	scanf("%d",&n);
	if(n<=10){
		int lc=1;
		for(int i=1;i<=n;i++) lc=lcm(lc,i);
		printf("%d ",lc);
		for(int i=2;i<=n;i++) printf("%d ",i);
		puts("");
		for(int i=1;i<n;i++) printf("%d %d\n",1,i+1);
		return 0;
	}
	add(1,2);
	add(2,3);
	a[1]=2,a[2]=6,a[3]=3;
	for(int i=4;i<=n;i++){
		int mi=1e9,id=0;
		for(int j=i-1;j;j--){
			if(check(j,i)){
				if(mi>lcm(i,a[j])){
					mi=lcm(i,a[j]);
					id=j;
				}
				break;				
			}
		}
		a[i]=i;
		a[id]=lcm(i,a[id]);
		add(i,id);
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	for(pair<int,int> v:g) printf("%d %d\n",v.first,v.second);
	return 0;
}
