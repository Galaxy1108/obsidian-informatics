#include <bits/stdc++.h>
using namespace std;
/*FeiAn
#define Ny 300
#define By 30
#define Np (Ny+1)
#define Bp (By+1)
#define Cp (Ny/By+1)
int n,q;
int a[Np][Np];
long long inb[Cp][Cp][Bp][Bp][Bp][Bp],otb[Np<<1][Np<<1];
*/
#define N 305
#define Q 200005
#define lINF 0x3f3f3f3f3f3f3f3fll
int n,q,a[N][N];
long long dis[N][N],ans[Q];
vector<tuple<int,int,int>>qs[N][N];
int main(){
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int sx,sy,ex,ey;
	for(int i=1;i<=q;i++){
		cin>>sx>>ex>>sy>>ey;
		qs[sx][sy].emplace_back(ex,ey,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(qs[i][j].empty())continue;
			for(int x=i;x<=n;x++){
				for(int y=j;y<=n;y++){
					dis[x][y]=lINF;
				}
			}
			dis[i][j]=0;
			for(int x=i;x<=n;x++){
				for(int y=j;y<=n;y++){
					if(x>i)dis[x][y]=min(dis[x][y],dis[x-1][y]);
					if(y>j)dis[x][y]=min(dis[x][y],dis[x][y-1]);
					dis[x][y]+=a[x][y];
				}
			}
			for(auto v:qs[i][j]){
				static int ex,ey,id;
				ex=get<0>(v),ey=get<1>(v),id=get<2>(v);
				ans[id]=dis[ex][ey];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}