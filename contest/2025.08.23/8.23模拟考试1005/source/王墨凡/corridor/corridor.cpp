#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
struct node{
	int x,y;
}no[1600086];
struct que{
	int w,x,y,q;
}qu[1600086];
int cntx,cnty,type,n,m,q,k,w,x,y,xx[1600086],yy[1600086],maxx,maxy;
bitset<50001> qwq[50001];
//bool qwq[20001][20001];
pair<int,int> dfs(int x,int y,int q,int s){
	if(x>=n+1 or y>=m+1){
		return {x,y};
	}
	if(qwq[x][y]){
		s=!s;
		q--;
		if(q==0)return {x,y};
	}
	if(s==1)dfs(x,y+1,q,s);
	else dfs(x+1,y,q,s);
}
int main(){
	ios::sync_with_stdio(0);
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	cin >> type >> n >> m >> k;
	for(int i=1;i<=k;i++){
		cin >> no[i].x >> no[i].y;
		qwq[no[i].x][no[i].y]=1;
	}
	cin >> q;
	for(int i=1;i<=q;i++){
		cin >> qu[i].w;
		if(qu[i].w==1){
			cin >> qu[i].x >> qu[i].y;
			qwq[qu[i].x][qu[i].y]=1;
		}
		if(qu[i].w==2){
			cin >> qu[i].x >> qu[i].y >> qu[i].q;
			pair<int,int> end;
			if(qu[i].x==0)end=dfs(qu[i].x,qu[i].y,qu[i].q,0);
			else  end=dfs(qu[i].x,qu[i].y,qu[i].q,1);
			cout << end.first << ' ' << end.second<< endl;
		}
	}
	return 0; 
}
