#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 105
#define V 15
bool stt;
int n,f[N][V][V][V],ca[N],cb[N],cc[N];
char a[N];
bool edd;
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ca[i]=ca[i-1]+(a[i]=='A');
		cb[i]=cb[i-1]+(a[i]=='B');
		cc[i]=cc[i-1]+(a[i]=='C');
	}
	memset(f,0x3f,sizeof(f));
	int to;
	to=min(10,n);
	f[to][ca[to]][cb[to]][cc[to]]=0;
	for(int i=min(10,n);i<=n;i++){
		for(int x=10;x>=0;x--){
			for(int y=10;y>=0;y--){
				for(int z=10;z>=0;z--){
					if(f[i][x][y][z]==INF)continue;
					if(x+ca[to]-ca[i]<=10&&y+cb[to]-cb[i]<=10){
						to=min(i+z,n);
						f[to][x+ca[to]-ca[i]][y+cb[to]-cb[i]][0+cc[to]-cc[i]]=min(f[to][x+ca[to]-ca[i]][y+cb[to]-cb[i]][0+cc[to]-cc[i]],f[i][x][y][z]+1);
					}
					if(x+ca[to]-ca[i]<=10&&z+cc[to]-cc[i]<=10){
						to=min(i+y,n);
						f[to][x+ca[to]-ca[i]][0+cb[to]-cb[i]][z+cc[to]-cc[i]]=min(f[to][x+ca[to]-ca[i]][0+cb[to]-cb[i]][z+cc[to]-cc[i]],f[i][x][y][z]+1);
					}
					if(y+cb[to]-cb[i]<=10&&z+cc[to]-cc[i]<=10){
						to=min(i+x,n);
						f[to][0+ca[to]-ca[i]][y+cb[to]-cb[i]][z+cc[to]-cc[i]]=min(f[to][0+ca[to]-ca[i]][y+cb[to]-cb[i]][z+cc[to]-cc[i]],f[i][x][y][z]+1);	
					}				
				}
			}
		}
	}
	cout<<f[n][0][0][0];
	return 0;
}
