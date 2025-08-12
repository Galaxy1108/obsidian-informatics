#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int mp[N][N];
int sum[N][N];
inline int get(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int ans[N][N],tot;
bool vis[N*N],chk[N][N];
void check(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!ans[i][j]||chk[i][j]) continue;
			int res=ans[i][j];
			bool flag=0;
			if(vis[res]) flag=1,tot++;
			vis[res]=1;
			int x=i,y=j;
			while(ans[x][y]==res) x++;
			x--;
			while(ans[x][y]==res) y++;
			y--;
			for(int k=i;k<=x;k++){
				for(int t=j;t<=y;t++){
					chk[k][t]=1;
					if(flag) ans[k][t]=tot;
				}
			}
		}
	}
}
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='C') mp[i][j]=1;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!mp[i][j]) continue;
			if(ans[i][j]) continue;
			int z;
			for(z=j;z<=m+1;z++){
				if(!mp[i][z]){
					z--;
					break;
				}
			}
			int h;
			for(h=i;h<=n+1;h++){
				if(get(i,j,h,z)!=(z-j+1)*(h-i+1)){
					h--;
					break;
				}
			}
			bool flag=0;
			for(int k=i;k<=h;k++){
				for(int t=j;t<=z;t++){
					if(!ans[k][t]){
						flag=1;
						break;
					}
				}
			}
			if(!flag) continue;
			tot++;
			for(int k=i;k<=h;k++){
				for(int t=j;t<=z;t++){
					ans[k][t]=tot;
				}
			}
		} 
	}
	check();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
//	cout<<tot<<'\n';
	return 0;
}

