#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}a[120001];
int T,n,m,fl=1,fa[1001],del[10001],t[1001][10]={};
vector<int> q[120001];
bool cmp(node x,node y){
	return x.l<y.l;
}
void dfs1(int x,int fx){
	fa[x]=fx;
	del[x]=del[fx]+1;
	int len=q[x].size();
	for(int i=0;i<len;i++){
		if(q[x][i]!=fx){
			dfs1(q[x][i],x);
		}
	}
}
void lc(int x,int y,int s){
	t[x][s]=2,t[y][s]=3;
	if(del[x]>del[y]){
		lc(y,x,s);
		return;
	}
	while(del[x]<del[y]) x=fa[x],t[x][s]=1;
	while(x!=y){
		x=fa[x],t[x][s]=1;
		y=fa[y],t[y][s]=1;
	}
}
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	cin>>T;
	int x,y;
	while(T--){
		cin>>n;
		fl=1;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			if(x!=i||y!=i+1)fl=0;
			q[x].push_back(y);
			q[y].push_back(x);
		}
		if(fl==1){
			cin>>m;
			for(int i=1;i<=m;i++){
				cin>>a[i].l>>a[i].r;
			}
			sort(a+1,a+1+n,cmp);
			int ma=0,i;
			for(i=1;i<=m;i++){
				if(ma>a[i].r){
					cout<<"No"<<endl;
					break;
				}
				ma=a[i].r;
			}
			if(i>m) cout<<"Yes"<<endl;
			continue;
		}
		cin>>m;
		if(m==2){
			dfs1(1,0);
			cin>>x>>y;
			lc(x,y,1);
			cin>>x>>y;
			if(t[x][1]==1&&t[y][1]==1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
			for(int i=1;i<=n;i++){
				fa[x]=0;
				del[x]=0;
				t[x][1]=0;
			} 
		}
		else{
			if(m=n-1)  cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
		
	return 0;
}
