#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool del[2500];
ll n2[12],ks[12];
ll num[2050];
char maps[2050][2600];
//ll min_y=LLONG_MAX,max_x=0,max_y=0;

void dfs(ll x,ll y,ll idx,char draw,ll cnt,ll k){
	maps[x][y]=draw;
//	min_y=min(min_y,y);
//	max_x=max(max_x,x);
//	max_y=max(max_y,y);
//	cout<<x<<' '<<y<<' '<<k<<endl;
	switch (draw){
		case 'o':
			if(k==1){
				break;
			}
			if(!del[2*idx]){
				dfs(x+1,y-1,2*idx,'/',ks[k-1],k-1);
			}
			if(!del[2*idx+1]){
				dfs(x+1,y+1,2*idx+1,'\\',ks[k-1],k-1);
			}
			break;
		case '/':
			if(cnt==1){
				dfs(x+1,y-1,idx,'o',-1,k);
			}else{
				dfs(x+1,y-1,idx,'/',cnt-1,k);
			}
			break;
		case '\\':
			if(cnt==1){
				dfs(x+1,y+1,idx,'o',-1,k);
			}else{
				dfs(x+1,y+1,idx,'\\',cnt-1,k);
			}
			break;
	}
}

int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout); 
	ll m,n;
	cin>>m>>n;
	n2[0]=ks[1]=1;
	for(int i=2;i<=m;i++){
		n2[i-1]=n2[i-2]*2;
		ks[i]=3*n2[i-2]-1;
	}
	for(int i=1;i<=n;i++){
		ll a,b;
		cin>>a>>b;
		del[n2[a-1]+(b-1)]=true;
	}
	dfs(1,ks[m]+1,1,'o',0,m);
	for(int i=1;i<=ks[m]+1;i++){
		for(int j=1;j<=2*ks[m]+1;j++){
			if(maps[i][j]=='\0'){
				cout<<' ';
			}else{
				cout<<maps[i][j];
			}
		}
		cout<<'\n';
	}
} 
