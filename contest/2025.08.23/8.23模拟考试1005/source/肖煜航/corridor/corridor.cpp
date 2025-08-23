#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=50005;
set<int> q1[N],q2[N];
int cid,n,m,k;
namespace solve1{
	pair<int,int> a[150005];
	int f[N][21],g[N][21],op1[N][21],op2[N][21];//fÏòÓÒ gÏòÏÂ 
	pair<int,int> get(int x,int cnt,int op){
		op^=1;
		//0 right 1 down
		for(int i=19;i>=0;i--){
			if(cnt>=(1<<i)){
				cnt-=(1<<i);
				int oo=0;
				if(op==0){
					x=f[x][i];
					oo=op1[x][i];
				}
				else{
					x=g[x][i];
					oo=op2[x][i];
				}
				if(x<0){
					if(oo==1){
						return {-x,m+1};
					}
					else{
						return {n+1,-x};
					}
				}
				if(i==0) op^=1;
			}
		}
		return {a[x].first,a[x].second};
	}
	void solve(){
		for(int i=1;i<=k;i++) a[i].first=read(),a[i].second=read();
		sort(a+1,a+k+1);
		for(int i=1;i<=k;i++){
			q1[a[i].first].insert(i);
			q2[a[i].second].insert(i);
		}
		for(int i=k;i;i--){
			auto u=q1[a[i].first].upper_bound(i);
			if(u==q1[a[i].first].end()) f[i][0]=-a[i].first,op1[i][0]=1;
			else f[i][0]=*u;
			u=q2[a[i].second].upper_bound(i);
			if(u==q2[a[i].second].end()) g[i][0]=-a[i].second,op2[i][0]=2;
			else g[i][0]=*u;
			for(int j=1;j<20;j++){
				if(f[i][j-1]<0) f[i][j]=f[i][j-1],op1[i][j]=op1[i][j-1];
				else if(j==1) f[i][j]=g[f[i][j-1]][j-1],op1[i][j]=op2[f[i][j-1]][j-1];
				else f[i][j]=f[f[i][j-1]][j-1],op1[i][j]=op1[f[i][j-1]][j-1];
				if(g[i][j-1]<0) g[i][j]=g[i][j-1],op2[i][j]=op2[i][j-1];
				else if(j==1) g[i][j]=f[g[i][j-1]][j-1],op2[i][j]=op1[g[i][j-1]][j-1];
				else g[i][j]=g[g[i][j-1]][j-1],op2[i][j]=op2[g[i][j-1]][j-1];
			}
		}
		int Q=read();
		while(Q--){
			int op=read(),x=read(),y=read(),cnt=read();
			int id1=1,id2=1,re=0;
			if(x==0) id2=y,re=0;
			else id1=x,re=1;
			if(cnt==0){
				printf("%d %d\n",id1,id2);
				continue;
			}
			cnt--;
			int id=0;
			if(op==0){
				auto u=q2[id2].lower_bound(id1);
				if(u==q2[id2].end()){
					id1=n+1;
				}
				else{
					id=*u;
					id1=a[*u].first;
					re=1;
				}
			}
			else{
				auto u=q1[id1].lower_bound(id2);
				if(u==q1[id1].end()){
					id2=m+1;
				}
				else{
					id=*u;
					id2=a[*u].second;
					re=0;
				}
			}
			if(cnt==0||id1==n+1||id2==m+1){
				printf("%d %d\n",id1,id2);
				continue;
			}
			pair<int,int> ans=get(id,cnt,re);
			printf("%d %d\n",ans.first,ans.second);
		}
	}
}
int main(){
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	cid=read(),n=read(),m=read(),k=read();
//	if(cid==1){
//		solve1::solve();
//		return 0;
//	}
	for(int i=1;i<=k;i++){
		int x=read(),y=read();
		q1[x].insert(y);
		q2[y].insert(x);
	}
	int Q=read();
	while(Q--){
		int opt=read(),x=read(),y=read(),cnt;
		if(opt==1){
			q1[x].insert(y);
			q2[y].insert(x);
		}
		else{
			cnt=read();
			int id1=1,id2=1,op=0;
			if(x==0) id2=y,op=0;
			else id1=x,op=1;
			for(int t=1;t<=cnt;t++){
				if(op==0){
					auto u=q2[id2].upper_bound(id1);
					if(t==1) u=q2[id2].lower_bound(id1);
					if(u==q2[id2].end()){
						id1=n+1;
						break;
					}
					else{
						id1=*u;
						op=1;
					}
				}
				else{
					auto u=q1[id1].upper_bound(id2);
					if(t==1) u=q1[id1].lower_bound(id2);
					if(u==q1[id1].end()){
						id2=m+1;
						break;
					}
					else{
						id2=*u;
						op=0;
					}
				}
			}
			printf("%d %d\n",id1,id2);
		}
	}
	return 0;
}
/*
1 4 4 2
2 2
3 2
1 
2 2 0 3
*/
