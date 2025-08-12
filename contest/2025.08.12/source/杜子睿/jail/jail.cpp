#include<bits/stdc++.h>
using namespace std;
int n,m,q,s[120005],t[120005],f[120005][20],fa[120005],c[120005],d[120005];
vector<int> e[120005];
void dfs(int x){
	for(int i=1;i<=18;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i:e[x])
		if(i!=f[x][0]){
			f[i][0]=x;
			d[i]=d[x]+1;
			dfs(i);
		}
}
int lca(int x,int y){
	if(d[x]>d[y])
		swap(x,y);
	for(int i=18;i>=0;i--)
		if(d[f[y][i]]>=d[x])
			y=f[y][i];
	if(x==y)
		return x;
	for(int i=18;i>=0;i--)
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
bool qu(int x,int y){
	if(d[x]>d[y])
		swap(x,y);
	for(int i=18;i>=0;i--)
		if(d[f[y][i]]>=d[x])
			y=f[y][i];
	return(x==y);
}
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		cin>>m;
		memset(f,0,sizeof f);
		memset(d,0,sizeof d);
		d[1]=1;
		f[1][0]=0;
		dfs(1);
		for(int i=0;i<m;i++){
			cin>>s[i]>>t[i];
			fa[i]=lca(s[i],t[i]);
			if(s[i]==fa[i])
				c[i]=1;
			else if(t[i]==fa[i])
				c[i]=0;
			else 
				c[i]=2;	
		}
		int flag=0;
		for(int i=0;i<m&&!flag;i++)
			for(int j=i+1;j<m;j++){
				int ff=0;
				if(c[i]>c[j]){
					swap(i,j);
					ff=1;
				}
				if(c[i]==0&&c[j]==0){
					int k,kk;
					if(d[t[i]]>d[t[j]]){
						k=j;
						kk=i;
					}
					else{
						k=i;
						kk=j;
					}
					if(lca(t[k],t[kk])!=t[k]){
						if(ff)
							swap(i,j);
						continue;
					}
					if(lca(s[k],s[kk])!=s[kk]){
						if(ff)
							swap(i,j);
						continue;
					}
				}
				else if(c[i]==0&&c[j]==1){
					if(!(qu(s[i],s[j]))){
						if(ff)
							swap(i,j);
						continue; 
					} 
				}
				else if (c[i]==0&&c[j]==2){
					if((!(qu(s[i],s[j])&&lca(t[i],fa[j])==fa[j]))&&(!(qu(s[i],t[j])&&lca(fa[j],t[i])==fa[j]))){
						if(ff)
							swap(i,j);
						continue;
					}
				}
				else if(c[i]==1&&c[j]==1){
					int k,kk;
					if(d[s[i]]>d[s[j]]){
						k=j;
						kk=i;
					}
					else{
						k=i;
						kk=j;
					}
					if(lca(s[k],s[kk])!=s[k]){
						if(ff)
							swap(i,j);
						continue;
					}
					if(lca(t[k],t[kk])!=t[kk]){
						if(ff)
							swap(i,j);
						continue;
					}
				}
				else if(c[i]==1&&c[j]==2){
					if((!(lca(t[i],t[j])==t[i]&&qu(s[i],fa[j])==fa[j]))&&(!(qu(t[i],s[j])&&lca(fa[j],s[i])==fa[j]))){
						if(ff)
							swap(i,j);
						continue;
					}
				}
				else{
					if((!(qu(t[j],s[i])&&qu(t[i],s[j])))){
						if(ff)
							swap(i,j);
						continue;
					}
				}
				cout<<"No"<<endl;
				flag=1;
				break;
			}		
		if(!flag)
			cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++)
			e[i].clear(); 
	}
	return 0;
}

