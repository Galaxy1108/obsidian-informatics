#include<bits/stdc++.h>
using namespace std;
int n,m,t,k;
int a[1005][1005],e[1005][1005],flag,d[1005];
int q[1005],ta;
int ff(int x,int fl,int t){
	if(x==t){
		flag=1;
		return fl;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==d[x]+1&&e[x][i]){
			int flow=ff(i,min(fl,e[x][i]),t);
			if(flag){
				e[x][i]-=flow;
				e[i][x]+=flow;
				return flow;
			}
		}
	}
	return 0;
}
int fffff(int x,int fl,int t){
	ta++;
	q[ta]=x;
	if(x==t){
		flag=1;
		return fl;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==d[x]+1&&e[x][i]){
			int flow=fffff(i,min(fl,e[x][i]),t);
			if(flag){
				e[x][i]-=flow;
				e[i][x]+=flow;
				return flow;
			}
		}
	}
	ta--;
	return 0;
}
void dfs(int x){
	for(int i=1;i<=n;i++)
		if(e[x][i]&&!d[i]){
			d[i]=d[x]+1;
			dfs(i);
		}
}
int dinnic(int s,int t){
	int f=0;
	do{
		flag=0;
		memset(d,0,sizeof d);
		d[s]=1;
		dfs(s);
		int flow=ff(s,0x3f3f3f3f,t);
		if(flag)
			f+=flow;
	}while(flag);
	return f;
}
void check(int s,int t){
	int f=k;
	do{
		flag=0;
		memset(d,0,sizeof d);
		d[s]=1;
		dfs(s);
		ta=0;
		int flow=fffff(s,0x3f3f3f3f,t);
		if(flag)
			for(int i=0;i<flow&&i<f;i++,cout<<endl){
				cout<<ta<<" ";
				for(int j=1;j<=ta;j++)
					cout<<q[j]<<" ";
			}
		f-=flow;
	}while(flag);
}
int main(){	
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		k=m/(n-1);
		if(m%(n-1))
			k++;
		memset(a,0,sizeof a);
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			if(x>y)
				a[y][x]++;
			else
				a[x][y]++;
		}
		int fff=0;
		for(int i=1;i<=n&&!fff;i++)
			for(int j=i+1;j<=n;j++){
				for(int ii=1;ii<=n;ii++)
					for(int jj=ii+1;jj<=n;jj++)
						e[ii][jj]=a[ii][jj];
				int ans=dinnic(i,j);
				if(ans>=k){
					for(int ii=1;ii<=n;ii++)
						for(int jj=ii+1;jj<=n;jj++)
							e[ii][jj]=a[ii][jj];
					cout<<i<<" "<<j<<endl;
					fff=1;
					check(i,j);
					break;
				}
			}
		if(!fff)
			cout<<-1<<endl;
	}
	return 0;
}

