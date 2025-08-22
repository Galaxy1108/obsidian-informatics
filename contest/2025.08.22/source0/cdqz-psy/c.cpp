#include<bits/stdc++.h>
using namespace std;
const int N=18;
int n,sed,a[N][N];
int f[N][1<<N];
void dfs(int x,int s){
	if(f[x][s]) return ;
	int c=__builtin_popcount(s);
	if(c==1){
		for(int i=1;i<=n+1;i++){
			if(s&(1<<(i-1))){
				f[x][s]=i;
				return ;
			}
		}
	}
	int res=0;
	for(int i=1;i<=n+1;i++){
		if(!(s&(1<<(i-1)))) continue;
		dfs(x%n+1,s^(1<<(i-1)));
		int pos=f[x%n+1][s^(1<<(i-1))];
		if(a[x][res]<a[x][pos]) res=pos;
	}
	f[x][s]=res; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>sed;
	if(!sed){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				cin>>a[i][j];
			}
		}
	}
	else{
		mt19937 rnd(sed);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				a[i][j]=j;
				swap(a[i][j],a[i][rnd()%j+1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,(1<<(n+1))-1);
		cout<<f[i][(1<<(n+1))-1]<<" ";
	}
}
